
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    void* data;
    struct node* next;
}Node;

typedef struct stack{
    Node* head;
    unsigned int size;
}Stack;

Stack* init();

Node* initNode();

void push(Stack* stack, void* data);

void pop(Stack* s, void (*delete) (void* data));

void* peek(Stack* s);

void destroy(Stack* s, void (*delete) (void* data));

int size(Stack* s);
