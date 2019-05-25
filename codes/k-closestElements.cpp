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

vector<int> getClosestElements(vector<int>& A, int k, int x) {
    int index = lower_bound(A.begin(), A.end(), x) - A.begin();
    int i = index - 1, j = index;
    while (k--) {
        if (i < 0 || (j < A.size() && abs(A[i] - x) > abs(A[j] - x))) {
            j++;
        } else {
            i--;
        }
    }
    return vector<int>(A.begin() + i + 1, A.begin() + j);
}

int main() {
    int N;
    cin >> N;
    vector <int> A;
    int x;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        A.push_back(x);
    }
    sort(A.begin(), A.end());
    int K, X;
    cin >> K >> X;
    vector <int> ans = getClosestElements(A, K, X);
    for (int i = 0; i < K; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
