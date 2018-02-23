/*
 * CURSOR.c
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#include "cursor.h"
#include "enviroment.h"

void drawCursor(rgba *p, rgba *buf, int x, int y) {
	int x0 = x - CURSOR_X_R < 0 ? 0 : x - CURSOR_X_R;
	int x1 =
			x + CURSOR_X_R > (screen_width - 1) ?
					(screen_width - 1) : x + CURSOR_X_R;
	int y0 = y - CURSOR_Y_R < 0 ? 0 : y - CURSOR_Y_R;
	int y1 =
			y + CURSOR_Y_R > (screen_height - 1) ?
					(screen_height - 1) : y + CURSOR_Y_R;
	for (int i = x0; i <= x1; i++) {
		for (int j = y0; j <= y1; j++) {
			drawRgba(p + j * screen_width + i, buf + j * screen_width + i);
		}
	}
}

void putCursor(rgba *p, int x, int y, int rgb) {
	int x0 = x - CURSOR_X_R < 0 ? 0 : x - CURSOR_X_R;
	int x1 =
			x + CURSOR_X_R > (screen_width - 1) ?
					(screen_width - 1) : x + CURSOR_X_R;
	int y0 = y - CURSOR_Y_R < 0 ? 0 : y - CURSOR_Y_R;
	int y1 =
			y + CURSOR_Y_R > (screen_height - 1) ?
					(screen_height - 1) : y + CURSOR_Y_R;
	for (int i = x0; i <= x1; i++) {
		for (int j = y0; j <= y1; j++) {
			putPixel(p, i, j, rgb);
		}
	}
}
