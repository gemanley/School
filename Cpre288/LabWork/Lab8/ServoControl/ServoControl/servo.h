/*
 * servo.h
 *
 * Created: 10/16/2012 6:18:54 PM
 *  Author: lbreuer
 */ 


#ifndef SERVO_H_
#define SERVO_H_


void timer3_init();
void move_servo(unsigned degree);
int countConvert(int c);


#endif /* SERVO_H_ */