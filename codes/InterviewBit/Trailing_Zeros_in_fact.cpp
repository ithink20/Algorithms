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

int countTrailingZeros(int N) {
    int count = 0;
    for (int i = 5; N / i >= 1; i *= 5) {
        count += N / i;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countTrailingZeros(N) << endl;
    return 0;
}
