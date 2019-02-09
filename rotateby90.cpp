/*
	@author : vikasc
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

void rotateby90(vector<vector<int> >&matrix) {
	//m[0][0] -> m[0][3]	//m[0][1] -> m[1][3]
	//m[0][3] -> m[3][3]	//m[1][3] -> m[3][2]
	//m[3][3] -> m[3][0]	//m[3][2] -> m[2][0]
	//m[3][0] -> m[0][0]	//m[2][0] -> m[0][1]

	//m[x][y]     		->  m[y][n-1-x]
	//m[y][n-1-x]   	->  m[n-1-x][n-1-y]
	//m[n-1-x][n-1-y] 	->  m[n-1-y][x]
	//m[n-1-y][x]   	->  m[x][y]
	int temp = 0;
	int N = matrix.size();
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N - i - 1; ++j) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[N - 1 - j][i];
			matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
			matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
			matrix[j][N - 1 - i] = temp;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<vector<int> > matrix(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
		}
	}
	rotateby90(matrix);
	return 0;
}