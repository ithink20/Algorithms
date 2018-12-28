// problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1869

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <utility>
#include <map>
#include <vector>
#include <set>
#include <list>

using namespace std;
typedef long long int lint;
#define sq(a) (a) * (a)     //sq(a) a * a   it's not correct, run for sq(2+2)

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int Places;
        cin >> Places;
        string line;
        getline(cin, line);      //consume the endline
        list <int> neighbor_count;
        int min_neighbor = -1;
        for (int i = 0; i < Places; ++i) {
            getline(cin, line);
            int count_neighbors = 1;
            for (int j = 0; j < line.length(); ++j) {
                if (line[j] == ' ') {
                    count_neighbors += 1;
                }
            }
            neighbor_count.push_back(count_neighbors);
            if (i == 0) {
                min_neighbor = count_neighbors;
            } else {
                min_neighbor = min(min_neighbor, count_neighbors);
            }
        }
        int index = 1;
        bool isprinted = false;
        for (list<int> :: iterator it = neighbor_count.begin(); it != neighbor_count.end(); ++it) {
            if (*it == min_neighbor) {
                if (isprinted) {
                    cout << " ";
                }
                else {
                    isprinted = true;
                }
                cout << index;
            }
            index += 1;
        }
        cout << endl;
    }
    return 0;
}
