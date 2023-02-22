#include<stdio.h>

void printarr(int *arr,int lenghth)
{
    for(int i=0;i<lenghth;i++)
    {
        printf("\t%d",arr[i]);
    }
    return;
}

void insertionsort(int *arr,int length)
{
    for(int i=1;i<length;i++)
    {
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    return;
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
    insertionsort(arr,length);
    printf("\nSorted array:");
    printarr(arr,length);
    return 0;
}