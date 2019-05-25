#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <vector>
#include <set>
#include <climits>
#include <map>
#include <string>
#include <cstdio>
#include <time.h>

using namespace std;

typedef long long int lint;

int totalsolutions = 0;

void print(vector < vector <int> >&board, int N) {
	totalsolutions++;
	// for (int i = 0; i < N; ++i) {
	// 	for (int j = 0; j < N; ++j) {
	// 		if (board[i][j] == 1) {
	// 			cout << "Q ";
	// 		} else {
	// 			cout << "_ ";
	// 		}
	// 	}
	// 	cout << endl;
	// }
}

bool isSafe(int row, int col, vector < vector <int> >&slash, vector < vector <int> >&backslash, 
			vector <bool> &checkrow, vector <bool> &checkslash, vector <bool> &checkbackslash) {

	if (checkslash[slash[row][col]] || checkbackslash[backslash[row][col]] || checkrow[row]) {
		return false;
	}
	return true;
}


bool N_queens_helper(vector < vector <int> >&board, int col, vector < vector <int> >&slash, 
					vector < vector <int> >&backslash, vector <bool> &checkrow, 
					vector <bool> &checkslash, vector <bool> &checkbackslash, int N) {

	//base case
	if (col == N) {
		print(board, N);
		//cout << endl << endl;
		return false;
	}

	for (int i = 0; i < N; ++i) {
		if (isSafe(i, col, slash, backslash, checkrow, checkslash, checkbackslash)) {
			//place queen
			board[i][col] = 1;
			checkrow[i] = true;
			checkslash[slash[i][col]] = true;
			checkbackslash[backslash[i][col]] = true;

			//explore rest
			if (N_queens_helper(board, col + 1, slash, backslash, checkrow, checkslash, checkbackslash, N)) {
				return true;
			}

			//backtrack
			board[i][col] = 0;
			checkrow[i] = false;
			checkslash[slash[i][col]] = false;
			checkbackslash[backslash[i][col]] = false;
		}
	}
	return false;
}

void N_queens(int N) {
	vector < vector <int> >board(N, vector <int> (N, 0));

	vector < vector <int> >slash(N, vector <int> (N, 0));
	vector < vector <int> >backslash(N, vector <int> (N, 0));

	vector <bool>checkrow(N, false);
	vector <bool>checkslash(2* N - 1, false);
	vector <bool>checkbackslash(2* N - 1, false);

	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			slash[row][col] = row + col;
			backslash[row][col] = row - col + N - 1;
		}
	}
	N_queens_helper(board, 0, slash, backslash, checkrow, checkslash, checkbackslash, N);
}

int main() {
	clock_t tstart = clock();
    int N;
    cin >> N;
    N_queens(N);
    cout << "Total solutions : " << totalsolutions << endl;
    printf("Time taken : %.2fs\n", (double)(clock() - tstart)/CLOCKS_PER_SEC);
    return 0;
}