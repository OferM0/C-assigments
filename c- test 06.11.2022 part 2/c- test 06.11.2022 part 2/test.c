#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

void func1(char str[1000])
{

    char first[501], second[501];
    int size, divideSize, count=0;

    size = strlen(str);
    divideSize = size / 2;

    for (int i = 0; i < divideSize; i++) {
        first[i] = str[i];
        count++;
    }
    first[count] = '\0';

    count = 0;
    for (int i = 0; i < strlen(str)-divideSize; i++) {
        second[i] = str[i+divideSize];
        count++;
    }
    second[count] = '\0';

    printf("first : %s\n", first);
    printf("second : %s\n", second);
}

void func2(char str[100])
{

    char first[51], second[51];
    int size, divideSize, count = 0;

    size = strlen(str);
    divideSize = size / 2;

    for (int i = 0; i < divideSize; i++) {
        first[i] = str[i];
        count++;
    }
    first[count] = '\0';

    printf("first : %s\n", first);

    while (strlen(first) > 1)
    {
        count = 0;
        for (int i = 0; i < strlen(first) / 2; i++) {
            first[i] = first[i];
            count++;
        }
        first[count] = '\0';
        printf("first : %s\n", first);
    }
}

int Add222(int num)
{
    printf("%d\n", num);
    return (num != 100)? Add222(num + 1) + 1: 0;

}

int main1()
{
    //char str [100] = "abcdefghijklmnopqrstuvwxyz";
    //func1(str);
    //func2(str);
    //Add222(1);

	return 0;
}
