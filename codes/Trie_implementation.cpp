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

class Node {
    Node *next[26];
    bool isLeaf = false;
    Node() {
        memset(next, 0, sizeof(next));
    }
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
        }
        current->isLeaf = true;
    }
    //search word in trie
    bool search(string s) {
        Node *current = root;
        for (int i = 0; i < s.length(); ++i) {
            if (current->next[s[i] - 'a'] == 0) {
                return false;    //not found
            }
            current = current->next[s[i] - 'a'];
        }
        if (current->isLeaf == true) {
            return true;
        } else {
            return false;
        }
    }
    //search worl with prefix
    bool startsWith(string s) {
        Node *current = root;
        for (int i = 0; i < s.length(); ++i) {
            if (current->next[s[i] - 'a'] == 0) {
                return false;    //not found
            }
            current = current->next[s[i] - 'a'];
        }
        return true;
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
    // cout << T.search("") << endl;
    return 0;
}
