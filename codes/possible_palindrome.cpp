#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isPossible(string :: iterator low, string :: iterator high) {
    while (low < high) {
        if (*low != *high) {
            return false;
        }
        ++low;
        --high;
    }
    return true;
}

int possibePalindromeByremoving1char(string str) {
    int l = 0, h = str.size() - 1;
    while (l < h) {
        if (str[l] == str[h]) {
            ++l; --h;
        } else {
            if (isPossible(str.begin() + l + 1, str.begin() + h)) {
                return l;
            } else if (isPossible(str.begin() + l, str.begin() + h -1)) {
                return h;
            }
            return -1;
        }
    }
    return -2;
}

int main() {
    string str;
    cin >> str;
    int index = possibePalindromeByremoving1char(str);
    if (index == -1) {
        cout << "can't make it palindrome." << endl;
    } else if (index == -2) {
        cout << "possible without removing any character." << endl;
    } else {
        cout << "possible by removing char at " << index << " index" << endl;
    }
    return 0;
}