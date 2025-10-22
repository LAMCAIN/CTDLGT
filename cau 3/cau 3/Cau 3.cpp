#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

Node* createNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode = NULL)
	{
		perror("Fail");
		exit(EXIT_FAILURE);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void printList(const char* name, Node* head)
{
	printf("%s:", name);
	if (head == NULL)
	{
		printf("EMPTY\n");
		return;
	}
	Node* current = head;
	while (current != NULL)
	{
		printf("%d ->", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void llInsertListAfter(Node* head1, Node* list2, Node* p)
{
	if (list2 == NULL)
	{
		printf("List L2 is empty. No insertion performed. \n");
		return;
	}
	if (p == NULL)
	{
		printf("Error: Insertion point 'p' cannot be NULL for 'insert after' operation. \n");
		return;
	}
	Node* rest_of_l1 = p->next;
	p->next = list2;

	Node* l2_tail = list2;
	while (l2_tail->next != NULL)
	{
		l2_tail = l2_tail->next;
	}

	l2_tail->next = rest_of_l1;

	printf("Successfully inserted L2 into L1 after node with data %d. \n", p->data);
}

void freeList(Node* head)
{
	Node* tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int main()
{
	Node* l1_head = createNode(1);
	l1_head->next = createNode(2);
	l1_head->next->next = createNode(3);
	l1_head->next->next->next = createNode(4);

	Node* p = l1_head->next;
	
	Node* l2_head = createNode(10);
	l2_head->next = createNode(20);
	l2_head->next->next = createNode(30);

	printf("---Initial State---\n");
	printList("L1", l1_head);
	printList("L2", l2_head);
	printf("Insertion point P has data: $d\n\n", p->data);

	llInsertListAfter(l1_head, l2_head, p);

	printf("\n---Final State ---\n");
	printList("L1 (Merged)", l1_head);
	printList("L2 (After Insertion)", l2_head);

	freeList(l1_head);
	return 0;
}