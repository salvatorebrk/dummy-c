#include <stdio.h>
#include <stdlib.h>
#include "stack_sb.h"


stack_sb_p stack_create(void){
    return NULL;
}

Boolean is_empty(stack_sb_p st){
    if(st==NULL)
        return true;
    return false;
}


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

stack_sb_p stack_push(stack_sb_p st,int v){
    stack_sb_t *element;
    element=(stack_sb_t*) malloc(sizeof(*element)); 
    element->value=v;
    element->next=st;
    return element;

}

stack_sb_p stack_pop(stack_sb_p st){
    stack_sb_t *element;
    if(is_empty(st))
        return stack_create();
    element=st->next;
    free(st);
    return element;
}


stack_sb_p stack_delete_element(stack_sb_p st,int v){
    stack_sb_t *element_to_delete,*element_to_attach;
    int cnt=0;;
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
    return st;
}

int stack_len(stack_sb_p st){
    stack_sb_t *element;
    element=st;
    int cnt=0;
    while (element!=NULL){
        element=element->next;
        cnt++;
    }
    return cnt;
} 

stack_sb_p stack_clear(stack_sb_p st){
    stack_sb_t *element;
    if(is_empty(st))
        return stack_create();
    element=st->next;
    free(st);
    return stack_clear(element);
}

void* stack_print_last_element(stack_sb_p st){
    return (void*)st->value;
}

