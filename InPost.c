#include<stdio.h>

char stack[50];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precendence(char ch)
{
    if(ch == '$' || ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else if (ch=='(')
        return 0;
}

void evaluate(char infix[], char postfix[])
{
    int i=0, p=0;
    char ch;

    while((ch=infix[i])!='\0')
    {
        switch (ch)
        {
            case '(': push(ch);
                      break;

            case ')': while(top!= -1 && stack[top]!= '(')
                        postfix[p++] = pop();
                      pop();
                      break;

            case '/':
            case '*':
            case '+':
            case '-': while(top!=-1 && precendence(stack[top]>=precendence(ch)))
                        postfix[p++] = pop();
                      push(ch);
                      break;

            case '$':
            case '^': while(top!=-1 && precendence(stack[top]>precendence(ch)))
                        postfix[p++] = pop();
                      push(ch);
                      break;

            default: postfix[p++] = ch;
                     break;
        }
        ++i;
    }
    while(top!= -1)
        postfix[p++] = pop();
    postfix[p] = '\0';
}

int main()
{
    char infix[50], postfix[50];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    evaluate(infix, postfix);

    printf("The postifx expression:\n%s\n", postfix);
    return 0;
}