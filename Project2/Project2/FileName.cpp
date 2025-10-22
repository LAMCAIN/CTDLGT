#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

float calculate(Node* head)
{
	if (head == NULL)
	{
		return 0.0f;
	}

	Node* current = head;
	long long sum = 0;
	int count = 0;
	
	while (current != NULL)
	{
		sum += current->data;
		count++;
		current=current->next;
	}

	return sum / count;
}

Node* create_node(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));

	if (new_node == NULL)
	{
		perror("Memory failed");
		exit(EXIT_FAILURE);
    }
	new_node->data = data;
	new_node->next = NULL;
	return new_node;

}

int main()
{
	Node* head = create_node(10);
	head->next = create_node(20);
	head->next->next = create_node(30);
	head->next->next->next = create_node(40);
	float avg_iter = calculate(head);
	printf("Average = %.2f\n", avg_iter);
}