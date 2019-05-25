#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef long long int lint;

// lps[] : contains the length of the longest common proper prefix and proper suffix.
// Ex:  "ABCD"
// prefix : {                                   suffix: {
//          "A", "AB", "ABC", "ABCD"                        "D", "CD", "BCD", "ABCD"
//      }                                           }
//
//   proper prefix or proper suffix is not the complete string.
//
//proper prefix : {                         proper suffix {
//          "A", "AB", "ABC"                                "D", "CD", "BCD"
//      }                                           }

/*
    step1 : start comparision of pattern[j] with j = 0 with characters of current window of text.
    step2 : keep incrementing i & j as text[i] and pattern[j] keep matches.
    step3 : when mismatch -
                * we know that characters pattern[0 ... j - 1] match with text[i - j + 1 ... i - 1] (j begins with 0).
                * we also know that lps[j - 1] is count of characters of pattern[0 ... j - 1] that are both prefix & suffix.
                * Now, we can conclude that we don't need to match these lps[j-1] characters with txt[i - j ... i - 1]
                  because these characters will anyway match.
*/
void createLPS(string pattern, int *lps) {
    int len = 0;
    lps[0] = 0;         //lps[0] will always be 0;
    int i = 1;
    while (i < pattern.length()) {
        if (pattern[len] == pattern[i]) {
            len += 1;
            lps[i] = len;
            i += 1;
        } else {        // when not matches
            if (len > 0) {
                len = lps[len - 1];
            } else if (len == 0) {
                lps[i] = 0;
                i += 1;
            }
        }
    }
}

vector <int> KMP(string text, string pattern) {
    int lps[pattern.length()];
    vector <int> foundPattern;
    createLPS(pattern, lps);
    int i = 0;           //indexing for text
    int j = 0;          //indexing for pattern
    while (i < text.length()) {
        if (pattern[j] == text[i]) {
            i += 1;
            j += 1;
        } if (j == pattern.length()) {
            foundPattern.push_back(i - j);
            j = lps[j - 1];
        } else if (i < text.length() && pattern[j] != text[i]) {
            if (j > 0) {
                j = lps[j - 1];
            } else if (j == 0) {
                i += 1;
            }
        }
    }
    return foundPattern;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector <int> patterns = KMP(text, pattern);
    cout << "Pattern found at indices: ";
    for (int i = 0; i < patterns.size(); ++i) {
        cout << patterns[i] << " ";
    }
    cout << endl;
    return 0;
}
