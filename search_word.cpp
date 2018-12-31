/*
    @author: vikaschaurasiya
    problem: https://leetcode.com/problems/add-and-search-word-data-structure-design/
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
};

int main() {
    int N, Q;
    cin >> N >> Q;
    string str;
    Trie T;
    for (int i = 0; i < N; ++i) {
        cin >> str;
        T.insert(str);
    }
    while (Q--) {
        cin >> str;
        cout << T.search(str) << endl;
    }
    return 0;
}
