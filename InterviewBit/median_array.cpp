#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <climits>

using namespace std;
typedef long long int lint;

double medianHelper(vector <int> A, vector <int> B) {
    int x = A.size();
    int y = B.size();
    //apply binary search for partition such that
    // partitionX + partitionY = (x + y + 1)/2;  here +1 for handling even-odd both sizes.
    int start = 0;
    int end = x;

    while (start <= end) {
        int partitionX = (start + end) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        //if partitionX = 0, means no-element on the left side then use -INF
        //if partitionX = x, means no-element on the right side then use +INF

        int maxLeftX = (partitionX == 0) ? INT_MIN : A[partitionX - 1];
        int maxRightX = (partitionX == x) ? INT_MAX : A[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : B[partitionY - 1];
        int maxRightY = (partitionY == y) ? INT_MAX : B[partitionY];

        if (maxLeftX <= maxRightY && maxLeftY <= maxRightX) {
            //partition done!
            if ((x + y) & 1) {
                return (double)max(maxLeftX, maxLeftY);
            } else {
                return ((double)max(maxLeftX, maxLeftY) + min(maxRightX, maxRightY)) / 2;
            }
        } else if (maxLeftX > maxRightY) {
            end = partitionX - 1;
        } else {
            start = partitionX + 1;
        }
    }
}

double getMedian(vector <int> A, vector <int> B) {
    if (A.size() < B.size()) {
        return medianHelper(A, B);
    } else {
        return medianHelper(B, A);
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector <int> A(m, 0), B(n, 0);
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    cout << getMedian(A, B) << endl;
    return 0;
}
