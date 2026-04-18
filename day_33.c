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

int precedence(char op){
    if(op == "+" || op == "-") return 1;
    if(op == "/" || op == "*") return 2;
    return 0;
}


int main(){
    struct stack s;
    s.top=-1;

    char infix[100], postfix[100];
    int i=0, j=0;

    printf("enter infix:");
    scanf("%s", infix);

    while(infix[i]!= '\0'){
        char ch = infix[i];

        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch == '('){
            push(&s, ch);
        }
        else if(ch == ')'){
            while(peek(&s)!= ')' && !isEmpty(&s))
            pop(&s);

            pop(&s);
        }
        else{
            while(!isEmpty(&s) && precedence(ch)<= precedence(peek(&s))){
                postfix[j++]= pop(&s);
            }
            push(&s, ch);

        }

        i++;
    }

    while(!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';

    printf("Postfix: %s", postfix);
    return 0;
}

