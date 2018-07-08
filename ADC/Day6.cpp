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

int get_max(vector <int> &A) {
    int max_index = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > A[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

vector <int> redistribute(vector <int> &A) {
    int max_index = get_max(A);
    int amount = A[max_index];
    A[max_index] = 0;
    for (int i = max_index + 1; i > 0; ++i) {
        if (amount == 0) {
            break;
        }
        amount -= 1;
        A[i % A.size()] += 1;
    }
    for (int j = 0; j < A.size(); ++j) {
        cout << A[j] << " ";
    }
    cout << endl;
    return A;
}

int main() {
    int N;
    cin >> N;
    vector <int> A(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    set<vector <int> >S;
    int a = 0, count = 0;
    do {
        a = S.size();
        S.insert(redistribute(A));
        count++;
    } while (S.size() != a);
    cout << count << endl;
    return 0;
}
