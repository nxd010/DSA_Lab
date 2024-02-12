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

Node* deleteFirstNode(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteMiddleNode(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("List does not have enough nodes\n");
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    free(slow);
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

    head1 = deleteFirstNode(head1);
    printf("After deleting the first node: ");
    print(head1);

    head1 = deleteMiddleNode(head1);
    printf("After deleting the middle node: ");
    print(head1);

    return 0;
}
