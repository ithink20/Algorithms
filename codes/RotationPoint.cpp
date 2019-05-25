/*
    @author : vikasc
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
        return (mid + 1);
    }
    if (mid > l && A[mid] < A[mid - 1]) {
        return mid;
    }
    if (A[h] > A[mid]) {
        return getPointofRotation(A, l, mid - 1);
    }
    return getPointofRotation(A, mid + 1, h);
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
    cout << getPointofRotation(A, 0, N - 1) << endl;
    return 0;
}