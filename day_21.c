//Problem: Create and Traverse Singly Linked List

#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head= NULL, *newnode, *temp;
    int n,i;

    printf("enter the number of nodes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        newnode= (struct node*)malloc(sizeof(struct node));

        printf("enter data for node %d: ", i+1);
        scanf("%d", &newnode->data);

        newnode->next=NULL;

        if(head==NULL){
            head= newnode;
        }
        else{
            temp = head;
            while(temp->next!= NULL){
                temp= temp->next;
            }
            temp->next= newnode;
        }

    }

    // Traversing the linked list
    printf("\nLinked List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}