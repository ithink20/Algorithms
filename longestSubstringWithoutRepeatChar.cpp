#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <utility>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;
typedef long long int lint;
#define sq(a) (a) * (a)     //sq(a) a * a   it's not correct, run for sq(2+2)

void longestSubstringWithoutRep(string str) {
    if (str.length() == 0) cerr << "Error: empty string" << '\n';

    //to store last occurrence of each already visited character
    unordered_map<char, int> M;
    int start_current_substr = 0, start_max_substr = 0, max_length = 0;
    M[str[0]] = 0;                          //last occurrence of first character
    int i;
    for (i = 1; i < str.length(); ++i) {
        if (M.find(str[i]) == M.end()) {
            //not found, so add it
            M[str[i]] = i;
        } else {
            //check if that occurrence is before or after starting point of current substring.
            if (M[str[i]] >= start_current_substr) {
                if (max_length < i - start_current_substr) {
                    max_length = i - start_current_substr;
                    start_max_substr = start_current_substr;
                }
                //start after the last occurrence to avoid repetition
                start_current_substr = M[str[i]] + 1;
            }
            M[str[i]] = i;
        }
    }
    //compare length of last substring
    if (max_length < i - start_current_substr) {
        max_length = i - start_current_substr;
        start_max_substr = start_current_substr;
    }
    cout << str.substr(start_max_substr, max_length) << endl;
}

int main() {
    string str;
    cin >> str;
    longestSubstringWithoutRep(str);
    return 0;
}
