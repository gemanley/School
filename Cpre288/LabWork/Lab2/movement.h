#ifndef MOVEMENT_H
#define MOVEMENT_H

void move_forward(oi_t *sensor, int millimeters);
void move_backward(oi_t *sensor, int millimeters);
void turn_clockwise(oi_t *sensor, int degrees);
void turn_counterclockwise(oi_t *sensor, int degrees);
void move_totalDistanceForward(oi_t *sensor, int millimeters);

#endif