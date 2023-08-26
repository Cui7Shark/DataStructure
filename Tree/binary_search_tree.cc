#include<iostream>

using namespace std;

struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode* GetNewNode(int n) {
    BstNode *newNode = new BstNode();
    newNode->data = n;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
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
// 在树上查找data
bool Search(BstNode* root, int data) {
    if (root == nullptr) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}
int main() {
    BstNode *root = nullptr; // 这是一颗空树
    int num;
    cout << "Enter number be searched\n";
    cin >> num;
    
    root = Insert(root, 15);
    root = Insert(root, 13);
    root = Insert(root, 2);
    if (Search(root, num) == true) 
        cout << "Found\n";
    else 
        cout << "Not Found\n";
}