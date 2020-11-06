#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stack_sb.h"

uint8_t buffer[5]={0,1,2,3,4};

int main(int argc, char const *argv[])
{
    stack_sb_p stk=stack_create();
    stk=stack_allocate_datas(stk,sizeof(buffer),buffer);
    stk=stack_push(stk,10);
    stk=stack_push(stk,45);
    stk=stack_push(stk,25);
    stk=stack_push(stk,45);
    stk=stack_push(stk,44);
    stk=stack_push(stk,23);
    stk=stack_push(stk,64);


    if(stack_element_is_in(stk,4))
        printf("find\n");
    else
        printf("not found\n");
    
 
       printf("%d\n",stack_len(stk)); 
       stk=stack_delete_element(stk,45); 

    while(stk!=NULL){
        printf("{%d}\n",(int*)stack_print_last_element(stk));
        stk=stk->next;
    } 

   stk=stack_clear(stk);

    

    
    return 0;
}
