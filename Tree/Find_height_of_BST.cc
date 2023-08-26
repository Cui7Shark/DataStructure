#include<iostream>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

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

int FindHeight(BstNode* root) {
    // 递归的退出条件
    if (root == nullptr) {
        return -1;
        //空节点的高度为-1
    }
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
    // 我们定义只有一个节点的树的高度为0 ；
    // 递归返回时，结果值+1 为当前节点的高度
}

int main() {
    BstNode* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 13);
    root = Insert(root, 2);

    /**  二叉搜索树 -- left < mid <right
     *     15
     *     /
     *    13
     *    /
     *   2
     * height = 2
    */
    int height = FindHeight(root);
    cout << height << endl;
    return 0;
}