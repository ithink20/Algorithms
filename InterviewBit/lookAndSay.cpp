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

string lookAndSay(int N) {
    if (N == 1) {
        return "1";
    }
    if (N == 2) {
        return "11";
    }
    string seq = "11";
    for (int i = 3; i < N + 1; ++i) {
        seq += '?';
        int count = 1;
        string temp = "";
        for (int j = 1; j < seq.length(); ++j) {
            if (seq[j - 1] != seq[j]) {
                temp += count + '0';
                temp += seq[j - 1];
                count = 1;
            } else {
                count += 1;
            }
        }
        seq = temp; //update
    }
    return seq;
}

int main() {
    int N;
    cin >> N;
    cout << lookAndSay(N) << endl;
    return 0;
}
