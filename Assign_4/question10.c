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

Node* insertAtThirdPlace(Node* head, int val) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        printf("List has only one node\n");
        return head;
    }
    if (head->next->next == NULL) {
        printf("List has only two nodes\n");
        return head;
    }
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory error\n");
        return head;
    }
    newnode->data = val;
    newnode->next = head->next->next;
    head->next->next = newnode;
    return head;
}

Node* removeLastNode(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
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
    printf("Enter the value to insert at third place: ");
    scanf("%d", &newValue);
    head1 = insertAtThirdPlace(head1, newValue);
    print(head1);

    head1 = removeLastNode(head1);
    printf("After removing the last node: ");
    print(head1);

    return 0;
}
