
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"


void test(char** data){
    int i = 0;
    Stack* stack = init();

    for(i = 0;i < 5; i++){
        printf("Pushing: %s\n",data[i]);
        push(stack,data[i]);
    }
    printf("Size: %d\n", size(stack));

    printf("Peek: %s\n", (char*)peek(stack));
    pop(stack,free);//pops off apple

    pop(stack,free);//pops off lettuce

    printf("Size: %d\n", size(stack));

    printf("Peek: %s\n", (char*)peek(stack));
    pop(stack,free);//pops off potato

    printf("Peek: %s\n", (char*)peek(stack));
    pop(stack,free);//pops off orange

    printf("Peek: %s\n", (char*)peek(stack));
    pop(stack,free);//pops off pear

    pop(stack,free);
    printf("Size: %d\n", size(stack));

    destroy(stack,free);
}

int main(int argc, char** argv){
    int i = 0;
    char** strings = malloc(sizeof(char*) * 5);
    
    strings[i] = malloc(sizeof(char) * 5);
    strcpy(strings[i++],"pear");
    strings[i] = malloc(sizeof(char) * 7);
    strcpy(strings[i++],"orange");
    strings[i] = malloc(sizeof(char) * 7);
    strcpy(strings[i++],"potato");
    strings[i] = malloc(sizeof(char) * 8);
    strcpy(strings[i++],"lettuce");
    strings[i] = malloc(sizeof(char) * 6);
    strcpy(strings[i++],"apple");

    test(strings);

    free(strings);
    strings = NULL;
    return 0;
}
