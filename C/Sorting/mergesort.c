#include<stdio.h>

void merge(int *arr,int low,int mid, int high)
{

    int temparr1[mid-low+1];
    int temparr2[high-mid];
    int ta1i,ta2i,ai;
    ai=low;
    for(int i=0;i<mid-low+1;i++)
    {
        temparr1[i]=arr[low+i];
    }
    for(int i=0;i<high-mid;i++)
    {
        temparr2[i]=arr[mid+1+i];
    }
    ta1i=ta2i=0;
    while(ta1i<mid-low+1 && ta2i<high-mid)
    {
        if(temparr1[ta1i]<temparr2[ta2i])
        {
            arr[ai++]=temparr1[ta1i++];
        }
        else
        {
           arr[ai++]=temparr2[ta2i++];
        }
    }
    while(ta1i<mid-low+1)
    {
        arr[ai++]=temparr1[ta1i++];
    }
    while(ta2i<high-mid)
    {
        arr[ai++]=temparr2[ta2i++];
    }
    return;
}

void mergesort(int *arr,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;  
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void printarray(int *array,int length)
{
    for(int i=0;i<length;i++)
    {
        printf("\t%d",array[i]);
    }
}

int main()
{
    int arr[100],noele;
    scanf("%d",&noele,printf("\nEnter the number of elements:"));
    printf("\nEnter %d values : ",noele);
    for(int i=0;i<noele;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nThe user entered array is :");
    printarray(arr,noele);
    mergesort(arr,0,noele-1);
    printf("\nThe sorted array is :");
    printarray(arr,noele);
    return 0;
}