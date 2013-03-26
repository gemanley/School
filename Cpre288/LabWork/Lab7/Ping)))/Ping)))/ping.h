/*
 * ping.h
 *
 * Created: 10/23/2012 6:18:54 PM
 *  Author: lbreuer
 */ 


#ifndef PING_H_
#define PING_H_

unsigned ping_read();
void send_pulse();
unsigned long time2dist( unsigned long time);
char getOverflow();
void timer_init();


#endif /* PING_H_ */