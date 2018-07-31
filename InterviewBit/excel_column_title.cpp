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
#define MAX 100
typedef long long int lint;

string getTitle(int N) {
    char str[MAX];
    int i = 0;

    while (N > 0) {
        int rem = N % 26;
        if (rem == 0) {
            str[i++] = 'Z';
            N = (N / 26) - 1;
        } else {
            str[i++] = (rem - 1) + 'A';
            N /= 26;
        }
    }
    str[i] = '\0';
    reverse(str, str + strlen(str));
    return str;
}

int main() {
    int N;
    cin >> N;
    cout << getTitle(N) << endl;
    return 0;
}
