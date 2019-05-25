#include <iostream>

using namespace std;

int binarySearch(int *A, int l, int h, int x) {
    if (h >= l) {
        int mid = (l + h)/2;
        if (A[mid] == x) {
            return mid;
        }
        if (A[mid] > x) {
            return binarySearch(A, l, mid - 1, x);
        }
        return binarySearch(A, mid + 1, h, x);
    }
    return -1;
}

int main() {
    int X, N;
    cin >> N >> X;
    int A[N + 1];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int result = binarySearch(A, 0, N - 1, X);
    if (result == -1) {
        cout << "Element Not found" << endl;
    } else {
        cout << "Element found at " << result << " index" << endl;
    }
    return 0;
}