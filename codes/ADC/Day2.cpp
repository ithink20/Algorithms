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
    int sum = 0;
    while (1) {
        int x, min = 9999999, max = -1;
        for (int i = 0; i < 16; ++i) {
            cin >> x;
            if (min > x) {
                min = x;
            }
            if (max < x) {
                max = x;
            }
        }
        sum += max - min;
        cout << sum << endl;
    }
    return 0;
}
