#include<iostream>
using namespace std;
struct Node
{
    /* data */
    int data;
    Node* next;
};
void Insert (Node** head, int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = *head;
    *head = temp;
    //delete temp; 不需要
    return;
}
void Print(Node* head) {
    Node* temp = head;
    cout << "List is: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
int main()
{   
    Node* head = nullptr;
    cout << "How many numbers?" << endl;
    int n, x;
    cin >> n;
    for (int i = 0; i<n; i++){
        cout << "Enter number: " << endl;
        cin >> x;
        Insert(&head, x);
        
        Print(head);
    }
}
