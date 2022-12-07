#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Node{
    long data;
    struct Node* next;
};


void enqueue(struct Node** head, long num){
    struct Node* ptr = *head;
    if (ptr == NULL) {
        struct Node* new = (struct Node*) malloc(sizeof(struct Node));
        new->data = num;
        new->next = NULL;
        *head = new;
        return;
    }

    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    new->data = num;
    new->next = NULL;
    ptr->next = new;
    return;
}


void push(struct Node** head, long num){
    struct Node* ptr = *head;
    if (ptr == NULL) {
        struct Node* new = (struct Node*) malloc(sizeof(struct Node));
        new->data = num;
        new->next = NULL;
        *head = new;
        return;
    }
    /*struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    *new = node;
    new->next = *head;
    *head = new;
    return;*/

    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
    new->data = num;
    new->next = ptr;
    *head = new;
    return;
}


//searches for first node containing 'data'
//and deletes that node from the LL
bool pop(struct Node** head){
    //struct Node* prev = *head;
    struct Node* current = *head;

    if (current == NULL) return false;
    
    (*head) = current->next;
    free(current);
    return true;
}


void print_list(struct Node* head) {
    if (head == NULL) {
        printf("EMPTY\n");
        return;
    }
    while(head) {
        printf("%ld",head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}


int main(int argc, char** argv){
    
    FILE *fp;
    fp = fopen(argv[1], "r");

    char val[8];
    long num;

    if(fp == NULL) {
        printf("error\n");
        exit(0);
        return 0;
    }

    struct Node* head = NULL;

    while(fscanf(fp, "%s", val) != EOF) {
        if (strcmp(val, "ENQUEUE") == 0) {
            fscanf(fp, "%ld",&num);
            enqueue(&head,num);
        }
        if (strcmp(val, "PUSH") == 0) {
            fscanf(fp, "%ld",&num);
            push(&head, num);
        }
        if (strcmp(val, "POP") == 0) {
            pop(&head);
        }
        print_list(head);
    }

    while (head != NULL) {
        struct Node* tempPtr = head;
        head = head->next;
        free(tempPtr);
    }

	return EXIT_SUCCESS;
}