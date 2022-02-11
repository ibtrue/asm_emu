#include "asm_emu.h"

int main()
{
    FILE *fp;
    /**
     * @brief Переменная, в которую будет записываться конкретная строка из программы (машинный код)
     */

    char* str = (char*)malloc(sizeof(char) * 50);

    int* vars = (int*)malloc(sizeof(int) * 1000);
    for (int i = 0; i < 1000; i++)
        vars[i] = 0;
    code* prog = (code*)malloc(sizeof(code) * 100);
    int amo_vars = 0;

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
        i = HEXtoDEC(res[0]) - HEXtoDEC("1000");
        if (i >= 0)
        {
            //printf("%d\n", i);
            vars[i] = HEXtoDEC(res[1]);
        }
        //printf("amo : %d;**i : %d;**vars[i] : %d\n ", amo_vars, i, vars[i]);
        amo_vars += 1;        
    }

    printf("\n\n");

    /**
     * @brief переменная, которая сначала счетчик для создания массива структур, потом - количество строк в программе - 1
     * 
     */
    int amo_commands = 0;
    int* arr = (int*)malloc(sizeof(int) * 100);
    int ind = 0;
    //Поменять индексы. (Случай когда они идут не по порядку) ((Поставить в зависимость от memory_cell))
    // DONE!!!
    while (!feof(fp)) // Разбивает на массив структур (prog) всё тело программы i - остаток от ячейки памяти -2000
    {
        fgets(str, 100, fp);
        char** res = split(str);
        int* mas = (int*)malloc(sizeof(int) * 5);
        
        for (int i = 0; i < 5; i++)
        {
            mas[i] = HEXtoDEC(res[i]);
        }

        arr[ind] = mas[0] - HEXtoDEC("2000");
        prog[arr[ind]].memory_cell = mas[0];
        prog[arr[ind]].operation = mas[1];
        prog[arr[ind]].var1 = mas[2];
        prog[arr[ind]].var2 = mas[3];
        prog[arr[ind]].res = mas[4];  
        ind++;
        amo_commands++;
    }
    
    for (int i = 0; i < amo_commands; i++)
    {
        code current_line = prog[arr[i]];
        current_line.res -= 1000;
        current_line.var1 -= 1000;
        current_line.var2 -= 1000;
        current_line.memory_cell -= 2000;
        int oper = current_line.operation;
        int flag = 0;
        int megaflag = 0;
        printf("Operation: %d\t", oper);

        TryAgain:
        if (megaflag != 0)
        {
            current_line = prog[arr[megaflag]];
            current_line.res -= 1000;
            current_line.var1 -= 1000;
            current_line.var2 -= 1000;
            current_line.memory_cell -= 2000;
            megaflag = 0;
        }
        if (oper == 99)
        {
            return_c();
            //return 0;
        }
        else if (oper == 00)
        {
            equating(vars, current_line.res, current_line.var1);
        }
        else if (oper == 1)
        {
            sum(vars, current_line.var1, current_line.var2, current_line.res);
        }
        else if (oper == 2)
        {
            subtraction(vars, current_line.var1, current_line.var2, current_line.res);
        }
        else if (oper == 3)
        {
            multy(vars, current_line.var1, current_line.var2, current_line.res);
        }
        else if (oper == 4)
        {
            div_c(vars, current_line.var1, current_line.var2, current_line.res);
        }
        else if (oper == 13)
        {
            mod_c(vars, current_line.var1, current_line.var2, current_line.res);
        }
        else if (oper == 14)
        {
            mod_c(vars, current_line.var1, current_line.var2, current_line.res);
        }
        else if (oper == 81)
        {
            flag = compeq(vars, current_line.var1, current_line.var2, current_line.res);
            if (flag != -1)
            {
                flag = 0;
                megaflag = current_line.res;
                goto TryAgain;
            }
        }
        else if (oper == 82)
        {
            flag = compneq(vars, current_line.var1, current_line.var2, current_line.res);
            if (flag != -1)
            {
                flag = 0;
                megaflag = current_line.res;
                goto TryAgain;
            }
        }
        else if (oper == 83)
        {
            flag = compl(vars, current_line.var1, current_line.var2, current_line.res);
            if (flag != -1)
            {
                flag = 0;
                megaflag = current_line.res;
                goto TryAgain;
            }
        }
        else if (oper == 86)
        {
            flag = comple(vars, current_line.var1, current_line.var2, current_line.res);
            if (flag != -1)
            {
                flag = 0;
                megaflag = current_line.res;
                goto TryAgain;
            }
        }
        else if (oper == 95)
        {
            flag = comph(vars, current_line.var1, current_line.var2, current_line.res);
            if (flag != -1)
            {
                flag = 0;
                megaflag = current_line.res;
                goto TryAgain;
            }
        }
        else if (oper == 85)
        {
            flag = comph(vars, current_line.var1, current_line.var2, current_line.res);
            if (flag != -1)
            {
                flag = 0;
                megaflag = current_line.res;
                goto TryAgain;
            }
        }
        else if (oper == 84)
        {
            flag = comphe(vars, current_line.var1, current_line.var2, current_line.res);
            if (flag != -1)
            {
                flag = 0;
                megaflag = current_line.res;
                goto TryAgain;
            }
        }
        else
        {
            printf("*%d*Incorrect command\n", oper);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        printf("*%d ", vars[i]);
        if (i % 15 == 0)
            printf("\n");
    }

    /*for (int i = 0; i <= amo_commands; i++)
    {
        code cur = prog[i];
        int sw = prog[i].operation;
        switch (sw)
        {
            case 99: //done
            {
                return_c(99);
                return 0;
                break;
            }
            case 00: //done
            {
                vars[prog[i].res - 1000].variable = vars[prog[i].var1 - 1000].variable; //приравнивает mas[4] к mas[2] 
                break;
            }
            case 01: //done
            {
                vars[prog[i].res - 1000].variable = vars[prog[i].var1 - 1000].variable + vars[prog[i].var2 - 1000].variable; //складывает mas[2] и mas[3] и записывает в mas[4]
                break;
            }
            case 02: //done
            {
                vars[prog[i].res - 1000].variable = vars[prog[i].var1 - 1000].variable + vars[prog[i].var2 - 1000].variable; //вычитает mas[3] из mas[2] и записывает в mas[4]
                break;
            }
            case 03: //done
            {
                vars[prog[i].res - 1000].variable = vars[prog[i].var1 - 1000].variable * vars[prog[i].var2 - 1000].variable; //умножение НЕ ПОНЯЛ ЧЕМ ОТЛИЧЕТСЯ Б/ЗН И С/ЗН
                break;
            }
            case 04: //done
            {
                vars[prog[i].res - 1000].variable = vars[prog[i].var1 - 1000].variable / vars[prog[i].var2 - 1000].variable; // div C/зн
                break;
            }
            case 14: //done
            {
                vars[prog[i].res - 1000].variable = vars[prog[i].var1 - 1000].variable % vars[prog[i].var2 - 1000].variable; // mod Б/зн
                break;
            }
            case 81: //nd
            {
                if (vars[prog[i].var1 - 1000].variable == vars[prog[i].var2 - 1000].variable) 
                {
                    cur = prog[vars[prog[i].res - 1000].variable];
                    break;
                }
                else
                {
                    break;
                }
            }
            case 82: // nd
            {
                if (vars[prog[i].var1 - 1000].variable != vars[prog[i].var2 - 1000].variable) 
                {
                    cur = prog[vars[prog[i].res - 1000].variable];
                    break;
                }
                else
                {
                    break;
                }
            }
            case 83: 
            {
                if (vars[prog[i].var1 - 1000].variable < vars[prog[i].var2 - 1000].variable) 
                {
                    cur = prog[vars[prog[i].res - 1000].variable];
                    break;
                }
                else
                {
                    break;
                }
            }
            case 86: 
            {
                if (vars[prog[i].var1 - 1000].variable <= vars[prog[i].var2 - 1000].variable) 
                {
                    cur = prog[vars[prog[i].res - 1000].variable];
                    break;
                }
                else
                {
                    break;
                }
            }
            case 85: 
            {
                if (vars[prog[i].var1 - 1000].variable > vars[prog[i].var2 - 1000].variable) 
                {
                    cur = prog[vars[prog[i].res - 1000].variable];
                    break;
                }
                else
                {
                    break;
                }
            }
            case 84: 
            {
                if (vars[prog[i].var1 - 1000].variable >= vars[prog[i].var2 - 1000].variable) 
                {
                    cur = prog[vars[prog[i].res - 1000].variable];
                    break;
                }
                else
                {
                    break;
                }
            }
        }
    }*/
     
    // Хочу дописать все операции и переходы с помощю массива структур (prog) в виде кажой строчки отдельно
    fclose(fp);
    return 0;
}