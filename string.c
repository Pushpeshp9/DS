#include<stdio.h>

void strCopy(char *string1, char *string2)
{
    int i;
    for(i=0;*(string1+i)!='\0';++i)
        *(string2+i) = *(string1+i);
}

void strconcat(char *string1, char *string2)
{
    int i,j;
    for(i=0;*(string1+i)!='\0';++i);
    for(j=0;*(string2+j)!='\0';++j)
        *(string1+i+j) = *(string2+j);
}

int strcomp(char *string1, char *string2)
{
    int i;
    for(i=0;*(string1+i)!='\0' || *(string2+i)!='\0'; ++i)
        if(*(string2+i)!=*(string1+i))
            return *(string2+i)-*(string1+i);
    return 0;
}

void Strrev(char *string1)
{
    int len,i;
    char temp;
    for(len=0;*(string1+len)!='\0';++len);
    for(i=0; i<len/2; ++i)
        {
            temp = *(string1+len-1-i);
            *(string1+len-1-i) = *(string1+i);
            *(string1+i) = temp;
        }
}

int main()
{
    int ch, res;
    char string1[50];
    char string2[50];

    printf("Enter first string: ");
    scanf("%s", string1);

    printf("\nWhich operation you want to perform:\n1.String copy\n2.String concatenation\n3.String comparison\n4.String reversal\n[1/2/3/4]: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1: strCopy(string1, string2);
                printf("The copied string: %s\n", string2);
                break;

        case 2: printf("Enter second string: ");
                scanf("%s", string2);
                strconcat(string1, string2);
                printf("Concatinated string: %s", string1);
                break;

        case 3: printf("Enter second string: ");
                scanf("%s", string2);
                res = strcomp(string1, string2);
                if(res == 0)
                    printf("Strings are equal\n");
                else    
                    printf("Strings are not equal\n");
                break;
        
        case 4: Strrev(string1);
                printf("Reversed String: %s\n", string1);
                break;

        default: printf("Wrong choice!!\n");
                 break;
    }
    return 0;
}