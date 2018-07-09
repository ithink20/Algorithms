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

int main() {
    int N;
    cin >> N;
    int A[N + 1], ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] == 1) {
            ans += 1;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < N; ++i) {
        if (A[i + 1] <= A[i] && i + 1 < N) {
            cout << A[i] << " ";
        }
    }
    cout << A[N - 1] << endl;
    return 0;
}
