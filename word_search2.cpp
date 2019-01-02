/*
    author: @vikasc
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;
typedef long long int lint;
#define sq(a) (a) * (a)     //sq(a) a * a   it's not correct, run for sq(2+2)

bool find_helper(vector<vector<char> >&board, int x, int y, string searchfor, int index) {
    if (index == searchfor.length()) { //end condition
        return true;
    }
    if (x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() - 1) {
        return false;
    }
    if (board[x][y] != searchfor[index]) { //do not match
        return false;
    }
    // DFS + Backtracking
    //choose
    char ch = board[x][y];
    board[x][y] = ' ';              //mark it to visited.
    //explore
    bool ans = (
    find_helper(board, x + 1, y, searchfor, index + 1) ||   //up
    find_helper(board, x - 1, y, searchfor, index + 1) ||   //down
    find_helper(board, x, y + 1, searchfor, index + 1) ||   //right
    find_helper(board, x, y - 1, searchfor, index + 1) );   //left
    //unchoose
    board[x][y] = ch;
    return ans;
}

bool find_word(vector<vector<char> >&board, string searchfor) {
    for (int x = 0; x < board.size(); ++x) {
        for (int y = 0; y < board[0].size(); ++y) {
            if (find_helper(board, x, y, searchfor, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    int Q;
    cin >> Q;
    string searchfor;
    while (Q--) {
        cin >> searchfor;
        cout << find_word(board, searchfor) << endl;
    }
    return 0;
}
