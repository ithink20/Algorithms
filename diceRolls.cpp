#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>


using namespace std;

typedef long long int lint;

void diceHelper(int N, vector<int> &chosen) {
    if (N == 0) {
        // base case
        cout << "(";
        int i;
        for (i = 0; i < chosen.size() - 1; ++i) {
            cout << chosen[i] << ", ";
        }
        cout << chosen[i];
        cout << ")\n";
    } else {
        // some dice left to roll
        // for each value one dice coud have.
        for(int i = 1; i <= 6; ++i) {
            chosen.push_back(i);                //choose
            diceHelper(N - 1, chosen);          // explore
            chosen.erase(chosen.end() - 1);     // un-choose
        }
    }
}

void diceRolls(int N) {
    vector <int> chosen;
    diceHelper(N, chosen);
}

int main() {
    int N;
    cin >> N;
    diceRolls(N);
    return 0;
}
