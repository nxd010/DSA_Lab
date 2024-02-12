#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
    int data;
    struct node *next;
} Node;

Node* linkedlistcreator(Node**head,int val,Node** tail){
    
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(!newnode)
        printf("memory error");
    newnode->data = val;
    newnode->next = NULL;
    
    if(*head==NULL){ 
        *head = newnode;
        *tail = newnode;
    }
    else{
        (*tail)->next = newnode;
        *tail = (*tail)->next;
    }
    return *head;
}

void print(Node* head){
    printf("\n");
    Node *temp = head;
    while(temp){
        printf("%d", temp->data);
        temp = temp->next;
        if(temp){
            printf("->");
        }
    }
    printf("\n");
    return;
}

int main(){
    Node *head1 = NULL;
    Node* tail1 = NULL;
   
   
    
    printf("enter the  linked list ");
    
    while(1){       
        int val;       
        scanf("%d", &val);
        if(val ==-1){
            break;
        }
       
        
        head1=linkedlistcreator(&head1, val, &tail1);
    }
    // printing 
    print(head1);

    Node *temp = head1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    printf("address of last node is : %d", temp);

    return 0;
}