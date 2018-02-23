/*
 * rgba.h
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#ifndef RGBA_H_
#define RGBA_H_

typedef struct _rgba {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
	unsigned char alpha;
} rgba;

extern rgba WHITE;
extern rgba BLACK;
extern rgba RED;
extern rgba GREEN;
extern rgba BLUE;
extern rgba LIGHT_GRAY;
extern rgba GRAY;
extern rgba DARK_GRAY;
extern rgba YELLOW;
extern rgba PURPLE;
extern rgba ORANGE;
extern rgba PINK;
extern rgba MAGENTA;
extern rgba CYAN;

void drawRgba(rgba *rgb_dst, rgba *rgb_src);

void setRgba(rgba *rgb, int red, int green, int blue);

void setRgb(rgba *p, int rgb);

void putPixel(rgba *p, int x, int y, int rgb);

int getRgbInt(int red, int green, int blue);

#endif /* RGBA_H_ */
