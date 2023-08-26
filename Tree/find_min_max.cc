/**
 * 搜索二叉搜索树中最小值和最大值
*/

#include<iostream>
using namespace std;
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

/*迭代方法*/
//寻找最小值
int FindMin(BstNode* root) {
    if (root == nullptr) {
        cout << "Error : tree is empty" << endl;
        return -1;
    }
    while (root->left) {
        root = root->left;
    }
    return root->data;
}
//寻找最大值
int FindMax(BstNode* root) {
    if (root == nullptr) {
        cout << "Error : tree is empty" << endl;
        return -1;
    }
    while (root->right) {
        root = root->right;
    }
    return root->data;
}
/*递归方法*/
 int FindMin_cur(BstNode* root) {
    if (root == nullptr) {
        cout << "Error : tree is empty" << endl;
        return -1;
    }
    else if (root->left == nullptr) {
        return root->data;
    }
    return FindMin_cur(root->left);
 }
 int FindMax_cur(BstNode* root) {
    if (root == nullptr) {
        cout << "Error : tree is empty" << endl;
        return -1;
    }
    else if (root->right == nullptr) {
        return root->data;
    }
    return FindMax_cur(root->right);
 }

//创建一个新节点
BstNode* GetNewNode(int n) {
    BstNode *newNode = new BstNode();
    newNode->data = n;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
//插入一个新节点
BstNode* Insert(BstNode *root, int n) {
   if (root == nullptr) {
        root = GetNewNode(n);
   }
   else if (n <= root->data) {
        root->left = Insert(root->left, n);
   }else {
        root->right = Insert(root->right, n);
   }
   return root;

}
int main() {
    BstNode* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 13);
    root = Insert(root, 2);
    int min, min_2;
    int max, max_2;
    min = FindMin_cur(root);
    max = FindMax_cur(root);
    min_2 = FindMin(root);
    max_2 = FindMax(root);
    cout << min << '\n';
    cout << min_2 << endl;
    cout << max << endl;
    cout << max_2 << endl;
    return 0;
}
