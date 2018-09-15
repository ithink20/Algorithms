#include <iostream>
#include <stdlib.h>

using namespace std;
#define M 11

class Queue {
public:
    int rear, front, *queue, size;
    Queue(int N) {
        size = N;
        queue = (int *)malloc(sizeof(int) * N);
        rear = -1;
        front = -1;
    }
    void enqueue(int x) {
        if (rear > size) {
            cout << "Overflow" << endl;
            front = rear = -1;
            return;
        }
        queue[++rear] = x;
        if (rear == 0) {
            front = 0;
        }
    }
    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Underflown\n";
            front = rear = -1;
            return 0;
        }
        int x = queue[front];
        front += 1;
        return x;
    }
    bool isEmpty() {
        if (front == -1 || front > rear) {
            return true;
        } else {
            return false;
        }
    }
    void display() {
        if (!isEmpty()) {
            for (int i = front; i <= rear; ++i) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }

};

void BFS(int A[M][M], int start) {
    int flag = 0, k = 0;
    Queue Q(1000);
    bool visited[M] = {false};
    visited[start] = true;
    Q.enqueue(start);
    while (!Q.isEmpty()) {
        int z = Q.dequeue();
        cout << z << " ";
        for (int i = 0; i < M; ++i) {
            if (A[z][i] && visited[i] == false) {
                Q.enqueue(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

class Stack {
public:
    int top, *stack, size;
    Stack(int N) {
        size = N;
        top = -1;
        stack = (int *)malloc(sizeof(int) * N);
    }
    bool isFull() {
        return (top == size);
    }
    void push(int x) {
        if (!isFull()) {
            stack[++top] = x;
        }
    }
    bool isEmpty() {
        return (top < 0);
    }
    void pop() {
        if (top < 0) {
            cout << "Underflow\n";
            top = -1;
        } else {
            top -= 1;
        }
    }
    int peek() {
        return stack[top];
    }
    void display() {
        int temp = top;
        while (temp > -1) {
            cout << stack[temp] << " ";
            temp -= 1;
        }
        cout << endl;
    }
};

bool visited[M] = {false};

void DFS(int A[M][M], int start) {
    Stack S(1000);
    S.push(start);
    visited[start] = true;
    while(!S.isEmpty()) {
        int z = S.peek();
        cout << z << " ";
        S.pop();
        for (int i = 0; i < M; ++i) {
            if (A[z][i] && visited[i] != true) {
                S.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int A[M][M];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    int start, connected_components = 0;
    cin >> start;
    cout << "BFS = ";
    BFS(A, start);
    cout << "DFS = ";
    DFS(A, start);
    cout << endl;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == false) {
            connected_components++;
            cout << "DFS = ";
            DFS(A, i);
        }
    }
    cout << endl;
    cout << "connected_components = " << connected_components + 1 << endl;
    (isbipertite(A)) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
