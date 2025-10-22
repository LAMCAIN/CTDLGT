#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

typedef struct Context
{
	long long sum;
	int count;
} Context;

typedef void (*CallbackFunc)(int value, Context* ctx);

void aggregate_callback(int value, Context* ctx)
{
	ctx->sum += value;
	ctx->count++;
}

void llForEach(Node* head, CallbackFunc cb, Context* ctx)
{
	Node* current = head;
	while (current != NULL)
	{
		cb(current->data, ctx);
		current = current->next;
	}
}

float average(Node* head)
{
	Context agg_context = { 0,0 };
	llForEach(head, aggregate_callback, &agg_context);

	if (agg_context.count == 0)
	{
		return 0.0f;
	}
	return (float)agg_context.sum / agg_context.count;
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
	float avg_foreach = average(head);
	printf("Average = %.2f\n", avg_foreach);
}