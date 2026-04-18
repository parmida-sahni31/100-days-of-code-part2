// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <stdio.h>
#define MAX 5

struct stack{
    int top;
    int arr[MAX];
};

int isEmpty(struct stack *s){
    return s->top==-1;
}

int isFull(struct stack *s){
    return s->top== MAX -1;
}

void push(struct stack *s, int data){
    if(isFull(s)){
        printf("stack overflow!");
        return;
    }

    s->top++;
    s->arr[s->top]= data;
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow!");
        return -1;
    }

    int val=  s->arr[s->top];
    s->top--;
    return val;
}

void display(struct stack *s){
    if(isEmpty(s)){
        printf("stack is empty.");
        return;
    }

    for(int i=0; i<=s->top; i++){
        printf("%d\n", s->arr[i]);
    }
}

int main(){
    struct stack s;
    s.top= -1;
    int n, m;

    scanf("%d", &n);
    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        push(&s, arr[i]);
    }

    scanf("%d", &m);

    for(int i=0; i<m; i++){
        pop(&s);
    }

    display(&s);
    return 0;
}

