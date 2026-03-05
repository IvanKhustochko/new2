#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK 10000

int stack[MAX_STACK];
int top = -1;

void push(int value) 
{
    stack[++top] = value;
}
int pop() 
{
    return stack[top--];
}

int main() 
{
    char token[100];
    int a, b;
    while (scanf("%s", token) == 1) 
    {
        int len = strlen(token);
        if (token[len - 1] == '.') 
        {

            token[len - 1] = '\0';
            if (len > 1) 
            {
                if (token[0] == '+') 
                {
                    b = pop();
                    a = pop();
                    push(a + b);
                }
                else if (token[0] == '-') 
                {
                    b = pop();
                    a = pop();
                    push(a - b);
                }
                else if (token[0] == '×' || token[0] == '*') 
                {
                    b = pop();
                    a = pop();
                    push(a * b);
                }
                else if (token[0] == '/') 
                {
                    b = pop();
                    a = pop();
                    push(a / b);
                }
                else 
                {
                    push(atoi(token));
                }
            }
            break;
        }
        
        if (token[0] == '+') 
        {
            b = pop();
            a = pop();
            push(a + b);
        }
        else if (token[0] == '-') 
        {
            b = pop();
            a = pop();
            push(a - b);
        }
        else if (token[0] == '×' || token[0] == '*') 
        {
            b = pop();
            a = pop();
            push(a * b);
        }
        else if (token[0] == '/') 
        {
            b = pop();
            a = pop();
            push(a / b);
        }
        else 
        {
            push(atoi(token));
        }
    }
    printf("%d\n", pop());
    
    return 0;
}
