#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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
    char* str = (char*)malloc(sizeof(char) * 100);
    fgets(str, 1000, stdin);

    char** res = split(str);

    for (int i = 0; i < 4; i++)
    {
        printf("%s\t", res[i]);
    }    

    return 0;
}