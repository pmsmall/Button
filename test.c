#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fb.h>
#include <linux/input.h>
#include <sys/mman.h>
#include <stdlib.h>

#include "enviroment.h"

#include "rgba.h"
#include "button.h"
#include "cursor.h"
#include "graphics.h"

struct fb_var_screeninfo vinfo;

#define BACKGROUD 0x0
#define FOREGROUD 0xffffff

void myButtonActionListener(ActionEvent *e);
void end();

int fbfd, fbsize, fd_mouse;
rgba *fbbuf;

int main(int argc, char *argv[]) {
	int i;
	int x = 0, y = 0, x0 = 0, y0 = 0;
	rgba *buffered;
	button *myButton = createButton(500, 380, 80, 25, RED, PINK, GREEN);

	setActionListener(myButton, myButtonActionListener);

	struct input_event event_mouse;

	if ((fbfd = open("/dev/fb0", O_RDWR)) < 0) {
		printf("get screen error");
		exit(1);
	}

	if ((fd_mouse = open("/dev/input/event5", O_RDONLY)) <= 0) {
		printf("get mouse error");
		exit(1);
	}

	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
		printf("Bad vscreeninfo ioct1\n");
		exit(2);
	}

	printf("x:%d\ny:%d\n", vinfo.xres, vinfo.yres);
	//fbsize = vinfo.xres * vinfo.yres * (vinfo.bits_per_pixel / 8);
	printf("%d", vinfo.bits_per_pixel);
	fbsize = 1920 * 1080 * (vinfo.bits_per_pixel / 8);

	if ((fbbuf = mmap(0, fbsize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0))
			== (void *) -1) {
		exit(3);
	}

	i = 8;
	printf("fbsize:%d\n", ((i % 255) << 16) | ((i % 255) << 8) | ((i % 255)));
	buffered = (rgba*) malloc(fbsize);

	for (int i = 0; i < 1920; i++) {
		for (int j = 0; j < 1080; j++) {
			putPixel(fbbuf, i, j, BACKGROUD);
			putPixel(buffered, i, j, BACKGROUD);
		}
	}

	//fillRectangleWithRgba(fbbuf, 50, 100, 80, 25, &LIGHT_GRAY);
	//fillRectangleWithRgba(buffered, 50, 100, 80, 25, &LIGHT_GRAY);
#ifndef update_my_button
#define	update_my_button \
	drawButton(fbbuf, myButton);\
	drawButton(buffered, myButton);
#endif

	update_my_button

	for (;;) {
		int len = read(fd_mouse, &event_mouse, sizeof(event_mouse));
		if (len == sizeof(event_mouse)) {
			if (event_mouse.type == EV_KEY) {
				if (inButton(myButton, x, y)) {
					InputEnent *e = (InputEnent *) malloc(sizeof(InputEnent));
					e->type = 1 << (event_mouse.code & 0xf);
					e->value = event_mouse.value;
					if (event_mouse.value == 1) {
						pressButton(myButton, e);
						update_my_button
						putCursor(fbbuf, x, y, FOREGROUD);
					} else {
						releaseButton(myButton, e);
						update_my_button
						putCursor(fbbuf, x, y, FOREGROUD);
					}
				}
			} else if (event_mouse.type == EV_REL) {
				if (event_mouse.code == REL_X) {
					//printf("x:%d\n", event_mouse.value);
					x += event_mouse.value;
					if (x < 0)
						x = 0;
					else if (x > 1919)
						x = 1919;
				} else if (event_mouse.code == REL_Y) {
//					printf("y:%d\n", event_mouse.value);
					y += event_mouse.value;
					if (y < 0)
						y = 0;
					else if (y > 1079)
						y = 1079;
				}
				if (inButton(myButton, x, y)) {
					if (myButton->state == BUTTON_STATE_RELEASED) {
						InputEnent *e = NULL;
						hoverButton(myButton, e);
						update_my_button
					}
				} else if (myButton->state != BUTTON_STATE_RELEASED) {
					InputEnent *e = NULL;
					exitButton(myButton, e);
					update_my_button
				}
				//printf("x:%d,y:%d", x, y);
				drawCursor(fbbuf, buffered, x0, y0);
				putCursor(fbbuf, x, y, FOREGROUD);
				x0 = x;
				y0 = y;
			}
		}
	}
//	for (i = 0; i < fbsize / sizeof(rgba); i++) {
////		fbbuf[i].red = (unsigned char) 0xff;
////		fbbuf[i].green = (unsigned char) 0x66;
////		fbbuf[i].blue = (unsigned char) 0x66;
////		fbbuf[i].alpha = (unsigned char) 0xff;
//		setRgb(fbbuf + i, 0xff6666);
//		//*(fbbuf + i) = 0xFF; //((i % 255) << 16) | ((255 - i % 255) << 8) | ((i % 255));
//		//*(fbbuf + i + 1) = 0x00; //((i % 255) << 16) | ((255 - i % 255) << 8) | ((i % 255));
//		//*(fbbuf + i + 2) = 0x33; //((i % 255) << 16) | ((255 - i % 255) << 8) | ((i % 255));
//	}
	end();
}

void myButtonActionListener(ActionEvent *e) {
	if (e->type == 1) {
		printf("This is myButtonActionListener.Left down\n");
	} else if (e->type == 2) {
		printf("This is myButtonActionListener.Right down\n");
	} else if (e->type == 4) {
		printf("This is myButtonActionListener.Middle down,exit\n");
		end();
	}
}

void end() {
#ifdef update_my_button
#undef update_my_button
#endif
	munmap(fbbuf, fbsize);
	close(fbfd);
	close(fd_mouse);
	exit(0);
}
