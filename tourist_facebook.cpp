#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <fstream>

using namespace std;
typedef long long int lint;

int main() {
    freopen("/Users/vikaschaurasiya/Desktop/tourist.txt", "r", stdin);
    freopen("/Users/vikaschaurasiya/Desktop/ans.txt", "w", stdout);
    int tt;
    cin >> tt;
    for (int l = 0; l < tt; ++l) {
        cout << "Case #" << l + 1 << ": ";
        lint N, K, V;
        cin >> N >> K >> V;
        vector <pair<int, string> >S(N, make_pair(0, ""));
        getchar();      //handle newline character;
        for (int i = 0; i < N; ++i) {
            getline(cin, S[i].second);
            S[i].first = i;
        }
        lint p;
        if ((K * V - K) == 0 || (K * V - K) == N) {     //special
            p = 0;
        } else if (N < (K * V - K)) {
            p = (K * V - K) % N;
        } else if (N > (K * V - K)) {
            lint q = N / (K * V - K);
            p = q * (K * (V - 1) - 1);
        }
        //cout << p << endl;
        vector <pair<int, string> >temp(K, make_pair(0, ""));
        int size = 0;
        for (lint i = p; ; ++i) {
            if (K == 0) {
                break;
            }
            K -= 1;
            temp[size].first = S[i % N].first;
            temp[size++].second = S[i % N].second;
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); ++i) {
            cout << temp[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}
