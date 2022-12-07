#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Node{
    long data;
    struct Node* next;
};


//adds a node to the beginig of the LL pointed to by head
void add_node(struct Node** head, long num){
    struct Node* ptr = *head;
    if (ptr == NULL) {
        struct Node* new = (struct Node*) malloc(sizeof(struct Node));
        new->data = num;
        new->next = NULL;
        *head = new;
        
        return;
    }

    while(ptr->next != NULL && ptr->data < num) {
        if (ptr->next->data > num) {
            struct Node* new = (struct Node*) malloc(sizeof(struct Node));
            new->data = num;
            new->next = ptr->next;
            ptr->next = new;
            return;
        }
        ptr = ptr->next;
    }

    if (ptr->data > num) {
        struct Node* new = (struct Node*) malloc(sizeof(struct Node));
        new->data = num;
        new->next = ptr;
        *head = new;
        return;
    }
    if (ptr->data < num) {
        struct Node* new = (struct Node*) malloc(sizeof(struct Node));
        new->data = num;
        new->next = NULL;
        ptr->next = new;
        return;
    }

    return;
}


//searches for first node containing 'data'
//and deletes that node from the LL
bool remove_node(struct Node** head, long data){
    struct Node* prev = *head;
    struct Node* current = *head;

    if (current == NULL) return false;
    
    if(current->data == data) {
        (*head) = current->next;
        free(current);
        return true;
    }

    current = current->next;

    while(current) {
        if(current->data == data) {
            prev->next = current->next;
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
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

    char val[7];
    long num;

    if(fp == NULL) {
        printf("error");
        exit(0);
        return 0;
    }

    struct Node* head = NULL;

    while(fscanf(fp, "%s %ld", val, &num) != EOF) {
        if (strcmp(val, "INSERT") == 0) {
            add_node(&head,num);
        }
        if (strcmp(val, "DELETE") == 0) {
            remove_node(&head, num);
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