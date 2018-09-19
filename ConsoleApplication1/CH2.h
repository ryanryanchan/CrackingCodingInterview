#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cassert>
#include <unordered_set>

struct node {
	int data;
	node* next;
};
void push(struct node** head_ref, int new_data);
void deleteList(struct node** head_ref);
void printList(node* n);

void testCH2();
void removeDups(node* head);
void removeDups2(node* head);
node* KtoLast(node* head, int k);
void delMiddle(node* N);
node* partition(node* N, int x);