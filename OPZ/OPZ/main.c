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
    gets(strin);    /* ���� �p������������� ��p������ */
    while (strin[k] != '\0')    /* ������������ ������, ���� �� ������ �� ����� �����. ��������� */
    {
        if ((strin[k] >= '1' && strin[k] <= '9') || strin[k] == ' ')    /* ���� ���p����� ������ - �����, ��  ���������� � � ������ ������*/
        {
            outstring[point++] = strin[k];
            k++;
            continue;
        }

        if (strin[k] == '(')    /* ���� ���p����� ������ - (, �� ���������� � � ����*/
        {
            push(k++);
            continue;
        }

        if (strin[k] == ')')   /* ���� ���p����� ������ - ), �� ���������� ��� ������� �� ( � ������ ������*/
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
            if (tos == 0)   /* ���� ���� ����, ������ ���������� ������ � ���� */
            {
                push(k++);
                continue;
            }

            if (prior(strin[k]) > prior(stack[tos - 1]))  /* ���� ���� �� ����, � �������������� ������ ���� �� ����������, ��� ����� �� ������� �����, ������ ���������� ������ � ���� */
            {
                push(k++);
                continue;
            }

            if (prior(strin[k]) <= prior(stack[tos - 1]))     /* ���� ���� �� ����, � �������������� ������ ���� �� ����������, */
            {                                               /* ��� ������ �� ������� �����, ����������� ��� ������� ���� ��� ������ �� ����������, */
                deleteElementInStack();                     /* � �������������� ������ �������� �� ������� ����� */
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

    if (tos != 0)   /* ���� ���� �� ����, ����������� ��� ������� � ������ ������ */
    {
        for (int n = tos - 1; n >= 0; n--)
        {
            outstring[point++] = stack[n];
            stack[tos - 1] = stack[tos];
        }
    }
    printf("%s", outstring);    /* ������� �������� ��������� */
}

/* ������� push ���������� � ���� �������������� ������. ����p����� ��������� �� ����� ��p���� ����� */
void push(int number)
{
    stack[tos] = strin[number];
    tos++;
}

/* ������� deleteElementInStack ���������� ������ � ������� ����� � ������ ������ � ������� ������ � �������. �������� ��������� �� ��p���� ����� */
void deleteElementInStack()
{
    outstring[point++] = stack[tos - 1];
    stack[tos - 1] = stack[tos];
    tos--;
}

/* ������� pop ������� �������� �� ������� ����� */
char pop()
{
    if (tos < 0)
        return '0';
    else
        return stack[tos - 1];
}

/* ������� prior ����p����� �p��p���� �p���. ���p���� */
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