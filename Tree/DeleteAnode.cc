#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};


Node* Findmin(Node* root) {
    if (root == nullptr){
        return nullptr;
    }
    else if (root->left == nullptr){
        return root;
    }
    return Findmin(root->left);
}
Node* Delete(Node *root, int data)
{
    if (root == nullptr)
        return nullptr;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        // case1:No child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        // case2:one child
        else if (root->left == nullptr)
        {
            Node *tmp = root;
            root = root->right;
            delete tmp;
        }
        else if (root->right == nullptr)
        {
            Node *tmp = root;
            root = root->left;
            delete tmp;
        }
        // case3: two child
        else
        {
            // 在当前节点的右子树中找最小值作为替代品
            Node *tmp = Findmin(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, data);
        }
    }
    return root;
}

int main()
{
    Node *root = nullptr;
    // root = Insert(root, 15);
    // root = Insert(root, 13);
    // root = Insert(root, 2);
    // root = Insert(root, 14);
    // root = Insert(root, 2);
    // root = Insert(root, 11);
    int data = 11;
    // 二叉树的创建省略
    Delete(root, data);
}