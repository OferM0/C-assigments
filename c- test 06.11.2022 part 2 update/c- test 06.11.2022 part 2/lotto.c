#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

struct lotto {	
	unsigned short id;
	char date[14];
	struct lotto* next;
	struct lotto* prev;
};

struct lotto_Header
{
	int Version;
	int lottoCount;
	char Reserved[1000];
};

struct lotto* head = NULL;
struct lotto* tail = NULL;

void printList()
{
	struct lotto* currentLotto = head;
	printf("Head");
	while (currentLotto != NULL)
	{
		printf("->(id: %d, date: %s)", currentLotto->id, currentLotto->date);
		currentLotto = currentLotto->next;
	}
	printf("->Null\n");
}

Add(unsigned short id, char date[14])
{
	struct lotto* curr;
	curr = (struct lotto*)malloc(sizeof(struct lotto));
	if (!curr) {
		printf("Allication Error\n");
		return;
	}
	curr->id = id;
	strcpy(curr->date, date);

	curr->next = NULL;
	curr->prev = NULL;
	if (head == NULL)
	{
		head = curr;
		tail = curr;
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}

void GetLottoDateIndex(unsigned short id)
{
	struct lotto* show = NULL;
	struct lotto* curr = head;

	while (curr != NULL)
	{
		if (curr->id == id)
		{
			show = curr;
			printf("Lotto number %d was at date: %s\n", show->id , show->date);
			return;
		}
		curr = curr->next;
	}
	(show) ? printf("(date: %s)", show->date) : printf("this index does not exist in oskar list\n");
}

void LoadFile()
{
	char date[14], str[1000];
	unsigned short id;
	FILE* f = fopen("Lotto.txt", "rb");

	if (f)
	{
		fgets(str, sizeof(str), f);
		while (str[0] != NULL)
		{
			char* token = strtok(str, ",");
			id = atoi(token);

			token = strtok(NULL, ",");
			strcpy(date, token);

			Add(id, date);
			str[0] = NULL;
			fgets(str, sizeof(str), f);
		}
		fclose(f);
	}
	else
	{
		// error
		return;
	}
}

int main()
{
	char userResponse;
	unsigned short id;

	LoadFile();

	printf("Please choose what to do. Q- for quit, P-to print list , N- for getting date by lotto id.\n");
	scanf(" %c", &userResponse);
	while (userResponse != 'Q')
	{
		switch (userResponse)
		{
		case 'Q':
			break;

		case 'N':
			printf("Pleas ente lotto id\n");
			scanf("%d", &id);
			GetLottoDateIndex(id);
			break;

		case 'P':
			printList();
			break;

		default:
			printf("Wrong selection. Try be more sharp\n");
			break;
		}

		printf("Please choose what to do. Q- for quit, P-to print list , N- for getting date by lotto id.\n");
		scanf(" %c", &userResponse);
	}
	return 0;
}