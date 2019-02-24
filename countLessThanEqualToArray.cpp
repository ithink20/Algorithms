/*
    @author : vikasc
    problem : For each element in 1st array count elements less than or equal to it in 2nd array
    Tag     : Amazon
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <climits>
#include <utility>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int lint;

int search(int *B, int l, int h, int x) {
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if (B[mid] <= x) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return h;
}

void countLessThanorEqual(int *A, int *B, int N, int M) {
    sort(B, B + M);
    for (int i = 0; i < N; ++i) {
        int index = search(B, 0, M - 1, A[i]);
        cout << index + 1 << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int A[N + 1], B[M + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    countLessThanorEqual(A, B, N, M);
    return 0;
}