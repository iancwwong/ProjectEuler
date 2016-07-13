/*
	= PROJECT EULER: Problem 1 =
	Find the sum of all numbers, divisible by 3 or 5, under
	a specific value (eg under 1000)

	Written by: Ian Wong
	Date: 14/07/2016
*/

#include <stdlib.h>
#include <stdio.h>

// naiive calculation
int prob1_function(int limit) {
	int sum = 0;
	int i = 0;
	while (i < limit) {
		sum = (i%3 == 0 || i%5 == 0) ? (sum + i) : (sum + 0);
		i++;
	}
	return sum;
}

// Set theory calculation (much faster)
int prob1_function2(int limit) {
	int num3s = (limit - 1) / 3;
	int num5s = (limit - 1) / 5;
	int num15s = (limit - 1) / 15;
	int sum3s = num3s * (3 + 3 * num3s) / 2;
	int sum5s = num5s * (5 + 5 * num5s) / 2;
	int sum15s = num15s * (15 + 15 * num15s) / 2;
	return (sum3s + sum5s - sum15s);
}

int main(int argc, char* argv[]) {

	// Usage: ./prob1 <number>
	if (argc < 2) {
		printf("Error. Usage: ./prob1 <number>\n");
		return 0;
	}

	// Calculate sum; print result
	int limit = atoi(argv[1]);
	int sum = prob1_function2(limit);
	printf("Sum of all numbers below %d that are divisible by 3 or 5:\n", limit);
	printf("%d\n",sum); 

	return EXIT_SUCCESS;
}
