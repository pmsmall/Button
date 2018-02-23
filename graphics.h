/*
 * graphics.h
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "rgba.h"

void drawRectangle(rgba *p, int x, int y, int width, int height, int rgb);
void drawRectangleWithRgba(rgba *p, int x, int y, int width, int height,
		rgba *color);
void fillRectangle(rgba *p, int x, int y, int width, int height, int rgb);
void fillRectangleWithRgba(rgba *p, int x, int y, int width, int height,
		rgba *color);
#endif /* GRAPHICS_H_ */
