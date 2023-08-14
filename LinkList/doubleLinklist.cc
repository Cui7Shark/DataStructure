#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *pre;
};
Node* head = nullptr;
Node* getNewnode(int data) {
    Node* newnode = new Node();
    newnode->data = data;
    newnode->next = nullptr;
    newnode->pre = nullptr;
    return newnode;
}
void InserAtHead(int data) {
    Node* temp = getNewnode(data);
    if (head == nullptr) {
        head = temp;
        return;
    }
    head->pre = temp;
    temp->next = head;
    head = temp;
    return;
}
void InserAtTail(int data) {
    Node* newNodePtr = getNewnode(data);
    Node* temp = head;

    if (temp == nullptr){
        head = newNodePtr;
        return;
    }
    
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNodePtr;
    newNodePtr->pre = temp;
    return;

}
void Print() {
    Node* temp = head;
    if (temp == nullptr) return;
    cout << "打印双向链表 : ";
    while (temp != nullptr) {
        
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
        
}
void ReversePrint() {
    Node* temp = head;
    if (temp == nullptr) return;
    cout << "逆序打印双向链表: ";
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->pre;
    }
    cout << endl;
    return;
}
int main()
{
    head = nullptr;
    InserAtHead(2); Print(); ReversePrint();
    InserAtHead(4); Print(); ReversePrint();
    InserAtHead(6); Print(); ReversePrint();
    InserAtHead(8); Print(); ReversePrint();
    InserAtTail(10); Print(); ReversePrint();
    return 0;
}