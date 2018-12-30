// @author: vikaschaurasiya
// time-complexity: O(log(m + n))

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;
typedef long long int lint;
#define sq(a) (a) * (a)     //sq(a) a * a   it's not correct, run for sq(2+2)

double findMedian(int *A, int *B, int N, int M) {
    if (N > M) {
        return findMedian(B, A, M, N);
    }
    int x = N, y = M;
    int low = 0, high = x;
    while (low <= high) {
        int partition_x = (low + high)/2;
        int partition_y = (x + y + 1)/2 - partition_x;

        //partition_x = 0 means nothing is there on left side
        int maxleft_x = (partition_x == 0) ? INT_MIN : A[partition_x - 1];
        int minright_x = (partition_x == x) ? INT_MAX : A[partition_x];

        int maxleft_y = (partition_y == 0) ? INT_MIN : B[partition_y - 1];
        int minright_y = (partition_y == y) ? INT_MAX : B[partition_y];

        if (maxleft_x <= minright_y && maxleft_y <= minright_x) {
            //partitioned at correct place
            if ((x + y) % 2 == 0) {  //case: even
                return ((double)max(maxleft_x, maxleft_y) + min(minright_x, minright_y))/2.0;
            } else {    //case: odd
                return max(maxleft_x, maxleft_y);
            }
        } else if (maxleft_x > minright_y) {
            high = partition_x - 1;
        } else {
            low = partition_x + 1;
        }
    }
    return -1;  //arrays not sorted. invalid input
}

int main() {
    int N, M;
    cin >> N >> M;
    int A[N + 1], B[M + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    cout << findMedian(A, B, N, M) << endl;
    return 0;
}
