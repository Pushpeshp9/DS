#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *number, N, i, sum=0;
    printf("Enter N:");
    scanf("%d", &N);

    number = (int *)malloc(N*sizeof(int));

    printf("Enter N numbers: ");
    for(i=0; i<N; ++i)
        scanf("%d", number+i);

    for(i=0; i<N; ++i)
        sum += *(number+i);

    printf("\nThe Sum of N terms are %d\n", sum);
    return 0;
}