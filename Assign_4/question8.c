#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* linkedlistcreator(Node** head, int val, Node** tail) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    if (!newnode)
        printf("memory error");
    newnode->data = val;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        *tail = newnode;
    } else {
        (*tail)->next = newnode;
        *tail = (*tail)->next;
    }
    return *head;
}

void print(Node* head) {
    printf("\n");
    Node *temp = head;
    while (temp) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp) {
            printf("->");
        }
    }
    printf("\n");
    return;
}

Node* insertAtBeginning(Node* head, int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory error\n");
        return head;
    }
    newnode->data = val;
    newnode->next = head;
    return newnode;
}

Node* insertAtEnd(Node* head, int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory error\n");
        return head;
    }
    newnode->data = val;
    newnode->next = NULL;
    
    if (head == NULL)
        return newnode;
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

int main() {
    Node *head1 = NULL;
    Node* tail1 = NULL;

    printf("Enter the linked list: ");
    
    while (1) {       
        int val;       
        scanf("%d", &val);
        if (val == -1) {
            break;
        }  
        head1 = linkedlistcreator(&head1, val, &tail1);
    }

    print(head1);

    int newValue;
    printf("Enter the value to insert at the beginning: ");
    scanf("%d", &newValue);
    head1 = insertAtBeginning(head1, newValue);
    print(head1);

    printf("Enter the value to insert at the end: ");
    scanf("%d", &newValue);
    head1 = insertAtEnd(head1, newValue);
    print(head1);

    return 0;
}
