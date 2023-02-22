#include<stdio.h>
#define SIZE 10

void swap(int *arr, int i1, int i2)
{
    int s = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = s;
}

int partition(int *arr, int low, int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,high);
    return (i+1);
}
void quicksort(int *arr, int lowi, int highi)
{
    int j;
    if(lowi<highi)
    {
        j=partition(arr,lowi,highi);
        quicksort(arr,lowi,j-1);
        quicksort(arr,j+1,highi);
    }
    return;
}
void printarr(int *arr)
{
    for(int i=0;i<SIZE;i++)
    {
        printf("\t%d",arr[i]);
    }
    return;
}
int main()
{
    int arr[SIZE];
    printf("\nEnter %d elements:",SIZE);
    for(int i=0;i<SIZE;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nUser entered array:");
    printarr(arr);
    quicksort(arr,0,SIZE-1);
    printf("\nSorted array:");
    printarr(arr);
    return 0;
}