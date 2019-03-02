/*
	@author : vikasc
	problem : Write a C function to insert a new value in a sorted Circular Linked List (CLL).
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <climits>
#include <utility>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int lint;

struct node {
	int data;
	node *next;
	node(int value) : data(value), next(NULL) {}
};

void __sorted_insert(node **head, node *new_node) {
	node *current_node = *head;
	if (current_node == NULL) {
		new_node->next = new_node;
		*head = new_node;
	}
	else if (current_node->data >= new_node->data) {
		while (current_node->next != *head) {
			current_node = current_node->next;
		}
		current_node->next = new_node;
		new_node->next = *head;
		*head = new_node;
	} else {
		while (current_node->next != *head && current_node->next->data < new_node->data) {
			current_node = current_node->next;
		}
		new_node->next = current_node->next;
		current_node->next = new_node;
	}
}

void display(node *head) {
	node *start = head;
	if (start) {
		do {
			cout << start->data << " ";
			start = start->next;
		} while (start != head);
		cout << endl;
	} else {
		cout << "no element\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, data;
	cin >> N;
	node *head = NULL;
	for (int i = 0; i < N; ++i) {
		cin >> data;
		node *new_node = new node(data);
		__sorted_insert(&head, new_node);
	}
	display(head);
	return 0;
}