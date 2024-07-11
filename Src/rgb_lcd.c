#include "rgb_lcd.h"

void lcd_init(RGB_LCD *lcd, I2C_HandleTypeDef *hi2c, uint8_t cols, uint8_t rows, uint8_t charsize) {
    lcd->hi2c = hi2c;
    lcd->numlines = rows;
    lcd->currline = 0;

    lcd->displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
    if (rows > 1) {
        lcd->displayfunction |= LCD_2LINE;
    }

    // Initialize the I2C peripheral
    HAL_I2C_Init(hi2c);

    // Initialization sequence
    HAL_Delay(50);
    lcd_command(lcd, LCD_FUNCTIONSET | lcd->displayfunction);
    HAL_Delay(5);
    lcd_command(lcd, LCD_FUNCTIONSET | lcd->displayfunction);
    HAL_Delay(1);
    lcd_command(lcd, LCD_FUNCTIONSET | lcd->displayfunction);

    // Turn on the display with no cursor or blinking default
    lcd->displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    lcd_display(lcd);

    // Clear the display
    lcd_clear(lcd);

    // Initialize to default text direction (left-to-right)
    lcd->displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
    lcd_command(lcd, LCD_ENTRYMODESET | lcd->displaymode);
}

void lcd_command(RGB_LCD *lcd, uint8_t value) {
    uint8_t data[2] = {0x80, value};
    HAL_I2C_Master_Transmit(lcd->hi2c, LCD_ADDRESS << 1, data, 2, HAL_MAX_DELAY);
}

void lcd_write(RGB_LCD *lcd, uint8_t value) {
    uint8_t data[2] = {0x40, value};
    HAL_I2C_Master_Transmit(lcd->hi2c, LCD_ADDRESS << 1, data, 2, HAL_MAX_DELAY);
}

void lcd_clear(RGB_LCD *lcd) {
    lcd_command(lcd, LCD_CLEARDISPLAY);
    HAL_Delay(2);
}

void lcd_home(RGB_LCD *lcd) {
    lcd_command(lcd, LCD_RETURNHOME);
    HAL_Delay(2);
}

void lcd_set_cursor(RGB_LCD *lcd, uint8_t col, uint8_t row) {
    uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    if (row > lcd->numlines) {
        row = lcd->numlines - 1;
    }
    lcd_command(lcd, LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

void lcd_display(RGB_LCD *lcd) {
    lcd->displaycontrol |= LCD_DISPLAYON;
    lcd_command(lcd, LCD_DISPLAYCONTROL | lcd->displaycontrol);
}

void lcd_no_display(RGB_LCD *lcd) {
    lcd->displaycontrol &= ~LCD_DISPLAYON;
    lcd_command(lcd, LCD_DISPLAYCONTROL | lcd->displaycontrol);
}

void lcd_blink(RGB_LCD *lcd) {
    lcd->displaycontrol |= LCD_BLINKON;
    lcd_command(lcd, LCD_DISPLAYCONTROL | lcd->displaycontrol);
}

void lcd_no_blink(RGB_LCD *lcd) {
    lcd->displaycontrol &= ~LCD_BLINKON;
    lcd_command(lcd, LCD_DISPLAYCONTROL | lcd->displaycontrol);
}

void lcd_cursor(RGB_LCD *lcd) {
    lcd->displaycontrol |= LCD_CURSORON;
    lcd_command(lcd, LCD_DISPLAYCONTROL | lcd->displaycontrol);
}

void lcd_no_cursor(RGB_LCD *lcd) {
    lcd->displaycontrol &= ~LCD_CURSORON;
    lcd_command(lcd, LCD_DISPLAYCONTROL | lcd->displaycontrol);
}

void lcd_scroll_display_left(RGB_LCD *lcd) {
    lcd_command(lcd, LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}

void lcd_scroll_display_right(RGB_LCD *lcd) {
    lcd_command(lcd, LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

void lcd_left_to_right(RGB_LCD *lcd) {
    lcd->displaymode |= LCD_ENTRYLEFT;
    lcd_command(lcd, LCD_ENTRYMODESET | lcd->displaymode);
}

void lcd_right_to_left(RGB_LCD *lcd) {
    lcd->displaymode &= ~LCD_ENTRYLEFT;
    lcd_command(lcd, LCD_ENTRYMODESET | lcd->displaymode);
}

void lcd_autoscroll(RGB_LCD *lcd) {
    lcd->displaymode |= LCD_ENTRYSHIFTINCREMENT;
    lcd_command(lcd, LCD_ENTRYMODESET | lcd->displaymode);
}

void lcd_no_autoscroll(RGB_LCD *lcd) {
    lcd->displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
    lcd_command(lcd, LCD_ENTRYMODESET | lcd->displaymode);
}

void lcd_create_char(RGB_LCD *lcd, uint8_t location, uint8_t charmap[]) {
    location &= 0x7; // we only have 8 locations 0-7
    lcd_command(lcd, LCD_SETCGRAMADDR | (location << 3));
    for (int i = 0; i < 8; i++) {
        lcd_write(lcd, charmap[i]);
    }
}
