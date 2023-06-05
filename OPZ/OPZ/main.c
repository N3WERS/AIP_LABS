#include<stdio.h>
#include<stdlib.h>

char stack[100], outstring[100], strin[100];
int point = 0, k = 0, tos = 0;
void push(int number);
void deleteElementInStack();
char pop();
int prior(char a);

void main()
{
    gets(strin);    /* Ввод аpифметического выpажения */
    while (strin[k] != '\0')    /* Обрабатываем массив, пока не дойдем до конца арифм. Выражения */
    {
        if ((strin[k] >= '1' && strin[k] <= '9') || strin[k] == ' ')    /* Если очеpедной символ - цифра, то  записываем её в строку вывода*/
        {
            outstring[point++] = strin[k];
            k++;
            continue;
        }

        if (strin[k] == '(')    /* Если очеpедной символ - (, то записываем её в стек*/
        {
            push(k++);
            continue;
        }

        if (strin[k] == ')')   /* Если очеpедной символ - ), то записываем все символы до ( в строку вывода*/
        {
            for (int r = tos - 1; stack[r] != '('; r--)
            {
                deleteElementInStack();
            }
            stack[tos - 1] = stack[tos];
            tos--;
            k++;
            continue;
        }

        else
        {
            if (tos == 0)   /* Если стек пуст, просто записываем символ в стек */
            {
                push(k++);
                continue;
            }

            if (prior(strin[k]) > prior(stack[tos - 1]))  /* Если стек не пуст, а обрабатываемый символ ниже по приоритету, чем симол на вершине стека, просто записываем символ в стек */
            {
                push(k++);
                continue;
            }

            if (prior(strin[k]) <= prior(stack[tos - 1]))     /* Если стек не пуст, а обрабатываемый символ выше по приоритету, */
            {                                               /* чем символ на вершине стека, вытаскиваем все символы ниже или равные по приоритету, */
                deleteElementInStack();                     /* а обрабатываемый символ помещаем на вершину стека */
                for (int l = tos - 1; l >= 0; l--)
                {
                    if (prior(stack[l]) == 1)
                        break;
                    if (prior(strin[k]) <= prior(stack[l]))
                    {
                        deleteElementInStack();
                    }
                }
                push(k++);
            }
        }
    }

    if (tos != 0)   /* Если стек не пуст, вытаскиваем все символы в строку вывода */
    {
        for (int n = tos - 1; n >= 0; n--)
        {
            outstring[point++] = stack[n];
            stack[tos - 1] = stack[tos];
        }
    }
    printf("%s", outstring);    /* Выводим конечный результат */
}

/* Функция push записывает в стек обрабатываемый символ. Возвpащает указатель на новую веpшину стека */
void push(int number)
{
    stack[tos] = strin[number];
    tos++;
}

/* Функция deleteElementInStack записывает символ с вершины стека в строку вывода и удаляет символ с вершины. Изменяет указатель на веpшину стека */
void deleteElementInStack()
{
    outstring[point++] = stack[tos - 1];
    stack[tos - 1] = stack[tos];
    tos--;
}

/* Функция pop выводит значение на вершине стека */
char pop()
{
    if (tos < 0)
        return '0';
    else
        return stack[tos - 1];
}

/* Функция prior возвpащает пpиоpитет аpифм. опеpации */
int prior(char a)
{
    switch (a)
    {
    case '^':
        return 4;
    case '*':
    case '/':
        return 3;

    case '-':
    case '+':
        return 2;

    case '(':
        return 1;
    }
}

/* 2 + 7 - 11 * (14 - 3 + 1) / 17 */
/* 12 + (47 * 9 - 1) / 14 + 1 */
/* 75 / (14 - 2) + (12 * 3) - 2 */
/* 5 - 89 * 2 - (23 + 12 * 65 / 56) */
/* 3 + 2 - 4 + 5 / 7 + (6 * 2) */
/* 17 * 1 + (2 - 1 * 3 * 9) */
/* 1 / 2 * 3 / (4 + 5 - 6 / 7 * 8) */