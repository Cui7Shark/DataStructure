/*使用迭代法反转链表*/

#include<iostream>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node* next;
};
//头插法
Node *Insert(Node *head, int num)
{   
    Node *temp = new Node();
    temp->data = num;
    temp->next = nullptr;
    temp->next = head;
    head = temp;
    return head;
}
void Print(Node *head) 
{
    Node *temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    return;
}
Node *Reverse(Node* head)
{
    Node *current, *pre, *next;
    pre = nullptr;
    current = head;
    
    while (current != nullptr) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;
    return head;
}
int main()
{
    Node *head = nullptr;
    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);
    // 4 3 2 1
    Print(head);
    head = Reverse(head);
    Print(head);
    // 1 2 3 4
    return 0;
}