/**
 * @file stack_sb.h
 * @author Salvatore Bruccoleri (salvatorebrk@gmail.com)
 * @brief Stack library example LIFO
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef __STACK_SB_HH__
#define __STACK_SB_HH__
#include <stdint.h>
typedef enum {
    false,
    true,
}Boolean;

typedef struct stack_sb_t
{
    int value;
    struct stack_sb_t *next;

} stack_sb_t, *stack_sb_p;

// Function Stack Prototype
stack_sb_p stack_create(void);
Boolean is_empty(stack_sb_p stk);
Boolean stack_element_is_in(stack_sb_p st,int v);
stack_sb_p stack_push(stack_sb_p st,int v);
stack_sb_p stack_pop(stack_sb_p st);
void* stack_print_last_element(stack_sb_p st);
stack_sb_p stack_clear(stack_sb_p st);
stack_sb_p stack_delete_element(stack_sb_p st,int v);
unsigned int stack_len(stack_sb_p st);
stack_sb_p stack_allocate_datas(stack_sb_p st,int size,uint8_t *buffer);

#endif