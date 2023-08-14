/*递归调用打印函数， 实现链表的逆序打印， 但链表本身无变化*/
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
//递归调用打印
void Print(Node *p) {
    if (p == NULL) return;
    Print(p->next);
    cout << p->data << " ";
}
//尾插法
Node *Insert(Node *head, int num) {
    Node *temp = new Node();
    temp->data = num;
    temp->next = nullptr;
    if (head == nullptr) head = temp;
    else {
        Node* temp2 = head;
        while (temp2->next != NULL) temp2 = temp2->next;
        temp2->next = temp;
    }
    return head;
}
int main()
{   
    Node *head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);
    head = Insert(head, 5);
    Print(head);
    return 0;
}