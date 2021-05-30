#include "drawing_SSD1306.h"


const uint8_t bmp_heart_16x16[]= {0x0, 0x0, 0x3C, 0x3C, 0x7E, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
									0xFF, 0xFF, 0x7F, 0xFE, 0x3F, 0xFC, 0x1F, 0xF8, 0x0F, 0xF0, 0x07, 0xE0, 0x03, 0xC0, 0x0, 0x0};

const uint8_t bmp_cancel_16x16[]= {0b00000111, 0b11100000,
									0b00001111, 0b11110000,
									0b00111111, 0b11111100,
									0b00111100, 0b00111100,
									0b01110000, 0b00111110,
									0b11110000, 0b01111110,
									0b11100000, 0b11100111,
									0b11100001, 0b11000111,
									0b11100011, 0b10000111,
									0b11100111, 0b00000111,
									0b11111110, 0b00001110,
									0b01111100, 0b00001110,
									0b00111100, 0b00111100,
									0b00111111, 0b11111100,
									0b00001111, 0b11110000,
									0b00000011, 0b11000000};

const uint8_t bmp_sandclk_16x16[]= {0b01111111, 0b11111100,
									0b01111111, 0b11111100,
									0b01000000, 0b00000100,
									0b01000010, 0b10000100,
									0b00100101, 0b01001000,
									0b00011010, 0b10110000,
									0b00001101, 0b01100000,
									0b00000010, 0b10000000,
									0b00000011, 0b10000000,
									0b00001100, 0b01100000,
									0b00010001, 0b00010000,
									0b00100010, 0b10001000,
									0b00100101, 0b01001000,
									0b01001010, 0b10100100,
									0b01111111, 0b11111100,
									0b01111111, 0b11111100};

const uint8_t bmp_chat_16x16[]= {0x07, 0xE0, 0x18, 0x18, 0x20, 0x04, 0x40, 0x02, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
								0x40, 0x02, 0x20, 0x04, 0x10, 0x18, 0x10, 0xE0, 0x23, 0x00, 0x2C, 0x00, 0x70, 0x00, 0x40, 0x00};


const uint8_t bmp_star_16x16[]= {0x01, 0x00, 0x01, 0x80, 0x1, 0x80, 0x1, 0x80, 0x3, 0xC0, 0x3, 0xC0, 0xFF, 0xFF, 0x7F, 0xFE,
									0x1F, 0xF8, 0xF, 0xF0, 0xF, 0xF0, 0xF, 0xF0, 0xF, 0xF0, 0x1E, 0x78, 0x18, 0x18, 0x10, 0x08};

const unsigned char bmp_power_16x16[] = {0x00, 0x0C, 0x00, 0x34, 0x00, 0xC2, 0x03, 0x01, 0x0C, 0x00, 0x30, 0x00, 0x40, 0x00, 0x30, 0x00,
										0x0C, 0x00, 0x03, 0x00, 0x00, 0x80, 0x00, 0x60, 0x00, 0x10, 0x00, 0x20, 0x00, 0xC0, 0x00, 0x20};

const unsigned char bmp_logo_128_64 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFC, 0x00, 0x00,
0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFE, 0x00, 0x00,
0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0x80, 0x00,
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xC0, 0x00,
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xE0, 0x00,
0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xE0, 0x00,
0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xF0, 0x00,
0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00,
0x00, 0x0F, 0xFF, 0xF0, 0x0F, 0xFF, 0xC0, 0x00, 0x00, 0x01, 0xFF, 0xFE, 0x01, 0xFF, 0xF8, 0x00,
0x00, 0x0F, 0xFF, 0xE0, 0x07, 0xFF, 0xC0, 0x00, 0x00, 0x01, 0xFF, 0xFC, 0x00, 0xFF, 0xF8, 0x00,
0x00, 0x0F, 0xFF, 0xC0, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x01, 0xFF, 0xF8, 0x00, 0xFF, 0xFC, 0x00,
0x00, 0x1F, 0xFF, 0x80, 0x03, 0xFF, 0xE0, 0x00, 0x00, 0x03, 0xFF, 0xF0, 0x00, 0x7F, 0xFC, 0x00,
0x00, 0x1F, 0xFF, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x7F, 0xFC, 0x00,
0x00, 0x1F, 0xFF, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x7F, 0xFC, 0x00,
0x00, 0x1F, 0xFF, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x7F, 0xFC, 0x00,
0x00, 0x1F, 0xFF, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x7F, 0xFC, 0x00,
0x00, 0x1F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x1F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0F, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0F, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0F, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00,
0x00, 0x07, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00,
0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xF8, 0x00, 0x00, 0x00,
0x00, 0x03, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x01, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x3C, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xF0, 0x00, 0x00,
0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xC0, 0x01, 0xFF, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xF8, 0x00, 0x00,
0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xE0, 0x03, 0xFF, 0x80, 0x00, 0x03, 0xFF, 0xFF, 0xFC, 0x00, 0x00,
0x00, 0x00, 0x07, 0xFF, 0xFF, 0xF0, 0x07, 0xFF, 0xC0, 0x00, 0x00, 0xFF, 0xFF, 0xFE, 0x00, 0x00,
0x00, 0x00, 0x01, 0xFF, 0xFF, 0xF0, 0x07, 0xFF, 0xC0, 0x00, 0x00, 0x3F, 0xFF, 0xFE, 0x00, 0x00,
0x00, 0x00, 0x00, 0x3F, 0xFF, 0xF8, 0x0F, 0xEF, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFC, 0x0F, 0xC7, 0xE0, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0x80, 0x00,
0x00, 0x00, 0x00, 0x07, 0xFF, 0xFC, 0x0F, 0x87, 0xE0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x80, 0x00,
0x00, 0x00, 0x00, 0x01, 0xFF, 0xFE, 0x1F, 0x87, 0xC0, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xC0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x7F, 0xFE, 0x1F, 0x8F, 0xC0, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xC0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x3F, 0xFE, 0x0F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xC0, 0x00,
0x07, 0xFF, 0x80, 0x00, 0x3F, 0xFE, 0x0F, 0xFF, 0x00, 0xFF, 0xF0, 0x00, 0x07, 0xFF, 0xC0, 0x00,
0x07, 0xFF, 0xC0, 0x00, 0x1F, 0xFE, 0x07, 0xFE, 0x00, 0xFF, 0xF8, 0x00, 0x03, 0xFF, 0xC0, 0x00,
0x07, 0xFF, 0xC0, 0x00, 0x1F, 0xFE, 0x07, 0xF8, 0x00, 0xFF, 0xF8, 0x00, 0x03, 0xFF, 0xC0, 0x00,
0x07, 0xFF, 0xC0, 0x00, 0x3F, 0xFE, 0x0F, 0xF0, 0x00, 0xFF, 0xF8, 0x00, 0x07, 0xFF, 0xC0, 0x00,
0x07, 0xFF, 0xC0, 0x00, 0x3F, 0xFE, 0x3F, 0xF0, 0x7C, 0xFF, 0xF8, 0x00, 0x07, 0xFF, 0xC0, 0x00,
0x07, 0xFF, 0xE0, 0x00, 0x7F, 0xFE, 0x7F, 0xF8, 0x7C, 0xFF, 0xFC, 0x00, 0x0F, 0xFF, 0xC0, 0x00,
0x03, 0xFF, 0xE0, 0x00, 0x7F, 0xFE, 0xFF, 0xF8, 0x78, 0x7F, 0xFC, 0x00, 0x0F, 0xFF, 0xC0, 0x00,
0x03, 0xFF, 0xF0, 0x01, 0xFF, 0xFC, 0xFE, 0xFC, 0xF8, 0x7F, 0xFE, 0x00, 0x3F, 0xFF, 0x80, 0x00,
0x03, 0xFF, 0xFC, 0x07, 0xFF, 0xFC, 0xFC, 0x7F, 0xF8, 0x7F, 0xFF, 0x80, 0xFF, 0xFF, 0x80, 0x00,
0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xF8, 0x3F, 0xF8, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF8, 0x1F, 0xF0, 0x1F, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00,
0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xE0, 0xFC, 0x1F, 0xF0, 0x0F, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00,
0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xC0, 0xFE, 0x7F, 0xE0, 0x07, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00,
0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0x80, 0xFF, 0xFF, 0xE0, 0x03, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00,
0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xF0, 0x01, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00,
0x00, 0x03, 0xFF, 0xFF, 0xFC, 0x00, 0x7F, 0xFF, 0xF0, 0x00, 0x7F, 0xFF, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x01, 0xFF, 0xFF, 0xF8, 0x00, 0x3F, 0xFF, 0xF8, 0x00, 0x3F, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x7F, 0xFF, 0xE0, 0x00, 0x0F, 0xE1, 0xF8, 0x00, 0x0F, 0xFF, 0xFC, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char bmp_bpmfx_128_64 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x7F, 0x00, 0x3C, 0x01, 0xF0, 0x0F, 0x80, 0x0F, 0xE0, 0x7F, 0xE7, 0xE0, 0x03, 0xC0, 0xF0,
0x00, 0xFF, 0xC0, 0x3C, 0x07, 0xF8, 0x3F, 0xC0, 0x1F, 0xF8, 0x7F, 0xE7, 0xF8, 0x03, 0xC0, 0xF0,
0x00, 0xFF, 0xC0, 0x7C, 0x0F, 0xFC, 0x7F, 0xE0, 0x1F, 0xFC, 0x7F, 0xC7, 0xFC, 0x07, 0xC0, 0xE0,
0x00, 0xE1, 0xE0, 0x7C, 0x0E, 0x1E, 0x70, 0xF0, 0x1C, 0x1C, 0x70, 0x0F, 0x1C, 0x07, 0xC0, 0xE0,
0x00, 0xE1, 0xE0, 0xFC, 0x0E, 0x00, 0x70, 0x00, 0x1C, 0x1C, 0xF0, 0x0F, 0x0E, 0x0F, 0xC0, 0xE0,
0x00, 0xE1, 0xC1, 0xCC, 0x0F, 0x00, 0x78, 0x00, 0x1C, 0x1C, 0xF0, 0x0E, 0x0E, 0x1C, 0xC0, 0xE0,
0x00, 0xFF, 0x81, 0xCE, 0x07, 0xC0, 0x3E, 0x00, 0x1C, 0x3C, 0xFF, 0x8E, 0x0E, 0x1C, 0xE1, 0xE0,
0x01, 0xFF, 0x83, 0x8E, 0x03, 0xF0, 0x1F, 0x80, 0x3F, 0xF8, 0xFF, 0x8E, 0x0E, 0x38, 0xE1, 0xE0,
0x01, 0xE3, 0xC3, 0x8E, 0x00, 0xF8, 0x07, 0xC0, 0x3F, 0xF0, 0xF0, 0x0E, 0x1E, 0x38, 0xE1, 0xC0,
0x01, 0xC1, 0xC7, 0xFE, 0x00, 0x38, 0x01, 0xC0, 0x3F, 0xC0, 0xE0, 0x1E, 0x1C, 0x7F, 0xE1, 0xC0,
0x01, 0xC1, 0xC7, 0xFE, 0x3C, 0x39, 0xE1, 0xC0, 0x38, 0x01, 0xE0, 0x1E, 0x1C, 0x7F, 0xE1, 0xC0,
0x01, 0xC3, 0xCF, 0xFF, 0x1C, 0x38, 0xE1, 0xC0, 0x38, 0x01, 0xE0, 0x1C, 0x38, 0xFF, 0xF1, 0xC0,
0x01, 0xFF, 0x8E, 0x0F, 0x1F, 0xF8, 0xFF, 0xC0, 0x38, 0x01, 0xFF, 0x9F, 0xF8, 0xE0, 0xF3, 0xFF,
0x03, 0xFF, 0x1E, 0x07, 0x0F, 0xF0, 0x7F, 0x80, 0x78, 0x01, 0xFF, 0x9F, 0xF1, 0xE0, 0x73, 0xFF,
0x03, 0xFE, 0x1C, 0x07, 0x07, 0xC0, 0x3E, 0x00, 0x70, 0x01, 0xFF, 0x1F, 0xC1, 0xC0, 0x73, 0xFE,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
0x00, 0x0F, 0x01, 0xE3, 0x83, 0x8E, 0x0F, 0xFF, 0x3C, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
0x00, 0x1F, 0x03, 0xE3, 0x83, 0x9E, 0x0F, 0xFF, 0x38, 0x3F, 0xF8, 0x00, 0x08, 0x1F, 0xC0, 0xF0,
0x00, 0x1F, 0x03, 0xE3, 0x83, 0x9E, 0x0F, 0xFF, 0x38, 0x3F, 0xF8, 0x00, 0x18, 0x1F, 0x81, 0xF0,
0x00, 0x1F, 0x87, 0xE7, 0x87, 0x9C, 0x00, 0xE0, 0x38, 0x3F, 0xF0, 0x00, 0x38, 0x3E, 0x07, 0xF0,
0x00, 0x1F, 0x87, 0xC7, 0x87, 0x1C, 0x00, 0xE0, 0x38, 0x3F, 0xE0, 0x00, 0x38, 0x1E, 0x07, 0xF0,
0x00, 0x1F, 0x8F, 0xC7, 0x07, 0x1C, 0x00, 0xE0, 0x38, 0x3F, 0xE0, 0xFF, 0xFC, 0x1C, 0x0F, 0xF0,
0x00, 0x1D, 0x8D, 0xC7, 0x07, 0x1C, 0x01, 0xE0, 0x78, 0x3F, 0xE0, 0xFF, 0xFC, 0x1C, 0x1F, 0xF0,
0x00, 0x3D, 0x9D, 0xC7, 0x07, 0x3C, 0x01, 0xE0, 0x70, 0x3F, 0xE0, 0xFF, 0xFC, 0x08, 0x3F, 0xF0,
0x00, 0x39, 0x99, 0xC7, 0x07, 0x3C, 0x01, 0xC0, 0x70, 0x3F, 0xE0, 0xFF, 0xFE, 0x00, 0x3F, 0xF0,
0x00, 0x39, 0xBB, 0xCF, 0x0F, 0x38, 0x01, 0xC0, 0x70, 0x3F, 0xC1, 0xFF, 0xFC, 0x00, 0xFF, 0xF0,
0x00, 0x39, 0xF3, 0x8F, 0x0E, 0x38, 0x01, 0xC0, 0x70, 0x3F, 0x81, 0xFF, 0xFE, 0x01, 0xFF, 0xF0,
0x00, 0x39, 0xF3, 0x8F, 0x0E, 0x38, 0x01, 0xC0, 0xF0, 0x3F, 0x80, 0x01, 0xFE, 0x01, 0xFF, 0xF0,
0x00, 0x39, 0xE3, 0x87, 0xFC, 0x3F, 0xE3, 0xC0, 0xF0, 0x3F, 0x80, 0x01, 0xFE, 0x03, 0xFF, 0xF0,
0x00, 0x78, 0xE3, 0x83, 0xFC, 0x7F, 0xE3, 0xC0, 0xE0, 0x3F, 0x80, 0x01, 0xFC, 0x03, 0xFF, 0xF0,
0x00, 0x78, 0xC7, 0x81, 0xF0, 0x7F, 0xE3, 0x80, 0xE0, 0x3F, 0x00, 0x03, 0xF8, 0x03, 0xFF, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x07, 0xFF, 0xF0, 0x03, 0xFF, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x07, 0xFF, 0xE0, 0x03, 0xFF, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x0F, 0xFF, 0xE0, 0xC1, 0xFF, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x0F, 0xFF, 0xC1, 0xC1, 0xFF, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x0F, 0xFF, 0x81, 0xC0, 0xFF, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x1F, 0xFE, 0x07, 0xC1, 0xFF, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x1F, 0xFE, 0x07, 0xC1, 0xFF, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x1F, 0xFC, 0x0F, 0xC0, 0xFF, 0xF0
};


void SSD1306_DrawPicture_custom(uint8_t x0, uint8_t y0, uint8_t w, uint8_t h, uint8_t picture[]){
	
	uint8_t lineSizeof = w / 8;
	uint16_t byteToPrint; //datos que corresponden para imprimir.
	uint8_t pos_inline; //que posicion arranco el ultimo for.
	
	for (uint8_t pixel_y = y0; pixel_y < y0 + h; pixel_y++){
		for (uint8_t line_byte = 0; line_byte < lineSizeof; line_byte++){
			byteToPrint = line_byte+(pixel_y-y0)*lineSizeof;
			pos_inline = x0+(line_byte*8);
			for (uint8_t pixel_x = 0; pixel_x <= 7; pixel_x++){
				SSD1306_DrawPixel(pos_inline+pixel_x, pixel_y, (picture[byteToPrint] >> (7-pixel_x)) & 0b1 );
			}
		}
	}
}

void SSD1306_DrawPicture_16x16(uint8_t x0, uint8_t y0, uint8_t picture[]){
  SSD1306_DrawPicture_custom(x0,y0,16,16,picture);
}
