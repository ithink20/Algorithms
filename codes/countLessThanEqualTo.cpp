/*
    @author : vikasc
    problem: Count elements less than or equal to a given value in a sorted rotated array
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

int getPointofRotation(int *A, int l, int h) {
    if (h < l) {
        return 0;
    }
    if (h == l) {
        return l;
    }
    int mid = l + (h - l) / 2;
    if (mid < h && A[mid + 1] < A[mid]) {
        return mid + 1;
    }
    if (mid > l && A[mid] < A[mid - 1]) {
        return mid;
    }
    if (A[h] > A[mid]) {
        return getPointofRotation(A, l, mid - 1);
    }
    return getPointofRotation(A, mid + 1, h);
}

int search(int *A, int l, int h, int X) {
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (A[mid] <= X) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return h;
}

int countLessThanEqualto(int *A, int N, int X) {
    int min_index = getPointofRotation(A, 0, N - 1);
    // if largest element <= X in A[min_index...N - 1]
    if (X <= A[N - 1]) {
        return search(A, min_index, N - 1, X) - min_index + 1;
    }
    //if largest element <= X in A[0....min_index - 1]
    if ((min_index - 1 >= 0) && X <= A[min_index - 1]) {
        return N - min_index + 1 + search(A, 0, min_index - 1, X);
    }
    //all elements <= X
    return N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int X;
    cin >> X;
    cout << countLessThanEqualto(A, N, X) << endl;
    return 0;
}