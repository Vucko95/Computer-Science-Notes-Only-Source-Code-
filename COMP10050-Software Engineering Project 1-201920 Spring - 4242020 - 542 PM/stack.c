/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lpasqua
 *
 * Created on 02 April 2019, 10:55
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

/*
 * Data structure to represent the various elements
 * of the stack
 */
struct stack_elem{
    int data;
    struct stack_elem *next;
} stack;


/*
 * This method adds an element on top of the stack
 * 
 * Input
 * value: the integer value contained in the element to be pushed to the stack
 * top: a pointer to the top of the stack
 * 
 * Output
 * Returns the new top of the stack pointing to the newly added element
 */
struct stack_elem * push(int value, struct stack_elem *top){
    struct stack_elem *curr = top;
    top = malloc(sizeof(stack));
    top->data = value;
    top->next = curr;
    return top;
}

/*
 * This method prints the value of the topmost element of the stack
 * and removes the element from the stack
 * 
 * Input
 * top: a pointer to the top of the stack
 * 
 * Output
 * Returns the new top of the stack after the topmost element is removed
 */
struct stack_elem * pop(struct stack_elem *top){
    struct stack_elem *curr = top;
    if(curr!=NULL){
        top = curr->next;
        printf("Stack Data: %d\n", curr->data);
        free(curr);
    }
    return top;
}


int main(int argc, char** argv) {
    
    //pointer to the top of the stack
    struct stack_elem *top = NULL;
    //pointer to the current element of the stack
    struct stack_elem *curr = NULL;
    
    printf("Pushing 3 elements to the stack\n");
    
    /*
     * Push 3 elements in the stack
     */
    top = push(1, top);
    printf("Stack Data: %d\n", top->data);
    
    top = push(2, top);
    printf("Stack Data: %d\n", top->data);
    
    top = push(3, top);
    printf("Stack Data: %d\n", top->data);
    
    /*
     * Pops 3 elements from the stack
     */
    top = pop(top);
    top = pop(top);
    top = pop(top);
    
    return 0;
}

