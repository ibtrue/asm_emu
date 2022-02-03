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

int main()
{
    FILE *fp;
    /**
     * @brief Переменная, в которую будет записываться конкретная строка из программы (машинный код)
     */

    char* str = (char*)malloc(sizeof(char) * 50);

    /**
     * @brief динамический массив для переменных и констант[]
     */
    int* vc = (int*)malloc(sizeof(int) * 10);

    data* vars = (data*)malloc(sizeof(data) * 100);
    code* prog = (code*)malloc(sizeof(code) * 100);
    
    int i = 0;
    
    if((fp = fopen("code.txt", "r")) == NULL)
    {
        printf("Couldn't open file");
	    return 0;
    }
    
    while (strcmp(str, "programm:\n") != 0)
    {
        fgets(str, 100, fp);
        char** res = split(str);
        i = atoi(res[0]) - 1000;
        vars[i].variable = atoi(res[1]);
    }

    /**
     * @brief переменная, которая сначала счетчик для создания массива структур, потом - количество строк в программе - 1
     * 
     */
    int j = 0;

    // Поменять индексы. (Случай когда они идут не по порядку) ((Поставить в зависимость от memory_cell))

    while (!feof(fp)) // Разбивает на массив структур (prog) всё тело программы i - остаток от ячейки памяти -2000
    {
        fgets(str, 100, fp);
        char** res = split(str);
        int* mas = (int*)malloc(sizeof(int) * 5);
        
        for (int i = 0; i < 5; i++)
        {
            mas[i] = atoi(res[i]);
        }
        prog[i].memory_cell = mas[0];
        prog[i].operation = mas[1];
        prog[i].var1 = mas[2];
        prog[i].var2 = mas[3];
        prog[i].res = mas[4];
        j++;
    }

    for (int i = 0; i <= j; i++)
    {
        code cur;
        int sw = prog[j].operation;
        switch (sw)
        {
            case 99:
            {
                return; //return выход из программы
                break;
            }
            case 00:
            {
                vars[prog[j].res - 1000].variable = vars[prog[j].var1 - 1000].variable; //приравнивает mas[4] к mas[2] 
                break;
            }
            case 01:
            {
                vars[prog[j].res - 1000].variable = vars[prog[j].var1 - 1000].variable + vars[prog[j].var2 - 1000].variable; //складывает mas[2] и mas[3] и записывает в mas[4]
                break;
            }
            case 02:
            {
                vars[prog[j].res - 1000].variable = vars[prog[j].var1 - 1000].variable + vars[prog[j].var2 - 1000].variable; //вычитает mas[3] из mas[2] и записывает в mas[4]
                break;
            }
            case 03:
            {
                vars[prog[j].res - 1000].variable = vars[prog[j].var1 - 1000].variable * vars[prog[j].var2 - 1000].variable; //умножение НЕ ПОНЯЛ ЧЕМ ОТЛИЧЕТСЯ Б/ЗН И С/ЗН
                break;
            }
            case 04:
            {
                vars[prog[j].res - 1000].variable = vars[prog[j].var1 - 1000].variable / vars[prog[j].var2 - 1000].variable; // div C/зн
                break;
            }
            case 14:
            {
                vars[prog[j].res - 1000].variable = vars[prog[j].var1 - 1000].variable % vars[prog[j].var2 - 1000].variable; // mod Б/зн
                break;
            }
            case 81:
            {
                vars[prog[j].res - 1000].variable = vars[prog[j].var1 - 1000].variable % vars[prog[j].var2 - 1000].variable; // mod Б/зн
                break;
            }
            case 95:
            {
                break;
            }
        }
    }
     
    // Хочу дописать все операции и переходы с помощю массива структур (prog) в виде кажой строчки отдельно
        
    return 0;
}