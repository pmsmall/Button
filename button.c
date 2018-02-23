/*
 * button.c
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#include "button.h"
#include "graphics.h"

void drawButton(rgba *p, button *b) {
	fillRectangleWithRgba(p, b->x, b->y, b->width, b->height, (b->color));
}

void setButtonColorRGBA(button *b, int rgb, int alpha) {
	rgba* color = &(b->release_color);
	for (int i = 0; i < 3; i++) {
		setRgb(color + i, rgb);
		color[i].alpha = alpha;
	}
}

void setButtonColorRGB(button *b, int rgb) {
	rgba* color = &(b->release_color);
	for (int i = 0; i < 3; i++) {
		setRgb(color + i, rgb);
	}
}

void setButtonAlpha(button *b, int alpha) {
	rgba* color = &(b->release_color);
	for (int i = 0; i < 3; i++) {
		color[i].alpha = alpha;
	}
}

void setActionListener(button *b, void (*actionListener)(ActionEvent *e)) {
	b->actionListener = actionListener;
}
void defaultActionListener(ActionEvent *e) {

}

button* createButton(int x, int y, int width, int height, rgba release_color,
		rgba hover_color, rgba press_color) {
	button *b = (button *) malloc(sizeof(button));
	b->x = x;
	b->y = y;
	b->width = width;
	b->height = height;
	b->release_color = release_color;
	b->hover_color = hover_color;
	b->press_color = press_color;
	b->color = &(b->release_color);
	b->state = BUTTON_STATE_RELEASED;
	b->actionListener = defaultActionListener;
	return b;
}

button* createDefaultButton(int x, int y, int width, int height) {
	return createButton(x, y, width, height, BUTTON_DEFAULT_RELEASED_COLOR,
	BUTTON_DEFAULT_HOVERED_COLOR, BUTTON_DEFAULT_PRESSED_COLOR);
}

void pressButton(button *b, InputEnent *e) {
	b->state = (b->state & 0xf0) | BUTTON_STATE_PRESSED | (e->type << 4);
	b->color = &(b->press_color);
}

void hoverButton(button *b, InputEnent *e) {
	if (b->state == BUTTON_STATE_RELEASED) {
		b->state = BUTTON_STATE_HOVERED;
		b->color = &(b->hover_color);
	}
}

void releaseButton(button *b, InputEnent *e) {
	int type = (e->type << 4);
	int result = (b->state & 0xf0) & type;
	b->state &= ~type;
	if (((b->state) & 0xf) == BUTTON_STATE_PRESSED) {
		if (!((b->state) & 0xf0)) {
			b->state = BUTTON_STATE_RELEASED;
			b->color = &(b->release_color);
			e->src = (void *) b;
			b->actionListener((ActionEvent *) e);
		}
	}
}

void exitButton(button *b, InputEnent *e) {
	if (b->state == BUTTON_STATE_RELEASED)
		return;
	b->state = BUTTON_STATE_RELEASED;
	b->color = &(b->release_color);
}

bool inButton(button *b, int x, int y) {
	if (x < b->x)
		return false;
	if (y < b->y)
		return false;
	if (x > b->x + b->width)
		return false;
	if (y > b->y + b->height)
		return false;
	return true;
}

