#include<stdio.h> //change the closing tag from < to >
#pragma warning(disable : 4996) // add this pragma warning else there will be errors

int main1() {
	int a = 4, b = 7; //change the ; in n=middle of declaring variables to ,
	float c;
	scanf("%f", &c); //add & before variable c because it's a scan function
	if (5 == c) // add = because it's a condition
		printf("%f", c); //add f to end of print- right syntax of function- printf
}

