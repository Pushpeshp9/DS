#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *matrix[3], sum_all=0, sum_primary_diagonal=0, sum_secondary_diagonal=0, i,j;

    for(i=0;i<3;++i)
        matrix[i] = (int *)malloc(3*sizeof(int));

    printf("Enter the elements of matrix: \n");
    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            scanf("%d", (*(matrix+i))+j);

    printf("The Matrix:\n");
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
            printf("%d ", *(*(matrix+i)+j));
        printf("\n\n");
    }

    for(i=0;i<3;++i)
    {
        sum_primary_diagonal+=*(*(matrix+i)+i);
        sum_secondary_diagonal+=*(*(matrix+i)+(2-i));
    }

    printf("Sum of element of the primary diagonal is %d and that of the secondary diagonal is %d\n\n", sum_primary_diagonal,sum_secondary_diagonal);
    return 0;
}