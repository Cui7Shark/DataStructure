#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;
void push(int x) {
    Node* temp = (Node*) malloc(sizeof(Node*));
    temp->data = x;
    temp->next = top;

    top = temp;
}

void pop() {
    if (top == NULL) {
        printf ("Stack is empty, you can not pop a number!\n");
        return;
    }
    Node* temp;
    temp = top;
    top = top->next;
    free(temp);
}
void Print() {
    printf("Stack is : ");
    Node* temp;
    temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void isempty() {
    if (top == NULL) {
        printf ("YES\n");
        //return true;
    }
    printf("NO\n");
    //return false;
}

int main() {
    push(1);
    push(4);
    push(3);
    Print();
    pop();
    
    printf("stack is empty, YES or NO ?: ");
    isempty();
    Print();
    return 0;
}
