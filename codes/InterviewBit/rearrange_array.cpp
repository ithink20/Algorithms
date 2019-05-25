#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef long long int lint;

void rearrange(int *A, int N) {
    for (int i = 0; i < N; ++i) {
        A[i] += (A[A[i]] % N) * N;
    }
    for (int i = 0; i < N; ++i) {
        A[i] /= N;
    }
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    rearrange(A, N);
    return 0;
}
