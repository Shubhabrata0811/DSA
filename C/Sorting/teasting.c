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

void selectionsort(int *arr,int length)
{
    int index_mini;
    for(int i=0;i<length-1;i++)
    {
        index_mini=i;
        for(int j=i+1;j<length;j++)
        {
            if(arr[j]<arr[index_mini])
            {
                index_mini=j;
            }
        }
        if(index_mini!=i)
        {
            swap(arr,i,index_mini);
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
    selectionsort(arr,length);
    printf("\nSorted array:");
    printarr(arr,length);
    return 0;
}