/*
 * @author: vikasc
 */

#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <climits>

typedef long long int lint;
using namespace std;

class node {
    public:
        int data;
        node *left, *right;
};

node *create_node(int data) {
    node *new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
}

bool isIdentical(node *tree1, node *tree2) {
    //Case 1: if both empty
    if (tree1 == NULL && tree2 == NULL) {
        return true;
    }
    //case 2: it both no-empty, compare
    if (tree1 != NULL && tree2 != NULL) {
        return (tree1->data == tree2->data
                && isIdentical(tree1->left, tree2->left)
                && isIdentical(tree1->right, tree2->right));
    }
    return false;
}

int main() {
    node *root1 = create_node(1);  
    root1->left = create_node(2);  
    root1->right = create_node(3);  
    root1->left->left = create_node(4);  
    root1->left->right = create_node(5);  
    
    node *root2 = create_node(1);
    root2->left = create_node(2);  
    root2->right = create_node(3);  
    root2->left->left = create_node(4);  
    root2->left->right = create_node(5);

    (isIdentical(root1, root2) ? cout << "Identical\n" : cout << "Non-Identical\n");
    return 0;
}