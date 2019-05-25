#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <string>

using namespace std;

typedef long long int lint;

struct node {
	int data;
	node *next;
	node(int value) : data(value), next(NULL) {}
};

class CQueue {
private:
	node *last;
public:
	CQueue() {
		last = NULL;
	}
	void enqueue(int val);
	void dequeue();
	void display();
};

void CQueue :: enqueue(int val) {
	node *new_node = new node(val);
	if (last == NULL) {
		last = new_node;
		new_node -> next = last;
	} else {
		new_node -> next = last -> next;
		last -> next = new_node;
		last = new_node;
	}
}

void CQueue :: display() {
	node *temp;
	if (last == NULL) {		//Empty list
		return;
	}
	temp = last -> next;
	while (temp != last) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << temp -> data << endl;
}

int main() {
	CQueue cq;
	int N;
	cin >> N;
	while (N--) {
		int data;
		cin >> data;
		cq.enqueue(data);
	}
	cq.display();
	return 0;
}