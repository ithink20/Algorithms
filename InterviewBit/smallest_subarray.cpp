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

int smallestSubarrarWithSum(int *A, int N, int K) {
    int current_sum = 0;
    int len = N + 1;
    int start = 0, end = 0;
    while (end < N) {
        //keep adding the elements while satisfying the condition
        while (current_sum < K && end < N) {
            //Ignore subarrays with -ve sum if K is +ve
            if (current_sum <= 0 && K > 0) {
                start = end;
                current_sum = 0;
            }
            current_sum += A[end++];
        }
        //if sum is greater than K
        while (current_sum >= K && start < N) {
            //update len
            if (end - start < len) {
                len = end - start;
            }
            //remove begining elements
            current_sum -= A[start++];
        }
    }
    if (len == (N + 1)) {
        //cout << len << endl;
        return -1;
    } else {
        return len;
    }
}

int main() {
    int N, K;
    cin >> N;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cin >> K;
    cout << smallestSubarrarWithSum(A, N, K) << endl;
    return 0;
}
