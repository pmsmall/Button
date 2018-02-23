/*
 * graphics.c
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#include "graphics.h"
#include "enviroment.h"

void drawRectangle(rgba *p, int x, int y, int width, int height, int rgb) {
	for (int i = x; i < x + width; i++) {
		setRgb(p + y * screen_width + i, rgb);
		setRgb(p + (y + height - 1) * screen_width + i, rgb);
	}
	for (int j = y + 1; j < y + height - 1; j++) {
		setRgb(p + j * screen_width + x, rgb);
		setRgb(p + j * screen_width + x + width - 1, rgb);
	}
}

void drawRectangleWithRgba(rgba *p, int x, int y, int width, int height,
		rgba *color) {
	for (int i = x; i < x + width; i++) {
		drawRgba(p + y * screen_width + i, color);
		drawRgba(p + (y + height - 1) * screen_width + i, color);
	}
	for (int j = y + 1; j < y + height - 1; j++) {
		drawRgba(p + j * screen_width + x, color);
		drawRgba(p + j * screen_width + x + width - 1, color);
	}
}

void fillRectangle(rgba *p, int x, int y, int width, int height, int rgb) {
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			setRgb(p + j * screen_width + i, rgb);
		}
	}
}

void fillRectangleWithRgba(rgba *p, int x, int y, int width, int height,
		rgba *color) {
	for (int i = x; i < x + width; i++) {
		for (int j = y; j < y + height; j++) {
			drawRgba(p + j * screen_width + i, color);
		}
	}
}
