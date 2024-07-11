#ifndef RGB_LCD_H
#define RGB_LCD_H

#include "stm32l4xx_hal.h"

// I2C address of the LCD
#define LCD_ADDRESS (0x7C >> 1)

// LCD Command set
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// Flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// Flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// Flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// Flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

typedef struct {
    I2C_HandleTypeDef *hi2c; // I2C handle
    uint8_t displayfunction;
    uint8_t displaycontrol;
    uint8_t displaymode;
    uint8_t numlines;
    uint8_t currline;
} RGB_LCD;

void lcd_init(RGB_LCD *lcd, I2C_HandleTypeDef *hi2c, uint8_t cols, uint8_t rows, uint8_t charsize);
void lcd_clear(RGB_LCD *lcd);
void lcd_home(RGB_LCD *lcd);
void lcd_set_cursor(RGB_LCD *lcd, uint8_t col, uint8_t row);
void lcd_display(RGB_LCD *lcd);
void lcd_no_display(RGB_LCD *lcd);
void lcd_blink(RGB_LCD *lcd);
void lcd_no_blink(RGB_LCD *lcd);
void lcd_cursor(RGB_LCD *lcd);
void lcd_no_cursor(RGB_LCD *lcd);
void lcd_scroll_display_left(RGB_LCD *lcd);
void lcd_scroll_display_right(RGB_LCD *lcd);
void lcd_left_to_right(RGB_LCD *lcd);
void lcd_right_to_left(RGB_LCD *lcd);
void lcd_autoscroll(RGB_LCD *lcd);
void lcd_no_autoscroll(RGB_LCD *lcd);

void lcd_create_char(RGB_LCD *lcd, uint8_t location, uint8_t charmap[]);
void lcd_command(RGB_LCD *lcd, uint8_t value);
void lcd_write(RGB_LCD *lcd, uint8_t value);

#endif // RGB_LCD_H
