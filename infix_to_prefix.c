#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

void push(int);
char pop();
void infixtoprefix();
int priority(char);

char stack[20], infix[20], prefix[20];
int top = -1;

int main()
{
    int cont;
    printf("\n Enter the Infix Expression : ");
    scanf("%s", infix);
    infixtoprefix();
    return 0;
}

void push(int pos)
{

    if (top == MAX - 1)
    {
        printf("stackfull!!!!");
    }

    else
    {
        top++;
        stack[top] = infix[pos];
    }
}

char pop()
{
    char ch;

    if (top < 0)
    {
        printf("stackempty!!!!");
        exit(0);
    }
    else
    {
        ch = stack[top];
        stack[top] = '\0';
        top--;
        return (ch);
    }
    return 0;
}

void infixtoprefix()
{
    int i = 0, j = 0;

    strrev(infix);

    while (infix[i] != '\0')
    {

        if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            prefix[j] = infix[i];
            j++;
            i++;
        }

        else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            push(i);
            i++;
        }

        else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            if (infix[i] == '(')
            {
                while (stack[top] != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
                i++;
            }

            else if (infix[i] == '[')
            {
                while (stack[top] != ']')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
                i++;
            }

            else if (infix[i] == '{')
            {
                while (stack[top] != '}')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
                i++;
            }
        }

        else
        {
            if (top == -1)
            {
                push(i);
                i++;
            }

            else if (priority(infix[i]) < priority(stack[top]))
            {
                prefix[j] = pop();
                j++;

                while (priority(stack[top]) > priority(infix[i]))
                {
                    prefix[j] = pop();
                    j++;
                    if (top < 0)
                    {
                        break;
                    }
                }
                push(i);
                i++;
            }

            else if (priority(infix[i]) >= priority(stack[top]))
            {
                push(i);
                i++;
            }
        }
    }

    while (top != -1)
    {
        prefix[j] = pop();
        j++;
    }

    strrev(prefix);
    prefix[j] = '\0';
    printf("The converted prefix expression is : %s ", prefix);
}

int priority(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return (1);
    }

    if (ch == '*' || ch == '/')
    {
        return (2);
    }

    if (ch == '$')
    {
        return (3);
    }
    return 0;
}
