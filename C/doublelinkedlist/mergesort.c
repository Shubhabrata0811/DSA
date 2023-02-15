#include<stdio.h>
#define SIZE 3

void merge(int *arr, int *newarr,int low,int mid, int high)
{
    int ai,bi,ci;
    ai=low;
    ci=low;
    bi=mid+1;
    while(ai<=mid && bi<=high)
    {
        if(arr[ai]<arr[bi])
        {
            newarr[ci++]=arr[ai++];
        }
        else
        {
            newarr[ci++]=arr[bi++];
        }
    }
    for(;ai<=mid;ai++)
    {
        newarr[ci++]=arr[ai];
    }
    for(;bi<=high;bi++)
    {
        newarr[ci++]=arr[bi];
    }
    printf("\nCurrent new arr :");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d  ",newarr[i]);
    }
    return;
}

void mergesort(int *arr, int *newarr,int low,int high)
{
    int mid=(low+high)/2;
    if(high==low)
    {
        return;
    }   
    mergesort(arr,newarr,low,mid);
    mergesort(arr,newarr,mid+1,high);
    merge(arr,newarr,low,mid,high);
}

int main()
{
    int arr[SIZE];
    int newarr[SIZE];
    printf("\nEnter 10 values : ");
    for(int i=0;i<SIZE;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nThe array is :");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d  ",arr[i]);
    }
    mergesort(arr,newarr,0,SIZE-1);
    printf("\nThe sorted array is :");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d  ",newarr[i]);
    }
    return 0;
}