#include <stdio.h>
#include <stdlib.h>
int main2()
{
	int x = 4, y = 3;                 //add values to the variables
	int nums[6] = { 0,1,2,3,4,5 };  //add values to the array
	int* arrPtr;

	// Section A - Print the variables
	puts("***** Section A *****"); 
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", (x * y) / 2); //right calculation for area size is: (x*y)/2

	// Section B - Print the static array "nums".
	puts("***** Section B *****"); 
	int i = 0;
	while (i < 6) {
		printf(" nums[%d] = %d\n", i, nums[i]);
		i++; //we must add this counting line else the while loop will turn into infinity loop
	}

	// Section C - Print allocated array.
	puts("***** Section C *****"); 
	arrPtr = (int*)malloc(sizeof(int) * 6); //dynamic array of size 6, change 10 to 6, add (int*) before malloc
	if (arrPtr) {
		for (i = 0; i < 6; i++) {
			arrPtr[i] = i; // add values to the dynamic array
			printf(" array[%d] = %d\n", i, arrPtr[i]);
		}
	}
	else {
		printf("Error Allocating Memory!\n");
		exit(1);
	}
	return 0;
} //there should be closint tag for the main