#include "pch.h"
#include "CH2.h"

void testCH2() {
	std::cout << "Testing Chapter 2: " << std::endl;

	std::cout << "Testing removeDupsA..." << std::endl;
	node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 2);
	push(&head, 2);
	push(&head, 3);
	push(&head, 3);
	push(&head, 4);
	printList(head);
	removeDups(head);
	printList(head);
	deleteList(&head);

	std::cout << "Testing removeDupsB..." << std::endl;
	head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 2);
	push(&head, 2);
	push(&head, 3);
	push(&head, 3);
	push(&head, 4);
	printList(head);
	removeDups2(head);
	printList(head);

	std::cout << "Testing KtoLast..." << std::endl;
	printList(head);
	std::cout << KtoLast(head, 1)->data << std::endl;
	std::cout << KtoLast(head, 2)->data << std::endl;
	std::cout << KtoLast(head, 3)->data << std::endl;
	std::cout << KtoLast(head, 4)->data << std::endl;

	std::cout << "Testing delMiddle..." << std::endl;
	push(&head, 5);
	printList(head);
	delMiddle(head->next);
	printList(head);
	delMiddle(head->next);
	printList(head);
	deleteList(&head);

	std::cout << "Testing partition..." << std::endl;
	push(&head, 1);
	push(&head, 2);
	push(&head, 10);
	push(&head, 5);
	push(&head, 8);
	push(&head, 5);
	push(&head, 3);
	std::cout << "Partition: 5" << std::endl;
	printList(head);
	printList(partition(head, 5));
	
}

void printList(node* n)
{
	while (n != NULL)
	{
		printf(" %d ", n->data);
		n = n->next;
	}
	std::cout << std::endl;
}

void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

void deleteList(struct node** head_ref)
{
	/* deref head_ref to get the real head */
	struct node* current = *head_ref;
	struct node* next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	/* deref head_ref to affect the real head back
	   in the caller. */
	*head_ref = NULL;
}

//================ Q1 A ==================
void removeDups(node* head) {
	std::unordered_set<int> map = {};
	node* prev = NULL;
	node* N = head;
	node* temp = NULL;
	while (N != NULL) {
		if (map.find(N->data) != map.end()) {
			temp = N;
			prev->next = N->next;
		}	
		else {
			map.insert(N->data);
			prev = N;
		}
		N = N->next;
		if (temp) {
			free(temp);
			temp = NULL;
		}
	}
}

//================ Q1 B ==================
void removeDups2(node* head) {
	while (head != NULL) {
		node* runner = head->next;
		node* prev = head;
		node* temp = NULL;

		while (runner != NULL) {
			if (runner->data == head->data) {
				prev->next = runner->next;
				temp = runner;
			}
			else {
				prev = prev->next;
			}
			runner = runner->next;
			if (temp) {
				free(temp);
				temp = NULL;
			}
		}
		head = head->next;
	}
}

//================ Q2 ==================
node* KtoLast(node* head, int k) {
	node* p1 = head;
	node* p2 = head;
	for (int i = 0; i < k; i++) {
		if (p1 == NULL)
			return NULL;
		p1 = p1->next;
	}
	while (p1 != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

//================ Q3 ==================
void delMiddle(node* N) {
	if (N == NULL || N->next == NULL)
		return;
	node* temp = N->next;
	N->data = N->next->data;
	N->next = N->next->next;
	free(temp);
}

//================ Q4 ==================
node* partition(node* N, int x) {
	node* head = N;
	node* tail = N;

	while (N != NULL) {
		node* next = N->next;
		if (N->data < x) {
			N->next = head;
			head = N;
		}
		else {
			tail->next = N;
			tail = N;
		}
		N = next;
	}
	tail->next = NULL;
	return head;
}