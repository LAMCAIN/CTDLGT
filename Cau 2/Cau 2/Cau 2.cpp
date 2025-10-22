#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

#define POOL_SIZE 10
static Node NODE_POOL[POOL_SIZE];
static int pool_index = 0;

Node* custom_alloc()
{
	if (pool_index < POOL_SIZE)
	{
		return &NODE_POOL[pool_index++];
	}
	printf("ERROR");
	exit(1);
	return NULL;
}

Node* llConvert(int* arr, int count)
{
	Node* head = NULL;
	Node* current = NULL;

	for (int i = 0; i < count; i++)
	{
		Node* newNode = custom_alloc();
		if (newNode == NULL)
		{
			return head;
		}
		newNode->data = arr[i];
		newNode->next = NULL;

		if (head == NULL)
		{
			head = newNode;
			current = newNode;
		}
		else
		{
			current->next = newNode;
			current = newNode;
		}
	}
	return head;
}

void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		if (temp->next != NULL)
		{
			printf("->");
		}
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int dataArray[] = { 10,20,30,40,50,60,70,80 };
	int arrayCount = sizeof(dataArray) / sizeof(dataArray[0]);

	printf("input array: [");
	for (int i = 0; i < arrayCount; i++)
	{
		printf("%d%s", dataArray[i], i < arrayCount - 1 ? "," : "");
	}
	printf("]\n\n");

	Node* listHead = llConvert(dataArray, arrayCount);
	printList(listHead);

	if (listHead && listHead->next && listHead->next->next)
	{
		printf("\nVerification check (List[2]): Data is %d\n", listHead->next->next->data);
	}
	return 0;
}