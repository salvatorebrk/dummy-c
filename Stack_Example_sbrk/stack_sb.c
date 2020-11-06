/**
 * @file stack_sb.c
 * @author Salvatore Bruccoleri (salvatorebrk@gmail.com)
 * @brief Stack library example LIFO methods
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack_sb.h"

/**
 * @brief initializer stack pointer
 * 
 * @return stack_sb_p 
 */
stack_sb_p stack_create(void){
    return NULL;
}

/**
 * @brief Is empty ?
 *         
 * @param st Stack
 * @return Boolean True o False
 */
Boolean is_empty(stack_sb_p st){
    if(st==NULL)
        return true;
    return false;
}

/**
 * @brief Find an element inside stack (don't give the position of element)
 *        
 * @param st 
 * @param v 
 * @return Boolean "True if is inside STack"
 */
Boolean stack_element_is_in(stack_sb_p st,int v){
    stack_sb_t *element;
    element=st;
    while (element!=NULL){
        if(element->value==v)
            return true;
        element=element->next;
    }
    return false;
}

/**
 * @brief Add an element into the Stack
 * 
 * @param st 
 * @param v 
 * @return stack_sb_p 
 */
stack_sb_p stack_push(stack_sb_p st,int v){
    stack_sb_t *element;
    element=(stack_sb_t*) malloc(sizeof(*element)); 
    if(element==NULL)
        return st;
    element->value=v;
    element->next=st;
    return element;

}

/**
 * @brief Remove only the last recod inserted
 * 
 * @param st 
 * @return stack_sb_p 
 */
stack_sb_p stack_pop(stack_sb_p st){
    stack_sb_t *element;
    if(is_empty(st))
        return stack_create();
    element=st->next;
    free(st);
    return element;
}

/**
 * @brief Remove the desired elements (one or more repetition) from the stack,this funcion is independent of dimension or position!!
 *       example:  remove 45
 *          1 23 45 78 98 45 2 -> 1 23 78 98 2
 * @param st 
 * @param v 
 * @return stack_sb_p 
 */
stack_sb_p stack_delete_element(stack_sb_p st,int v){
    stack_sb_t *element_to_delete,*element_to_attach;
    int cnt=0;
    if(st->value==v)
        return stack_pop(st);
    element_to_delete=st;
    element_to_attach=st;
    if(stack_element_is_in(st,v)){
        while (element_to_delete!=NULL){
            if(element_to_delete->value==v)
                {break;}
            element_to_delete=element_to_delete->next;
            cnt++;
            }
        
        for(int i=1;i<=cnt-1;i++){
            element_to_attach=element_to_attach->next;
        }
        element_to_attach->next=stack_pop(element_to_delete);
        
    }
    if(stack_element_is_in(st,v))
        stack_delete_element(st,v);

    return st;
}
 /**
  * @brief Function use to calcutate number of record in Stack
  * 
  * @param st 
  * @return unsigned int 
  */
unsigned int stack_len(stack_sb_p st){
    stack_sb_t *element;
    element=st;
    unsigned int cnt=0;
    while (element!=NULL){
        element=element->next;
        cnt++;
    }
    return cnt;
} 

/**
 * @brief Clear all LIFO 
 * 
 * @param st 
 * @return stack_sb_p 
 */

stack_sb_p stack_clear(stack_sb_p st){
    stack_sb_t *element;
    if(is_empty(st))
        return stack_create();
    element=st->next;
    free(st);
    return stack_clear(element);
}

/**
 * @brief Return last element value
 * 
 * @param st 
 * @return void* 
 */
void* stack_print_last_element(stack_sb_p st){
    return (void*)st->value;
}

/**
 * @brief Useful to push un array of elements in to the stack
 *  In this example i push int value, you can modify it to push several complex data structor
 *  For exaple:
 * typedef struct
 *{
 *	char		*cmd;
 *	uint16_t	cmdSize;
 *	char		*cmdResponseOnOk;
 *	uint16_t	timeoutMs;
 *	uint16_t	delayMs;
 *	uint8_t		skip;
 *}GSM_Cmd;
 * 
 * @param st 
 * @param size 
 * @param buffer 
 * @return stack_sb_p 
 */
stack_sb_p stack_allocate_datas(stack_sb_p st,int size, uint8_t*buffer){
    stack_sb_t *element;
    element=st;
    for(int i=0;i<size;i++)
        element=stack_push(element,buffer[i]);
    return element;
}