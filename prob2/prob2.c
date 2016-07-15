/*
	= PROJECT EULER: Problem 2 =
	Calculate the sum of the even Fibonnaci sequence, with the last number
	not exceeding 4,000,000.

	Written by: Ian Wong
	Date: 14/07/2016
*/

#include <stdlib.h>
#include <stdio.h>

// Naiive method
int prob2_function(int limit) {
	// Initial fib numbers
	int fn1 = 1;
	int fn2 = 2;
	int nextfn = fn1 + fn2;
	int sum = 2;	// initial even sum
	while (nextfn < limit) {
		sum = (nextfn % 2 == 0) ? (sum + nextfn) : (sum + 0);
		fn1 = fn2;
		fn2 = nextfn;
		nextfn = fn1 + fn2;
	}
	return sum;
}

int main(int argc, char* argv[]) {

	// Return sum
	printf("Sum of the even fibonnaci numbers less than 4 million:\n");
	printf("%d\n",prob2_function(4000000));

	return EXIT_SUCCESS;
}
