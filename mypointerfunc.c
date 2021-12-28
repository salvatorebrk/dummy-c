/**
 * @file mypointerfunc.c Simple example of called array functions
 * @author Salvatore Bruccoleri (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int mul(int a, int b) {
    return a*b;
}

int dv(int a, int b) {
    return a/b;
}

enum op{
    SUM=0,
    SUB,
    MUL,
    DV,
    N_OP,
};


typedef struct operation{
    int (*ptrtof)(int, int);
    int result;
    enum op opt;
}operation_t;

operation_t exec_operation[N_OP]={
{&add,0,SUM},
{&sub,0,SUB},
{&mul,0,MUL},
{&dv,0,DV},
};


int main(int argc, char const *argv[])
{
    for (int i=0;i<N_OP;i++){
        exec_operation[i].result=exec_operation[i].ptrtof(6,2);
        printf("registered opt is %u \n",exec_operation[i].opt);
        printf("Result is %u \n",exec_operation[i].result);
    }

    return 0;
}
