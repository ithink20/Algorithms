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
const int MARKER = -1;

class node{
    public:
        int data;
        node *left, *right;
};

node *create_node(int data) {
    node *new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

//stores tree in a file.
void serialize(node *root, FILE *fp) {
    if (!root) {
        fprintf(fp, "%d ", MARKER);
        return;
    }
    fprintf(fp, "%d ", root->data);
    serialize(root->left, fp);
    serialize(root->right, fp);
}

void deserialize(node *&root, FILE *fp) {
    int data;
    if (!fscanf(fp, "%d ", &data) || data == MARKER) {
        return;
    }
    root = create_node(data);
    deserialize(root->left, fp);
    deserialize(root->right, fp);
}

void inorder(node *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    node *root               = create_node(20); 
    root->left               = create_node(8); 
    root->right              = create_node(22); 
    root->left->left         = create_node(4); 
    root->left->right        = create_node(12); 
    root->left->right->left  = create_node(10); 
    root->left->right->right = create_node(14);

    FILE *fp = fopen("tree.txt", "w");
    if (fp == NULL) { 
        cerr << "Could not open file" << endl; 
        return 0; 
    }
    serialize(root, fp); 
    fclose(fp);

    node *root1 = NULL; 
    fp = fopen("tree.txt", "r"); 
    deserialize(root1, fp);
    cout << "Inorder : ";
    inorder(root1);
    cout << endl;
    return 0;
}