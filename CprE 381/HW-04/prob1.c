/*
 *  prob1.c
 *  
 *
 *  Created by Trevor Lund on 2/15/12.
 *  Copyright 2012 Iowa State University. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 4;
	int result = 0;
	
	printf("Please enter a number >= 1 : ");
	scanf("%d", &N);
	if(N < 1)
		goto end;
	while (N > 0) {
		result += N;
		N--;
	}
	
	printf("\n\nThe result is:%d", result);
end:
	return 1;
}

