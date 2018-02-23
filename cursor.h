/*
 * CURSOR.h
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#ifndef CURSOR_H_
#define CURSOR_H_

#include "rgba.h"

typedef struct _cursor {
	int x;
	int y;
} cursor;

#define CURSOR_X_R 5
#define CURSOR_Y_R 5

void drawCursor(rgba *p, rgba *buf, int x, int y);

void putCursor(rgba *p, int x, int y, int rgb);

#endif /* CURSOR_H_ */
