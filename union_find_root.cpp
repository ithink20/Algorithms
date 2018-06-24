#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef long long int lint;

void initialise(int *A, int N) {
    for (int i = 0; i < N; ++i) {
        A[i] = i;
    }
}

int root(int *A, int i) {
    while (A[i] != i) {
        i = A[i];
    }
    return i;
}

void _union(int *A, int x, int y) {
    int root_x = root(A, x);
    int root_y = root(A, y);
    A[root_x] = root_y;             //setting parent of root(x) as root(y)
}

bool find(int *A, int x, int y) {
    return root(A, x) == root(A, y);
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    initialise(A, N);
    int Q;
    cin >> Q;
    while (Q--) {
        int uf, x, y;
        cin >> uf >> x >> y;
        if (uf == 1) {
            _union(A, x, y);
        } else {
            find(A, x, y) ? cout << "connected\n" : cout << "Not connected\n";
        }
    }
    return 0;
}
