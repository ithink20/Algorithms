/*
    author: @vikasc
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <climits>
#include <utility>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int lint;

bool isSafe(vector <vector <int> > &MAZE, int x, int y) {
	int N = MAZE.size();
	if (x >= 0 && y >= 0 && x < N && y < N && MAZE[x][y] == 1) {
		return true;
	}
	return false;
}

bool mazeHelper(vector <vector <int> > &MAZE, int x, int y, vector<vector <int> >&Path) {
	// base case
	int N = Path.size();
	if (x == N - 1 && y == N - 1) {		//destination
		Path[x][y] = 1;
		return true;
	}
	if (isSafe(MAZE, x, y)) {
		//choose
		Path[x][y] = 1;

		// explore
		if (mazeHelper(MAZE, x + 1, y, Path) || 
            mazeHelper(MAZE, x, y + 1, Path) || 
            mazeHelper(MAZE, x - 1, y, Path) || 
            mazeHelper(MAZE, x, y - 1, Path)) {
			return true;
		}
		//unchoose : backtrack
		Path[x][y] = 0;
		return false;
	}
	return false;
}

void solveMaze(vector <vector <int> > &MAZE) {
	int N = MAZE.size();
	vector <vector <int> >Path(N, vector<int> (N, 0));
	if (mazeHelper(MAZE, 0, 0, Path)) {
		// print path
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << Path[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		cout << "No Solution\n";
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector <vector <int> >MAZE(N, vector<int> (N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> MAZE[i][j];
		}
	}
	solveMaze(MAZE);
    return 0;
}
