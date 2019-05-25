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

// Rotattion Matrix : (cosx    -sinx)
//                    (sinx     cosx)
//solve a bit easier: what if we have to find the line parallel to y-axis such that both sides sum of weights become equal.
//and later rotate the point by 45º using "Rotation Matrix"
// so, (x, y) -> ((x - y)/√2, (x + y)√2) we can ignore the √2 that is just a scaling factor.

int main() {
    int N;
    cin >> N;
    int x, y, h;
    map <int, int> A;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> h;
        int rotated_x = x - y;  //rotated_y doson't matter here.
        A[rotated_x] += h;
    }
    vector <int> prefix_sum;
    prefix_sum.push_back(0);        //init.
    for (int i = -2e3; i < 2e3 + 1; ++i) {
        if (A.find(i) != A.end()) {
            int temp = prefix_sum.back() + A[i];
            prefix_sum.push_back(temp);
        }
    }
    int total = prefix_sum.back();
    bool ok = false;
    for (int i = 1; i < prefix_sum.size(); ++i) {
        if (prefix_sum[i] == total - prefix_sum[i]) {
            ok = true;
        }
        if (prefix_sum[i - 1] == total - prefix_sum[i]) {
            ok = true;
        }
    }
    ok ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
