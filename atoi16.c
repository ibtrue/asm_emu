#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *Scale = "0123456789ABCDEF";
 
int CVH(char *Str,int *Res)
{
    char a;
    int l = 0, n = 0, i = 0, j = 0, p = 0, r = 0;
    l = strlen(Str);

    r = 0;
    for (i = 0; i < l; i++)
    {
        a = Str[i];
        if ((a >= 'a') && (a <= 'z')) a = (int) a & 0xDF; // перевод в верхний регистр
        p = 0;
        for (j = 0; j <= 15; j++) 
            if (Scale[j] == a)
            { 
               r = r * 16 + j; // собственно, перевод в шестнадцатЕричную систему
               p = 1;
               break;
            }   
         // неверный символ в строке
         if (p == 0)
            return -3; 
    }     
    *Res = r;
    return 0;
}