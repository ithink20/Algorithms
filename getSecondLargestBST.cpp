#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef long long int lint;

// uncomment line below to enable debugging
// #define ENABLE_DEBUGGING

#if defined(ENABLE_DEBUGGING) || defined(DDD)
#define SOURCE_INFO_COUT "[" << __FUNCTION__ <<  "():" << __LINE__ << "] "
#define debug_print0(...) do { cout << SOURCE_INFO_COUT << #__VA_ARGS__ << endl; } while (0)
#define debug_print1(x) do { cout << SOURCE_INFO_COUT << #x "::" << x << endl; } while (0)
#define debug_print2(x, y) do { cout << SOURCE_INFO_COUT << #x "::" << x << ", " #y "::" << y << endl; } while (0)
#define debug_print3(x, y, z) do { cout << SOURCE_INFO_COUT << #x "::" << x << ", " #y "::" << y << ", " #z "::" << z << endl; } while (0)
#define debug_print4(x, y, z, z1) do { cout << SOURCE_INFO_COUT << #x "::" << x << ", " #y "::" << y << ", " #z "::" << z << ", " #z1 "::" << z1 << endl; } while (0)
#else
#define debug_print0(...)
#define debug_print1(x)
#define debug_print2(x, y)
#define debug_print3(x, y, z)
#define debug_print4(x, y, z, z1)
#endif


// This is an O(h) time and O(h) space, h: height of tree.
class BinaryTreeNode {
public:
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
    BinaryTreeNode * insertLeft(int value) {
        this->left = new BinaryTreeNode(value);
        return this->left;
    }
    BinaryTreeNode * insertRight(int value) {
        this->right = new BinaryTreeNode(value);
        return this->right;
    }
    int getLargest(const BinaryTreeNode* root) {
        if (root->right) {
            return getLargest(root->right);
        }
        return root->value;
    }
    int getSecondLargest(const BinaryTreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            throw invalid_argument("Tree must have at least 2 nodes");
        }
        //case: currently at largest node and this node has a left subtree.
        //so second largest will be the largest node in that left subtree.
        if (root->left && (!root->righ)) {
            return getLargest(root->left);
        }
        // case: we're at parent of largest, and largest has no left subtree,
        // so 2nd largest must be current node
        if (root->right && (!root->right->left) && (!root->right->right)) {
            return root->value;
        }
        return getSecondLargest(root->right);
    }
};

//But h space in the call stack is avoidable.
class BinaryTreeNode {
public:
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
    BinaryTreeNode * insertLeft(int value) {
        this->left = new BinaryTreeNode(value);
        return this->left;
    }
    BinaryTreeNode * insertRight(int value) {
        this->right = new BinaryTreeNode(value);
        return this->right;
    }
    int getLargest(const BinaryTreeNode* root) {
        const BinaryTreeNode *current = root;
        const BinaryTreeNode *largest = nullptr;

        while (current) {
            if (!current->right) {
                largest = current;
            }
            current = current->right;
        }
        return largest->value;
    }
    int getSecondLargest(const BinaryTreeNode* root) {
        if (!root || (!root->left && !root->right)) {
            throw invalid_argument("Tree must have at least 2 nodes");
        }
        const BinaryTreeNode *current = root;
        while (1) {
             // case: current is largest and has a left subtree
             // 2nd largest is the largest in that subtree
             if (current->left && !current->right) {
                 return getLargest(current->left);
             }
             // case: current is parent of largest, and largest has no children,
             // so current is 2nd largest
             if (current->right && !current->right->left && !current->right->right) {
                 break;
             }
             //move to right
             current = current->right;
        }
        return current->value;
    }
};
/* We're doing one walk down our BST, which means O(h) time, where h is the height of the tree
 * (again, that's O(lgn) if the tree is balanced, O(n) otherwise. O(1) space.
 */
