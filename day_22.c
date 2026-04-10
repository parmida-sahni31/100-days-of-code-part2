//Problem: Count Nodes in Linked List

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

int main(){
    struct node *head=NULL, *newnode, *temp;
    int n,i;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        newnode= (struct node *)malloc(sizeof(struct node));

        scanf("%d", &newnode->data);

        newnode->next = NULL;
        
        if(head == NULL){
            head= newnode;
        }
        else {
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next=newnode;
        }
    }

    int count= 0;
    temp = head;
    while(temp!= NULL){
        count++;
        temp= temp->next;
    }

    printf("%d", count);
    return 0;
}