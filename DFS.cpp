#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector< vector <int> > &A, int &start, int &N) {
    stack<int> S;
    vector <bool> visited(N, false);
    S.push(start);
    while (!S.empty()) {
        int z = S.top();
        S.pop();
        if (!visited[z]) {
            cout << z << " ";
            visited[z] = true;
        }
        vector<int> :: iterator i = A[z].begin();
        while (i != A[z].end()) {
            if (visited[*i] == false) {
                S.push(*i);
            }
            ++i;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > A(N + 1);
    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    cout << endl;
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    int start;
    cin >> start;
    DFS(A, start, N);
    return 0;
}