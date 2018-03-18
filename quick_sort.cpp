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

int partition(int *A, int start, int end) {
    int i = start + 1;
    int piv = A[start];             // taking 1st element as pivot
    for (int j = start + 1; j <= end; ++j) {
        if (A[j] < piv) {
            swap(A[i], A[j]);
            ++i;
        }
    }
    swap(A[start], A[i - 1]);
    return i - 1;       // return pivot_position
}

void quick_sort(int *A, int start, int end) {
    if (start < end) {
        int piv = partition(A, start, end);
        quick_sort(A, start, piv - 1);
        quick_sort(A, piv + 1, end);
    }
}    

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    quick_sort(A, 0, N - 1);
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
