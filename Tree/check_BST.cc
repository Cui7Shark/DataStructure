#include <iostream>
#include <climits>
using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    bool IsBstUtil(Node *root, int minValue, int maxValue)
    {
        if (root == nullptr)
            return true;
        if (root->data < maxValue && root->data > minValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, root->data, maxValue))
            return true;
        else
            return false;
    }

    bool IsBinarySearchTree(Node *root)
    {
        return IsBstUtil(root, INT_MAX, INT_MAX);
    }
    // 创建一个新节点
    Node *GetNewNode(int n)
    {
        Node *newNode = new Node();
        newNode->data = n;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    // 插入一个新节点
    Node *Insert(Node *root, int n)
    {
        if (root == nullptr)
        {
            root = GetNewNode(n);
        }
        else if (n <= root->data)
        {
            root->left = Insert(root->left, n);
        }
        else
        {
            root->right = Insert(root->right, n);
        }
        return root;
    }
};
int main()
{
    Node* root = nullptr;
    root->Insert(root, 10);
    root->Insert(root, 19);
    root->Insert(root, 4);
    if (root->IsBinarySearchTree(root)) 
        cout << "true" << endl;
    else 
        cout << false << endl;
     

}