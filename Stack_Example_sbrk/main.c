#include <stdio.h>
#include <stdlib.h>
#include "stack_sb.h"

int main(int argc, char const *argv[])
{
    stack_sb_p stk=stack_create();
    stk=stack_push(stk,10);
    stk=stack_push(stk,21);
    stk=stack_push(stk,25);
    stk=stack_push(stk,45);
    stk=stack_push(stk,24);
    stk=stack_push(stk,23);
    stk=stack_push(stk,64);


    if(stack_element_is_in(stk,44))
        printf("find\n");
    else
        printf("not found\n");
    
   //stk=stack_delete_element(stk,44);
       printf("%d\n",stack_len(stk)); 
    while(stk!=NULL){
        printf("{%d}\n",(int*)stack_print_last_element(stk));
        stk=stk->next;
    } 

   stk=stack_clear(stk);

    

    
    return 0;
}
