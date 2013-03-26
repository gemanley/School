/*
 * convert.c
 *
 *  Created on: Jan 13, 2012
 *      Author: trevorlund
 */
#include <stdio.h>
#define KILOS_PER_POUND 0.45359 // No semicolon here
int main(void) {

	// Must declare pounds here for pedantic
	int pounds;
	printf("US Pounds  UK St. lbs  Int. kg\n");
	for(pounds = 10; pounds < 250; pounds += 10) {
		print_converted(pounds);
	}
	return 0;
}

void print_converted(int pounds) {
	int stones = pounds / 14;
	int uklbs = pounds / .14;
	float kilos = KILOS_PER_POUND * pounds;
	printf(" %d %d %d  %f\n", pounds, stones, uklbs, kilos);
}
