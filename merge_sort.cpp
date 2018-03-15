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

void merge(int *A, int *B, int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    if (i > mid) {
        while (j <= h) {
            B[k++] = A[j++];
        }
    }
    if(j > h) {
        while (i <= mid) {
            B[k++] = A[i++];
        }
    }
    for (int m = 0; m < k; ++m) {
        A[l++] = B[m];
    }
}

void merge_sort(int *A, int *B, int l, int h) {
    if (l < h) {
        int mid = (l + h)/2;
        merge_sort(A, B, l, mid);
        merge_sort(A, B, mid + 1, h);
        merge(A, B, l, mid, h);
    }
}

int main() {
    int N;
    cin >> N;
    int A[N + 1], B[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    merge_sort(A, B, 0, N - 1);
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    return 0;
}
