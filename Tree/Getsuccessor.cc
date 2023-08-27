#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
// 寻找中序遍历的后继节点
Node *Find(Node *root, int data)
{
    if (root == nullptr)
        return nullptr;
    else if (data < root->data)
    {
        return Find(root->left, data);
    }
    else if (data > root->data)
    {
        return Find(root->right, data);
    }
    else
        return root;
}
Node* FindMin(Node* root) 
{
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) 
    {
        root = root->left;
    }
    return root;
}

/**BST
 *       10
 *       / \
 *      8   14
 *     / \    \
 *    5   9    16
 * 
 * Inorder : 5 8 9 10 14 16
 * O(log n)  time 
*/ 
// 一个节点 如果
// 1 有右子树， 它的中序遍历后继节点就是右子树中的最小值(位于右子树最左边的叶子节点)；
// 2 没有右子树
//          1》给定节点在祖先的左子树，它的祖先是它的后继，
//          2》给定节点在祖先的右子树，它祖先的祖先是它的后继
Node *getsuccessor(Node *root, int data)
{
    Node *current = Find(root, data);
    if (current == nullptr) return nullptr;
    //case 1 : Node has right subtree
    if (current->right != nullptr) {
        return FindMin(current->right);
    }
    // case 2 : No right subtree
    else {
        Node* successor = nullptr;
        Node* ancestor = root;
        while (ancestor != current) 
        {
            //给定节点在祖先的左子树
            if (current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            //给定节点在祖先的右子树
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}