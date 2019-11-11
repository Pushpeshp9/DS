#include<stdio.h>
#define maxsize 5

struct student
{
    char name[30];
    char usn[11];
};

struct student stack[maxsize];
int top = -1;

void push(struct student element)
{
    if(top == maxsize-1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = element;
}

struct student pop()
{
        return stack[top--];
}

void display()
{
    if(top == -1)
        printf("Stack Underflow!\n");
    else
    {
        int i;
        for(i=top;i>-1;--i)
            printf("\nName: %s\nUSN: %s\n", stack[i].name, stack[i].usn);
    }

}

int main()
{
    struct student stud;
    int op;
    char ch;
    do
    {
        printf("\n\nOperation to perform:\n1.Push\n2.Pop\n3.Display\n[1/2/3]: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1: printf("Enter Student's name: ");
                    scanf("%s", stud.name);
                    printf("Enter Student's USN: ");
                    scanf("%s", stud.usn);
                    push(stud);
                    break;

            case 2: if(top==-1)
                        printf("Stack Underflow!\n");
                    else
                    {
                        stud = pop();
                        printf("\nName: %s\nUSN: %s\nPopped!\n", stud.name, stud.usn);
                    }
                    break;

            case 3: display();
                    break;

            default: printf("Wrong choice!!\n");
                     break;

        }
        printf("\nWant to perform more operations? [Y/N]: ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}