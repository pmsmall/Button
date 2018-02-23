/*
 * button.h
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "rgba.h"
#include "input/InputEvent.h"
#include "input/ActionEvent.h"
#include "enviroment.h"

typedef struct _button {
	int x;
	int y;
	int width;
	int height;
	rgba *color;
	rgba release_color;
	rgba hover_color;
	rgba press_color;
	unsigned char state;
	void (*actionListener)(ActionEvent *e);
} button;

#define BUTTON_STATE_RELEASED 0
#define BUTTON_STATE_HOVERED 1
#define BUTTON_STATE_PRESSED 2

#define BUTTON_DEFAULT_RELEASED_COLOR (GRAY)
#define BUTTON_DEFAULT_HOVERED_COLOR (LIGHT_GRAY)
#define BUTTON_DEFAULT_PRESSED_COLOR (DARK_GRAY)

button* createButton(int x, int y, int width, int height, rgba release_color,
		rgba hover_color, rgba press_color);
button* createDefaultButton(int x, int y, int width, int height);

void drawButton(rgba *p, button *b);
void setButtonColorRGBA(button *b, int rgb, int alpha);
void setButtonColorRGB(button *b, int rgb);
void setButtonAlpha(button *b, int alpha);
void setActionListener(button *b, void (*actionListener)(ActionEvent *e));
void pressButton(button *b, InputEnent *e);
void hoverButton(button *b, InputEnent *e);
void releaseButton(button *b, InputEnent *e);
void exitButton(button *b, InputEnent *e);
bool inButton(button *b, int x, int y);

#endif /* BUTTON_H_ */
