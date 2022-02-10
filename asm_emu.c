#include "asm_emu.h"

long int HEXtoDEC(char* str)
{
    char *next = NULL;
    long int value = strtol(str, &next, 16);

    return (int)value;
}

int charcmp(char s1, char s2)
{
    return (s1 == s2) ? 0 : 1;
}

char** split(char* str)
{
    char ** res = (char**)malloc(sizeof(char) * 32);
    int i = 0, j = 0;
    for (int i = 0; i < (int)strlen(str); i++)
    {
        res[i] = (char*)malloc(sizeof(char) * (int)strlen(str));
    }
    i = 0;
    if (!res)
        return NULL;
    
    while (*str)
    {
        if (charcmp(*str, ' ') != 0 && charcmp(*str, '\n') != 0)
        {
            res[i][j] = *str;
            j++;
        }
        else if (charcmp(*str, '\n') != 0)
        {
            j = 0;
            i++;
        }
        ++str;
    }
    return res;
}

/**
 * @brief Операция 99. завершает программу
 */
void return_c()
{
    printf("return\n");
    return;
}

/**
 * @brief приравнивает переменную из массива переменных с индексом ind_where к переменной с индексом ind_who
 * Операция 00
 * 
 * @param vars 
 * @param ind_where 
 * @param ind_who 
 */
void equating(data* vars, int ind_where, int ind_who)
{
    vars[ind_where].variable = vars[ind_who].variable;
    return;
}

/**
 * @brief Записывает сумму переменных с индексами arg1 и arg2 в индекс res
 * Операция 01
 * 
 * @param vars 
 * @param arg1 
 * @param arg2 
 * @param res 
 */
void sum(data* vars, int arg1, int arg2, int res)
{
    vars[res].variable = vars[arg1].variable + vars[arg2].variable;
    return;
}

/**
 * @brief Разность arg1 - arg2. записывается в res
 * Операция 02
 * 
 * @param vars 
 * @param arg1 
 * @param arg2 
 * @param res 
 */
void subtraction(data* vars, int arg1, int arg2, int res)
{
    vars[res].variable = vars[arg1].variable - vars[arg2].variable;
    return;
}

/**
 * @brief Произведение arg1 и arg2. записывается в res
 * Операция 03
 * 
 * @param vars 
 * @param arg1 
 * @param arg2 
 * @param res 
 */
void multy(data* vars, int arg1, int arg2, int res)
{
    vars[res].variable = vars[arg1].variable * vars[arg2].variable;
    return;
}

/**
 * @brief Целочисленное деление arg1 на arg2. Результат в res
 * 
 * @param vars 
 * @param arg1 
 * @param arg2 
 * @param res 
 */
void div(data* vars, int arg1, int arg2, int res)
{
    vars[res].variable = vars[arg1].variable / vars[arg2].variable;
    return;
}

/**
 * @brief Остаток от деления arg1 на arg2. Результат в res
 * 
 * @param vars 
 * @param arg1 
 * @param arg2 
 * @param res 
 */
void mod(data* vars, int arg1, int arg2, int res)
{
    vars[res].variable = vars[arg1].variable % vars[arg2].variable;
    return;
}

void div(data* vars, int arg1, int arg2, int res)
{
    vars[res].variable = vars[arg1].variable / vars[arg2].variable;
    return;
}

int compeq(data* vars, int arg1, int arg2, int res) //comparation equal
{
    if (vars[arg1].variable == vars[arg2].variable)
    {
        return res;
    }

    else
    {
        return; //next idk how to code it like your idea. I think it might be memory cell number
    }
}

int compneq(data* vars, int arg1, int arg2, int res) //comparation not equal
{
    if (vars[arg1].variable != vars[arg2].variable)
    {
        return res;
    }

    else
    {
        return; //next idk how to code it like your idea. I think it might be memory cell number
    }
}

int compl(data* vars, int arg1, int arg2, int res) //comparation arg1 lower than arg2
{
    if (vars[arg1].variable < vars[arg2].variable)
    {
        return res;
    }

    else
    {
        return; //next idk how to code it like your idea. I think it might be memory cell number
    }
}

int comple(data* vars, int arg1, int arg2, int res) //comparation arg1 lower or equal than arg2
{
    if (vars[arg1].variable <= vars[arg2].variable)
    {
        return res;
    }

    else
    {
        return; //next idk how to code it like your idea. I think it might be memory cell number
    }
}

int comph(data* vars, int arg1, int arg2, int res) //comparation arg1 higher than arg2
{
    if (vars[arg1].variable > vars[arg2].variable)
    {
        return res;
    }

    else
    {
        return; //next idk how to code it like your idea. I think it might be memory cell number
    }
}

int comphe(data* vars, int arg1, int arg2, int res) //comparation arg1 higher or equal than arg2
{
    if (vars[arg1].variable >= vars[arg2].variable)
    {
        return res;
    }

    else
    {
        return; //next idk how to code it like your idea. I think it might be memory cell number
    }
}

//Ya ne viebonistiy a prosto vpadlu perekluchat' yazik :)