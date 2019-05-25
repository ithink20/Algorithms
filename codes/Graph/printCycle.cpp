#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#include <utility>

using namespace std;

int k = 0;

int DFS(vector< vector <int> > &A, vector <bool> &visited, vector <int> &path, int &start, int parent) {
    
    visited[start] = true;
    vector <int> :: iterator i;
    for (i = A[start].begin(); i != A[start].end(); ++i) {
    	if (!visited[*i]) {
    		int res = DFS(A, visited, path, *i, start);
    		if (res == -1) {
    			return -1;
    		} else if (res != -2) {
    			path[k++] = start;
    			if (res == start) {
    				return -1;
    			} else {
    				return res;
    			}
    		}
    	} else if (*i != parent) {
    		path[k++] = start;
    		return *i;
    	}
    }
    return -2;
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
    int start = 1;
    vector <bool> visited(N, false);
    vector <int> path(N, -1);
    DFS(A, visited, path, start, -1);
	int l = 0;
    int count = 0;
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] == -1) {
            break;
        } else {
            count++;
        }
    }
    if (count > 1) {
        cout << "cycle at : ";
    	while (path[l] != -1 && l < N) {
    		cout << path[l++] << " ";
    	}
    	cout << endl;
    } else {
        cout << "No cycle found\n";
    }
    return 0;
}