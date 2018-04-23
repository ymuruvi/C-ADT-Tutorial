
#include "stack.h"

Stack* init(){
    Stack* s = malloc(sizeof(Stack));
    s-> head = NULL;
    s-> size = 0;
    return s;
}

Node* initNode(){
    Node* n = malloc(sizeof(Node));
    if(n){
        n-> data = NULL;
        n-> next = NULL;
    }
    return n;
}

void push(Stack* stack, void* data){
    if(stack){
        Node* node = initNode();
        if(node){
            node-> data = data;
            node-> next = stack-> head;
            stack-> head = node;
            stack-> size++;
        }
    }
}

void pop(Stack* stack, void (*delete) (void* data)){
    if(stack){
        Node* tmp = stack-> head;
        if(tmp){
            stack-> head = tmp-> next;
            stack-> size --;
            delete(tmp-> data);
            free(tmp);
            tmp = NULL;
        }
    }
}

void* peek(Stack* stack){
    if(stack){
        return stack-> head-> data;
    }
    return NULL;
}

void destroy(Stack* stack, void (*delete) (void* data)){
    if(stack){
        Node* current;
        while(current = stack-> head){
            delete(current-> data);
            stack-> head = current-> next;
            free(current);
        }
        free(stack);
        stack = NULL;
    }
}

int size(Stack* s){
    if(s){
        return s-> size;
    }
    return -1;
}
