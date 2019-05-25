#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <string>


using namespace std;

typedef long long int lint;

void permuteHelper(string s, string chosen, set<string> &alreadyTaken) {
    if (s == "") {                  // check empty
        if (alreadyTaken.find(chosen) == alreadyTaken.end()) {
            cout << chosen << endl;
            alreadyTaken.insert(chosen);
        }    
    } else {
        // choose/explore/unchoose
        for (int i = 0; i < s.length(); ++i) {
            // choose
            char c = s[i];
            chosen += c;
            s.erase(i, 1);

            // explore
            permuteHelper(s, chosen, alreadyTaken);

            // unchoose
            s.insert(i, 1, c);
            chosen.erase(chosen.length() - 1, 1);
        }
    }
}

void permute(string s) {
    set <string> alreadyTaken;
    permuteHelper(s, "", alreadyTaken);
}

int main() {
    string s;
    cin >> s;
    permute(s);
    return 0;
}
