#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1()
{
	

	int numbers[10];
	FILE* f;

	for (int i = 0; i < 10; i++)
	{
		printf("Pleas enter number\n");
		scanf("%d", &numbers[i]);
	}

	f = fopen("HW_file1.bin", "w");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		fwrite(numbers, sizeof(int), 10, f);

		fclose(f);

		//check if writing to file successed.
       
		/* 
		int num;
		f = fopen("HW_file1.bin", "r");
		for (int i = 0; i < 10; i++)
		{
			fread(&num, sizeof(int), 1, f);
			printf("%d ", num);
		}
		fclose(f);
		*/
	}

	return 0;
}

int main_3()
{
	int getval;
	char getname[100];

	struct Items
	{
		int val;
		char name[100];
		short answer;
	};

	struct Items item1, item2, item3;
	FILE* f;


	printf("Please enter val and name\n");
	scanf("%d %s", &getval, getname);

	item1.val = getval;
	strcpy(item1.name, getname);
	item1.answer = (item1.val > 10 && strlen(item1.name) > 5) ? 1 : 0;

	printf("Please enter val and name\n");
	scanf("%d %s", &getval, getname);

	item2.val = getval;
	strcpy(item2.name, getname);
	item2.answer = (item2.val > 10 && strlen(item2.name) > 5) ? 1 : 0;

	printf("Please enter val and name\n");
	scanf("%d %s", &getval, getname);

	item3.val = getval;
	strcpy(item3.name, getname);
	item3.answer = (item3.val > 10 && strlen(item3.name) > 5) ? 1 : 0;


	f = fopen("HW_file3.bin", "w");

	if (f == NULL) {
		printf("Error");
	}
	else
	{
		fwrite(&item1, sizeof(struct Items), 1, f);
		fwrite(&item2, sizeof(struct Items), 1, f);
		fwrite(&item3, sizeof(struct Items), 1, f);

		fclose(f);
	}

	return 0;
}
