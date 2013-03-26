#include <stdlib.h>
#include "open_interface.h"
#include "util.h"

void turn_counterclockwise(oi_t *sensor, int degrees)
{
	int sum = 0;
	oi_set_wheels(500, -500); // move forward; full speed
	while (sum < degrees) {
		oi_update(sensor_data);
		sum += sensor_data->angle;
	}
	oi_set_wheels(0, 0); // stop
}

void turn_clockwise(oi_t *sensor, int degrees)
{
		int sum = 0;
		oi_set_wheels(-500, 500); // move forward; full speed
		while (sum < degrees) {
			oi_update(sensor_data);
			sum -= sensor_data->angle;
		}
		oi_set_wheels(0, 0); // stop
}

void move_forward(oi_t *sensor, int centimeters)
{
		int sum = 0;
		oi_set_wheels(500, 500); // move forward; full speed
		while (sum < centimeters) {
			oi_update(sensor_data);
			sum += sensor_data->distance;
		}
		oi_set_wheels(0, 0); // stop
}

void move_backward(oi_t *sensor, int centimeters)
{
	int sum = 0;
	oi_set_wheels(-500, -500); // move forward; full speed
	while (sum < centimeters) {
		oi_update(sensor_data);
		sum -= sensor_data->distance;
	}
	oi_set_wheels(0, 0); // stop
}