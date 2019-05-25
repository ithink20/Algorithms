/*
	@author : vikasc
	problem : Construct Tree from given Inorder and Preorder traversals
	TimeComplexity : O(n)
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <climits>
#include <utility>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int lint;

struct node {
	char data;
	node *left, *right;
};

node *__newNode(char data) {
	node *t = new node;
	t->data = data;
	t->left = t->right = NULL;
	return t;
}

node *__tree_helper(char *inorder, char *preorder, int start, int end, unordered_map<char, int> &M) {
	static int pre_index = 0;
	if (start > end) {
		return NULL;
	}
	//pick node from preorder.
	char current = preorder[pre_index++];
	node *new_node = __newNode(current);
	
	//if node has no children
	if (start == end) {
		return new_node;
	}
	//find index of current in inorder.
	int index = M[current]; //search here in O(1) using map otherwise search will be in O(n)
	new_node->left = __tree_helper(inorder, preorder, start, index - 1, M);
	new_node->right = __tree_helper(inorder, preorder, index + 1, end, M);
	return new_node;
}

node *__buildTree(char *inorder, char *preorder, int N) {
	unordered_map<char, int> M;
	for (int i = 0; i < N; ++i) {
		M[inorder[i]] = i;
	}
	return __tree_helper(inorder, preorder, 0, N - 1, M);
}

void __display_inorder(node *root) {
	if (!root) return;
	__display_inorder(root->left);
	cout << root->data << " ";
	__display_inorder(root->right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char inorder[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char preoder[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int N = sizeof(inorder) / sizeof(inorder[0]);
	node *root = __buildTree(inorder, preoder, N);
	__display_inorder(root);
	cout << endl;
	return 0;
}