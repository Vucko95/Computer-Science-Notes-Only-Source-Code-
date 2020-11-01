/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: lpasqua
 *
 * Created on 02 April 2019, 20:49
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

//data structure that represents the elements
// of the linked list
struct chain_element {
  int data;
  struct chain_element* next; 
} chain;


int main(int argc, char** argv)  {
    //number of elements of the linked list
    int chainSize;

    //pointer to an element of the list
    struct chain_element *curr;
    //pointer to the first element of the list
    struct chain_element *first;
    //pointer to the last element of the list
    struct chain_element *last;

    printf("Insert number of elements\n");
    scanf("%d",&chainSize);
    
    
    /*
     * Functionality to add a number of elements
     * to the list equal to chainSize
     */
     for (int i = 0; i < chainSize; i++) {
        last = malloc (sizeof (chain));
        last->data = i + 1;
        last->next = NULL;
        if(i==0)
            first = last;
        else
            curr-> next = last;
        curr = last;
    }
    
    /*
     * Functionality to traverse the elements of the list
     * in the order in which they have been added to the list
     * and print their value
     */
    curr = first;
    while (curr != NULL) {
        printf ("Chain num %d -> ", curr->data);
        curr = curr->next;
    }
    
    /*
     * Functionality to traverse the elements of the list
     * and remove them from the list in the order in which
     * they have been added to the list
     */
    printf("\n\n");   
    curr = first;    
    while (curr != NULL) {     
	printf ("freeing %d ->", curr->data);     	
        first= curr->next;    
	free(curr);     
	curr = first;   
    }
    
    return 0;

}

