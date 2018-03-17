/*
    Aim: to calculate the maximum sum of 'k' consecutive elements in the array.
*/
// Brute Force technique - time complexity O(k*n), n - size of array.
// window sliding - time complexity O(n). (it brings two loops into one.)

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int maxSum(int *A, int N, int k) {
    if (N < k) {
        cout << "Invalid";
    }
    int max_sum = 0;
    for (int i = 0; i < k; ++i) {
        max_sum += A[i];
    }
    int window_sum = max_sum;
    for (int i = k; i < N; ++i) {
        window_sum += A[i] - A[i - k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int k;
    cin >> k;
    cout << maxSum(A, N, k) << endl;
    return 0;
}