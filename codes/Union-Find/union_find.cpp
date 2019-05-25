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

// Time complexity : O(M * N)

void initialize(int *A, int N) {
    for (int i = 0; i < N; ++i) {
        A[i] = i;
    }
}

bool find(int *A, int N, int x, int y) {
    return A[x] == A[y];
}

void _union(int *A, int N, int x, int y) {
    int temp = A[x];
    for (int i = 0; i < N; ++i) {
        if (A[i] == temp) {
            A[i] = A[y];
        }
    }
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    initialize(A, N);
    int Q;
    cin >> Q;
    while (Q--) {
        int uf, x, y;
        cin >> uf >> x >> y;
        if (uf == 1) {
            _union(A, N, x, y);
        } else {
            find(A, N, x, y) ? cout << "connected\n" : cout << "Not connected\n";
        }
    }
    return 0;
}
