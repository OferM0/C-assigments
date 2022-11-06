#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// struct to collect counting info about english letters found in a text file.
typedef struct letter {
	char small;
	char big;
	int counter;
	struct letter* next; // we must add next pointer
	struct letter* prev; // we must add prev pointer
}letter;

//Function to free linked list
void freeList(letter* head) {
	letter* releaseItem;
	letter* runItem = head;
	while (runItem != NULL) {
		releaseItem = runItem;
		runItem = runItem->next;
		free(releaseItem);
	}
}
int main()
{
	//Next two string represents all the english alphabets (small and capital)
	char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
	char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int lettersCountArr[26] = { 0 }; // size of array need to be as count of alphabet letters
	char readChar, ch;
	FILE* f;
	f = fopen("myFile.txt", "r");
	if (!f)                   // add condition to check if file exist
	{
		printf("File Error");
		return;
	}

	// Display the content of myFile.txt and count letters
	printf("the content of myFile.txt :\n");
	while ((readChar = fgetc(f)) != EOF) //change this condition from 0 to EOF
	{
		printf("%c", readChar);
		for (int i = 0; i < strlen(smallAlpha); i++) {
			if (readChar == smallAlpha[i] || readChar ==
				bigAlpha[i])
				lettersCountArr[i]++;
		}
	}
	fclose(f);

	// Build Linked list from file content
	// Every node represent English letter (small and big).
	letter* HEAD = NULL;
	letter* TAIL = NULL;
	for (int j = 0; j < strlen(smallAlpha); j++) {
		letter* letterItem = (letter*)malloc(sizeof(letter));
		if (!letterItem) {
			puts("Error Allocating Memory!");
			exit(1);
		}

		letterItem->small = 'a' + j;
		letterItem->big = 'A' + j;
		letterItem->counter = lettersCountArr[j];

		letterItem->next = NULL; //add null to the next and prev of item
		letterItem->prev = NULL; //

		if (!HEAD)       // add condition to build first node- the HEAD in case it's null else regular adding
		{
			HEAD = letterItem;
			TAIL = letterItem;
		}
		else
		{
			// Creating the linked list
			TAIL->next = letterItem;
			letterItem->prev = TAIL;
			TAIL = letterItem;
			TAIL->next = NULL;
		}
		
	}
	return 0;
}