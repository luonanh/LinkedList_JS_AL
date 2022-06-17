#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int val;
	struct node* next;
	struct node* prev;
} node_t;

void printlist(node_t* head)
{
	node_t* curr = head;

	while (curr != NULL) {
		printf("%d - ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

node_t* create_new_node(int val)
{
	node_t* result = malloc(sizeof(node_t));
	result->val = val;
	result->next = NULL;
	result->prev = NULL;
	return result;
}

node_t* insert_at_head(node_t** head, node_t* node_to_insert)
{
	node_to_insert->next = *head;
	if (*head != NULL) {
		(*head)->prev = node_to_insert;
	}
	*head = node_to_insert;
	node_to_insert->prev = NULL;
	return node_to_insert;
}

node_t* find_node(node_t* head, int val)
{
	node_t* curr = head;
	while (curr) {
		if (curr->val == val)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

node_t* insert_after_node(node_t* node_to_insert_after, node_t* newnode)
{
	newnode->next = node_to_insert_after->next;
	if (newnode->next != NULL) {
		newnode->next->prev = newnode;
	}
	node_to_insert_after->next = newnode;
	newnode->prev = node_to_insert_after;
	return newnode;
}

void remove_node(node_t** head, node_t* node_to_remove)
{
	if (*head == node_to_remove) {
		*head = node_to_remove->next;
		if (*head != NULL) {
			(*head)->prev = NULL;
		}
		return;
	}
	else {
		node_to_remove->prev->next = node_to_remove->next;
		if (node_to_remove->next != NULL) {
			node_to_remove->next->prev = node_to_remove->prev;
		}
	}
	node_to_remove->next = NULL;
	node_to_remove->prev = NULL;
	return;
}

int main()
{
	node_t* head = NULL;
	node_t* tmp;

	for (int i = 0; i < 25; i++) {
		tmp = create_new_node(i);
		insert_at_head(&head, tmp);
	}

	tmp = find_node(head, 13);
	printf("found node with value %d\n", tmp->val);

	insert_after_node(tmp, create_new_node(75));

	remove_node(&head, tmp);
	remove_node(&head, head);

	printlist(head);

	return 0;
}
