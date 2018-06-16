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

class Queue {
private:
	node *rear, *front;
public:
	Queue() {
		rear = NULL;
		front = NULL;
	}
	void enqueue();
	void dequeue();
	void display();
};

void Queue :: enqueue() {
	int data;
	cin >> data;
	node *new_node = new node(data);
	if (front == NULL) {
		front = rear = new_node;
	} else {
		rear -> next = new_node;
		rear = new_node;
	}
}

void Queue :: dequeue() {
	if (front == NULL) {
		cout << "Error: Queue Underflow!" << endl;
	} else {
		node *temp = front;
		front = front -> next;
		if (front == NULL) {
			rear = NULL;
		}
		// print deleted temp -> data.
		delete temp;
	}
}

void Queue :: display() {
	if (front == NULL) {
		cout << "Warning: Queue is Empty!" << endl;
	} else {
		node *temp = front;
		while (temp) {
			cout << temp -> data << " ";
			temp = temp -> next;
		}
	}
}

int main() {
	Queue q;
	int N;
	cin >> N;
	int x;
	for (int i = 0; i < N; ++i) {
		q.enqueue();
	}
	q.display();
	//q.dequeue();
	//cout << endl;
	//q.display();	
	return 0;
}