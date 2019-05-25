#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>


using namespace std;

typedef long long int lint;

struct node {
    int data;
    node *next;
} *p;

node *head = NULL;

node *createNode(int data) {
    node *t = new node();
    t -> data = data;
    t -> next = NULL;
    return t;
}

void insertNode(node *new_node) {
    if (head == NULL) {
        head = new_node;
        p = head;
    } else {
        p -> next = new_node;
        p = new_node;
    }
}

void display() {
    node *temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    int N, data;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> data;
        node *new_node = createNode(data);
        insertNode(new_node);
    }
    display();
    return 0;
}
