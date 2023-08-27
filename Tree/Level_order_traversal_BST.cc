/**
 * BST
 * 层序遍历
*/
#include<iostream>
#include<queue>
using namespace std;

struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode* getNewNode(BstNode* root, int data) {
        BstNode* newNode = new BstNode();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
}
BstNode* Insert(BstNode* root, int data) {
    if (root == nullptr) {
        root = getNewNode(root, data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

void level_order(BstNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<BstNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        //队列不为空时，取出出口的节点，打印数据，在将其pop之前，压入其左右孩子节点
        BstNode* current = Q.front();
        cout << current->data << " ";
        if (current->left) Q.push(current->left);
        if (current->right) Q.push(current->right);
        Q.pop();
    }
    cout << endl;

}

/**      BST
 *       10
 *       / \
 *      8   14
 *     / \    \
 *    5   9    16
 * 
 * print : 10 8 14 5 9 16
 * 
 * 5 8 9 10 14 16
*/ 
int main() {
    BstNode *root = nullptr;
    root = Insert(root, 10);
    root = Insert(root, 8);
    root = Insert(root, 14);
    root = Insert(root, 5);
    root = Insert(root, 16);
    root = Insert(root, 9);
    level_order(root);
    return 0;
}
