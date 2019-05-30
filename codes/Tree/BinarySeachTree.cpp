/*
    @author: vikasc
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *root = NULL;

node *GetNewnode(int data) {
    node *t = new node();
    t -> data = data;
    t -> left = t -> right = NULL;
    return t;
}

node* insert(node *root, int data) {
    if (root == NULL) {
        root = GetNewnode(data);
    } else if (data <= root -> data) {
        root -> left = insert(root -> left, data);
    } else {
        root -> right = insert(root -> right, data);
    }
    return root;
}

void display(node *root) {              // pre-order traversal
    if (root) {
        cout << root -> data << " ";
        display(root -> left);
        display(root -> right);
    }    
}

/* void display(node *root) {          // inorder traversal
    if (root) {
        display(root -> left);
        cout << root -> data << " ";
        display(root -> right);
    }
} */

/* void display(node *root) {          // post-order traversal
    if (root) {
        display(root -> left);
        display(root -> right);
        cout << root -> data << " ";
    }
}
*/

int height(node *root) {        // or maxDepth of tree.
    if (root == NULL) {
        return 0;
    }
    return 1 + max(height(root -> left), height(root -> right));
}

void levelOrderTraversal(node *root) {
    queue <node* > Q;
    while (root) {
        cout << root -> data << " ";
        if (root -> left) {
            Q.push(root -> left);
        }
        if (root -> right) {
            Q.push(root -> right);
        }
        if (!Q.empty()) {
            root = Q.front();
        } else {
            try {
                if (Q.empty())
                    throw 0;
            }
            catch(int a) {return;}
        }
        Q.pop();
    }
    return;
}

void levelBylevel(node *root) {
	if (root == NULL) return;
	queue<node *> Q;
	node *current;
	Q.push(root);
	Q.push(NULL);
	while (Q.size() > 1) { //1 delimeter is NULL
		current = Q.front();
		Q.pop();
		if (current == NULL) {
			Q.push(NULL);
			cout << endl;
		} else {
			if (current -> left) {
				Q.push(current->left);
			}
			if (current -> right) {
				Q.push(current->right);
			}
			cout << current->data << " ";
		}
	}
}

int main() {
    int N, data;
    cin >> N;
    while (N--) {
        cin >> data;
        root = insert(root, data);
    }
    display(root);
    cout << endl;
    cout << height(root) << endl;
    levelOrderTraversal(root);
    cout << endl;
	levelBylevel(root);
	cout << endl;
	return 0;
}
