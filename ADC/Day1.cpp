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
    string str;
    cin >> str;
    long long int sum = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (i == str.length() - 1) {
            if (str[i] == str[0]) {
                sum += (int)str[i] - '0';
            }
        }
        if (str[i] == str[i + 1]) {
            sum += (int)str[i] - '0';
        }
    }
    cout << sum << endl;
    return 0;
}
