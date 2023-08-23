#include<iostream>                  
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* front = nullptr;
Node* rear = nullptr;
bool Empty();
void Enqueue(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    if (front == nullptr && rear == nullptr) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void Dequeue() {
    Node* temp;
    temp = front;
    if (front == nullptr){
        cout << "Can't pop num" << endl;
        return;
    } 
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = temp->next;
    }
        delete temp;
}
int Front() {
    if (!Empty()) {
        int num = front->data;
        return num;
    }else {
        cout << "queue is NULL" << endl;
        return 0;
    }
}
bool Empty() {
    if (front == rear) {
        cout << "yes , it is empty" << endl;
        return true;
    } else {
        cout << "No, it has some numbers" << endl;
        return false;
    }
}
void Print() {
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
int main() {
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Print();
    Dequeue();
    Empty();
    Print();
    Dequeue();
    Print();
    Dequeue();
    Print();
    Dequeue();
    Print();
    Dequeue();
    Print();
    return 0;
}       
