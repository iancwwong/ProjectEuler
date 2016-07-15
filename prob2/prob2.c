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

// Method 2: Calculate every 3rd fibonnaci number, to avoid testing for 'even'
// as every 3rd number is even! eg 1, 1, *2, 3, 5, *8, etc.
// NOTE: The 3rd number is stored as 'nextfn'
int prob2_function2(int limit) {
	// initial fib numbers
	int fn1 = 1;
	int fn2 = 1;
	int nextfn = fn1 + fn2;
	int sum = 0;
	while (nextfn < limit) {
		sum += nextfn;
		
		// recalculate 3rd number
		fn1 = fn2 + nextfn;
		fn2 = nextfn + fn1;
		nextfn = fn1 + fn2;
	}
	return sum;
}

// Method 3: Find by recursion, through the special recursive formula:
// F(n)=4*F(n-3)+F(n-6)
// where F(n) is an even fibonnaci number
// NOTE: Similar to method 2, where we're checking every 3rd number

int main(int argc, char* argv[]) {

	// Return sum
	printf("Sum of the even fibonnaci numbers less than 4 million:\n");
	printf("%d\n",prob2_function2(4000000));

	return EXIT_SUCCESS;
}
