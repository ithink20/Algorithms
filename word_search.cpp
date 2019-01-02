/*
    author: @vikasc
    problem: https://leetcode.com/problems/word-search-ii/
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

class Node {
public:
    Node *next[26];     //alphabets
    int value = 0;
    bool isLeaf = false;
};

class Trie {
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    //insert word into Trie
    void insert(string s) {
        Node *current = root;
        if (s.length() == 0) return;
        for (int i = 0; i < s.length(); ++i) {
            if (current->next[s[i] - 'a'] == 0) {
                current->next[s[i] - 'a'] = new Node();
            }
            current = current->next[s[i] - 'a'];
            current->value += 1;
        }
        current->isLeaf = true;
    }
    bool search_helper(string s, int index, Node* current) {
        if (index == s.length()) {
            return current->isLeaf;
        }
        if (s[index] == '.') {
            bool result = false;
            for (int i = 0; i < 26; ++i) {
                if (current->next[i] != 0) {
                    result = result || search_helper(s, index + 1, current->next[i]);
                }
            }
            return result;
        } else {
            if (current->next[s[index] - 'a'] == 0) {
                return false;
            }
            return search_helper(s, index + 1, current->next[s[index] - 'a']);
        }
    }
    //search with '.' char: means any-one char per dot
    bool search(string s) {
        Node *current = root;
        return search_helper(s, 0, current);
    }
    vector<string> find_words(vector<vector<char> >&board) {
        set<string> result_set;
        Node *current = root;
        for (int x = 0; x < board.size(); ++x) {
            for (int y = 0; y < board[0].size(); ++y) {
                find_helper(board, x, y, current, "", result_set);
            }
        }
        vector<string> result;
        for (auto it : result_set) {
            result.push_back(it);
        }
        return result;
    }
    void find_helper(vector<vector<char> >&board, int x, int y, Node *current, string word, set<string> &result) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board.size() || board[x][y] == ' ') {
            return;
        }
        if (current->next[board[x][y] - 'a'] != 0) {
            word += board[x][y];
            current = current->next[board[x][y] - 'a'];
            if (current->isLeaf) {
                result.insert(word);
            }
            //choose
            char ch = board[x][y];
            //explore
            board[x][y] = ' ';
            find_helper(board, x + 1, y, current, word, result);
            find_helper(board, x - 1, y, current, word, result);
            find_helper(board, x, y + 1, current, word, result);
            find_helper(board, x, y - 1, current, word, result);
            //unchoose
            board[x][y] = ch;
        }
    }
};

int main() {
    int N;
    cin >> N;
    string str;
    Trie T;
    for (int i = 0; i < N; ++i) {
        cin >> str;
        T.insert(str);
    }
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    vector<string> words = T.find_words(board);
    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << " ";
    }
    cout << endl;
    return 0;
}
