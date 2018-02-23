/*
 * InputEvent.h
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#ifndef INPUT_INPUTEVENT_H_
#define INPUT_INPUTEVENT_H_

typedef struct _inputEvent {
	unsigned char type;
	unsigned char value;
	unsigned char extra[2];
	void *src;
} InputEnent;

#endif /* INPUT_INPUTEVENT_H_ */
