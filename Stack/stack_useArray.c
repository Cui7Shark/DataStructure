#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 101
int top = -1;
int Stack[MAX_SIZE];

void push(int x) {
    if (top == MAX_SIZE-1) {
        printf("push() error \n");
        return;
    }
    Stack[++top] = x;

} 
void pop() {
    if (top == 0) {
        perror("pop()");
        return;
    }
    top--;
}

void Top () {
    if (top == -1) {
        perror("Top()");
        return;
    }
    printf("Top of Stack is: %d\n", Stack[top]);
    
}

void print() {
    int i = 0;
    printf("Stack is : ");
    for (i; i <= top; ++i) {
        printf("%d ", Stack[i]);
    }
    printf("\n");
}


int main() {
    push(2);
    print();
    push(4);
    print();
    push(5);
    print();
    pop();
    print();
    Top();
    for (int i = 0; i < 102; i++) {
        push(i);
        //print();
    }
    print();
    return 0;
}