#include <stdio.h>
#include <ctype.h>
#define MAX 100

struct stack{
    int top;
    int arr[MAX];
};

void push(struct stack *s, char ch){
    s->arr[++s->top]= ch;
}

int pop(struct stack *s){
    return s->arr[s->top--];
}

int peek(struct stack *s){
    return s->arr[s->top];
}

int isEmpty(struct stack *s){
    return s->top== -1;
}

int ApplyOperator(char op, int a, int b){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
    if(op == '/') return a / b;
    return 0;
}

int main(){
    struct stack s;
    s.top=-1;

    char postfix[100];
    int i=0, result;

    printf("enter postfix:");
    scanf("%s", postfix);

    while(postfix[i]!= '\0'){
        char ch = postfix[i];

        if(isdigit(ch)){
            push(&s, ch - '0');   // convert char → int
        }
        else{
            int b = pop(&s);
            int a = pop(&s);
            int result = ApplyOperator(ch, a, b);
            push(&s, result);
        }
        i++;
    }

    printf("Result = %d", pop(&s));
    return 0;
}

