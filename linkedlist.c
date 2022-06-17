#include <stdlib.h>
#include <stdio.h>

#if 0
typedef struct node {
	int val;
	struct node* next;
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
	return result;
}

node_t* insert_at_head(node_t **head, node_t *node)
{
	node->next = *head;
	*head = node;
	return node;
}

node_t* find_node(node_t *head, int val)
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
	node_to_insert_after->next = newnode;
}

void remove_node(node_t** head, node_t* node_to_remove)
{
	if (*head == node_to_remove) {
		*head = node_to_remove->next;
		return;
	}
	else {
		node_t *tmp = *head;
		while (tmp != NULL && tmp->next != node_to_remove) {
			tmp = tmp->next;
		}
		if (tmp == NULL) return;
		tmp->next = node_to_remove->next;
		node_to_remove = NULL;
	}
	return;
	/* My way
	   node_t* prev, * curr;
	   curr = *head;
	   prev = NULL;

	   while (curr) {
	   if (curr == node_to_remove) {
	   curr = curr->next;
	   if (prev) {
	   prev->next = curr;
	   }
	   else {
	 *head = curr;
	 }
	 }
	 curr = curr->next;
	 }
	 */
}

int main()
{
	/*
	   node_t n1, n2, n3;
	   node_t* head;

	   n1.val = 45;
	   n2.val = 8;
	   n3.val = 32;

	   head = &n3;
	   n3.next = &n2;
	   n2.next = &n1;
	   n1.next = NULL;
	   printlist(head);

	   node_t n4;
	   n4.val = 13;
	   n4.next = &n3;
	   head = &n4;
	   printlist(head);

	   head = head->next;
	   printlist(head);
	   */
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

	printlist(head);

	return 0;
}
#endif
