/*用递归方法反转链表*/

#include<iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node* next;
};

void Print(Node* head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
Node *Insert(Node *head, int data) {
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;
    if (head == nullptr){
        head = temp1;
    }else {
        Node *temp2 = head;
        while(temp2->next != nullptr) {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
    return head;
}
void Reverse(Node* p, Node* &head) {
    if (p->next == nullptr) {
        head = p;
        return;
    }
    Reverse(p->next, head);
    Node *q = p->next;
    q->next = p;
    p->next = nullptr;

}
int main()
{
    Node *head = nullptr;
    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);
    Print(head);
    cout << "Now List is : " << endl;
    Reverse(head, head);
    Print(head);
    return 0;

}