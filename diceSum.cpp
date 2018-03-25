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

int totalcalls = 0;

int sumAll(vector <int> &chosen) {
    int sum = 0;
    for(int i = 0; i < chosen.size(); ++i) {
        sum += chosen[i];
    }
    return sum;
}

void diceHelper(int N, vector<int> &chosen, int desiredSum) {
    totalcalls++;
    if (N == 0) {
        // base case
        int i;
        if (sumAll(chosen) == desiredSum) {
            cout << "(";
            for (i = 0; i < chosen.size() - 1; ++i) {
                cout << chosen[i] << ", ";
            }
            cout << chosen[i];
            cout << ")\n";
        }
    } else {
        for(int i = 1; i <= 6; ++i) {
            chosen.push_back(i);                            //choose
            diceHelper(N - 1, chosen, desiredSum);          // explore
            chosen.erase(chosen.end() - 1);                 // un-choose
        }
    }
}

void diceSum(int N, int desiredSum) {
    vector <int> chosen;
    diceHelper(N, chosen, desiredSum);
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << "diceSum :\n";
    diceSum(N, K);
    cout << "total calls : " << totalcalls << endl;
    return 0;
}
