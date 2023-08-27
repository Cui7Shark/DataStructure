#include<iostream>
#include<queue>
using namespace std;
/**
 * 复杂度
 * time O(n)
 * Space O(h) h:树高度 O(log n)
*/
struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};

void PreOrder(BstNode *root){
    if (root == nullptr) {
        return;
    }
    cout << root->data;
    PreOrder(root->left);
    PreOrder(root->right);

}
void Inorder(BstNode* root) {
    if (root == nullptr) {
        return;
    }
    Inorder(root->left);
    cout << root->data;
    Inorder(root->right);
}
void Postorder(BstNode* root) {
    if (root == nullptr) {
        return;
    }
    Inorder(root->left);
    Inorder(root->right);
    cout << root->data;
}



int main(){
    BstNode* root = nullptr;
    PreOrder(root);

}