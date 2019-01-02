/*
    author: @vikasc
    problem: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/dummy4-2/
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
    //this is startsWith prefix search;
    int search(string s) {
        Node *current = root;
        for (int i = 0; i < s.length(); ++i) {
            if (current->next[s[i] - 'a'] == 0) {
                return false;    //not found
            }
            current = current->next[s[i] - 'a'];
        }
        return current->value;
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
