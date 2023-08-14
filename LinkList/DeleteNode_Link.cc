#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head;
//头插法
void Insert(int num) {
    Node* temp = new Node();
    temp->data = num;
    temp->next = nullptr;
    if (head != nullptr) {
        temp->next = head;
    }
    head = temp;
    return;
}
void Delate(int n) {
    Node* temp1 = head;
    if (n == 1) {
        head = temp1->next;
        delete temp1;
        return;
    }
    
    /*让temp1 指向 第 n-1 个节点位置 （i<=n-2） ,
    又因为 temp1 本身指向第1个节点 所以 i<n-2*/

    for (int i = 0; i< n-2; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next; // temp2指向第n个节点

    temp1->next = temp2->next; // 第n-1个节点指向第n+1 个节点
    //删除第n个节点
    delete temp2;
    return;
    
}
void Print() {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
int main()
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Print();
    cout << "Delete ? node:";
    int n;
    cin >> n;
    Delate(n);
    Print();
    return 0;
}