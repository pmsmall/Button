/*
 * ActionEvent.h
 *
 *  Created on: 2017年12月12日
 *      Author: frank
 */

#ifndef INPUT_ACTIONEVENT_H_
#define INPUT_ACTIONEVENT_H_

typedef struct _actionEvent {
	unsigned char type;
	unsigned char value;
	unsigned char actionMessage;
	unsigned char extra;
	void *src;
} ActionEvent;

#endif /* INPUT_ACTIONEVENT_H_ */
