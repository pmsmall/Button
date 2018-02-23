/*
 * rgba.c
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#include "rgba.h"
#include "enviroment.h"

rgba WHITE = { 0xff, 0xff, 0xff, 0xff };
rgba BLACK = { 0, 0, 0, 0xff };
rgba RED = { 0, 0, 0xff, 0xff };
rgba GREEN = { 0, 0xff, 0, 0xff };
rgba BLUE = { 0xff, 0, 0, 0xff };
rgba LIGHT_GRAY = { 192, 192, 192, 0xff };
rgba GRAY = { 0x80, 0x80, 0x80, 0xff };
rgba DARK_GRAY = { 0x4b, 0x4b, 0x4b, 0xff };
rgba YELLOW = { 0, 0xff, 0xff, 0xff };
rgba PURPLE = { 0xff, 0, 0xff, 0xff };
rgba ORANGE = { 0, 0x66, 0xff, 0xff };
rgba PINK = { 175, 175, 255, 0xff };
rgba MAGENTA = { 0xff, 0, 0xff, 0xff };
rgba CYAN = { 0xff, 0xff, 0, 0xff };

void drawRgba(rgba *rgb_dst, rgba *rgb_src) {
	*(rgb_dst) = *(rgb_src);
}
void setRgba(rgba *rgb, int red, int green, int blue) {
	rgb->red = red;
	rgb->green = green;
	rgb->blue = blue;
}

void setRgb(rgba *p, int rgb) {
	p->red = (unsigned char) ((rgb >> 16) & 0xff);
	p->green = (unsigned char) ((rgb >> 8) & 0xff);
	p->blue = (unsigned char) (rgb & 0xff);
	p->alpha = (unsigned char) (0xff);
}

void putPixel(rgba *p, int x, int y, int rgb) {
	setRgb(p + y * screen_width + x, rgb);
}

int getRgbInt(int red, int green, int blue) {
	return (red << 16 | green << 8 | blue);
}
