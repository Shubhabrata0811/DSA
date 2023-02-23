#include<stdio.h>

void printarr(int *arr,int lenghth)
{
    for(int i=0;i<lenghth;i++)
    {
        printf("\t%d",arr[i]);
    }
    return;
}

void swap(int *arr,int p1,int p2)
{
    int temp = arr[p1];
    arr[p1]=arr[p2];
    arr[p2]=temp;
    return;
}

void bubblesort(int *array,int length)
{
    for(int i=0;i<length-1;i++)
    {
        for(int j=0;j<length-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array,j,j+1);
            }
        }
    }
}

int main()
{
    int arr[100],length;
    scanf("%d",&length,printf("\nEnter the number of elements:"));
    printf("\nEnter %d elements:",length);
    for(int i=0;i<length;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nUser entered array:");
    printarr(arr,length);
    bubblesort(arr,length);
    printf("\nSorted array:");
    printarr(arr,length);
    return 0;
}
