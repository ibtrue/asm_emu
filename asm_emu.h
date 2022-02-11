#ifndef ASM_EMU_H
# define ASM_EMU_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

struct Code
{
    int memory_cell;
    int operation;
    int var1;
    int var2;
    int res;
};

typedef struct Code code;

long int    HEXtoDEC(char* str);
int         charcmp(char s1, char s2);
char**      split(char* str);
//code functions
void        return_c(); // 99
void        equating(int* vars, int ind_where, int ind_who); // 00
void        sum(int* vars, int arg1, int arg2, int res); // 01
void        subtraction(int* vars, int arg1, int arg2, int res); //02
void        multy(int* vars, int arg1, int arg2, int res); //03
void        div_c(int* vars, int arg1, int arg2, int res); //04
void        mod_c(int* vars, int arg1, int arg2, int res); //14
int         compeq(int* vars, int arg1, int arg2, int res);
int         compneq(int* vars, int arg1, int arg2, int res);
int         compl(int* vars, int arg1, int arg2, int res);
int         comple(int* vars, int arg1, int arg2, int res);
int         comph(int* vars, int arg1, int arg2, int res);
int         comphe(int* vars, int arg1, int arg2, int res);

#endif