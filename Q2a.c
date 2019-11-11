#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *matrix1[3], *matrix2[3], *product[3],i,j,k;

    for(i=0;i<3;++i)
    {
        matrix1[i] = (int *)malloc(3*sizeof(int));
        matrix2[i] = (int *)malloc(3*sizeof(int));
        product[i] = (int *)malloc(3*sizeof(int));
    }

    printf("Enter the elements of matrix1: \n");
    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            scanf("%d", (*(matrix1+i))+j);

    printf("Enter the elements of matrix2: \n");
    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            scanf("%d", (*(matrix2+i))+j);

    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            *(*(product+i)+j) = 0;

    for(i=0;i<3;++i)
        for(j=0;j<3;++j)
            for(k=0;k<3;++k)
                *(*(product+i)+k) += *(*(matrix1+i)+k) * *(*(matrix2+j)+k);

    printf("The Product Matrix:\n");
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
            printf("%d ", *(*(product+i)+j));
        printf("\n\n");
    }

    return 0;
}