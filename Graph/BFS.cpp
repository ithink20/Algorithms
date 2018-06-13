#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(vector< vector<int> > A, int start, int N, int *levels) {
    int flag = 0, k = 0;
    queue <int> Q;
    vector<bool> visited(N, false);
    visited[start] = true;
    Q.push(start);
    while (!Q.empty()) {
        int z = Q.front();
        cout << z << " ";
        Q.pop();
        vector<int> :: iterator i;
        if (z == start) {
            levels[z] = 0;
        }
        for ( i = A[z].begin(); i != A[z].end(); ++i) {
            if (visited[*i] == false) {
                visited[*i] = true;
                Q.push(*i);
                levels[*i] = levels[z] + 1;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector< vector<int> > A(10);
    int u, v, m;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        m = max(u, v);
        A[u].push_back(v);
        A[v].push_back(u);
    }
    // cout << endl;
    // for (int i = 0; i <= m; ++i) {
    //     for (int j = 0; j < A[i].size(); ++j) {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int levels[m + 1];
    for (int i = 0; i <= m; ++i) {
        levels[i] = 0;
    }
    int start;
    cout << "Enter start vertex: ";
    cin >> start;
    BFS(A, start, N, levels);
    cout << endl;
    for (int i = 0; i <= m; ++i) {
        cout << levels[i] << " ";
    }
    return 0;
}