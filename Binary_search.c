#include<stdio.h>
int BinarySearch(int array[], int key, int lo, int hi)
{
    if(lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(key == array[mid])
            return mid+1;
        else if(key > array[mid])
            BinarySearch(array, key, mid+1, hi);
        else if(key < array[mid])
            BinarySearch(array, key, lo, mid-1);
    }
    else
        return -1;
    
}

int main()
{
    int array[10], key, i, pos=0;

    printf("Enter 10 elements: ");
    for(i=0;i<10;++i)
        scanf("%d", &array[i]);

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    pos = BinarySearch(array, key, 0, 10);
    if(pos!= -1)
        printf("Element found at location %d \n\n", pos);
    else
        printf("Element not found!!\n\n");

    return 0;
}