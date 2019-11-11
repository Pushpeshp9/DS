#include <stdio.h>
#include <math.h>
#define PI 3.14159f

int factorial(int n);
float sine(float , int);
int i;

void main(){
    float degree;
    float radian;
    float result;
    int n;
    printf("Enter the angle in degree: ");
    scanf("%f",&degree);
    printf("Enter the iteration: ");
    scanf("%d",&n);
    radian = degree * PI / 180;
    result = sine(radian,n);
    printf("%d",factorial(n));
    printf("\n");
    printf("sin%.2f = %.3f",degree,result);
}

int factorial(int n)
{
    if(n==0)
        return 1;
    else if (n==1)
        return 1;
    else
        return (n*factorial(n-1));
}

float sine(float an, int n)
{
    if (an==0)
        return 0;
    else if(n>=0)
        if(n%2==1)
            return (sine(an,n-2) - pow(an,n)/factorial(n)) * pow(-1,n);
        else
            return (sine(an,2*n-1) - pow(an,2*n+1)/factorial(2*n+1)) *-1 ;
}
