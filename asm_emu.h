#ifndef ASM_EMU_H
# define ASM_EMU_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

struct Data
{
    int variable;
};

struct Code
{
    int memory_cell;
    int operation;
    int var1;
    int var2;
    int res;
};

typedef struct Data data;
typedef struct Code code;

long int    HEXtoDEC(char* str);
int         charcmp(char s1, char s2);
char**      split(char* str);
//code functions
void return_c(int code); // 99
void equating(data* vars, int ind_where, int ind_who); // 00
void sum(data* vars, int arg1, int arg2, int res); // 01
void subtraction(data* vars, int arg1, int arg2, int res); //02
void multy(data* vars, int arg1, int arg2, int res); //03
void div(data* vars, int arg1, int arg2, int res); //04
void mod(data* vars, int arg1, int arg2, int res); //14

#endif