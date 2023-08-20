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
    //Unit testing
    int arr[]={1,2,3,4,5,6,7,8,9,10};//sorted array
    int arr2[]={10,9,8,7,6,5,4,3,2,1};//reverse sorted array
    int arr3[]={4,8,2,6,1,9,5,3,7,10};//random array
    int arr4[]={1,1,1,1,1,1,1,1,1,1};//same element array
    int arr5[]={1};//single element array
    printf("\nBefore sorting arr\n");
    printarray(arr,10);
    printf("\nAfter sorting\n");
    mergesort(arr,0,9);
    printarray(arr,10);
    printf("\nBefore sorting arr2\n");
    printarray(arr2,10);
    printf("\nAfter sorting\n");
    mergesort(arr2,0,9);
    printarray(arr2,10);
    printf("\nBefore sorting arr3\n");
    printarray(arr3,10);
    printf("\nAfter sorting\n");
    mergesort(arr3,0,9);
    printarray(arr3,10);
    printf("\nBefore sorting arr4\n");
    printarray(arr4,10);
    printf("\nAfter sorting\n");
    mergesort(arr4,0,9);
    printarray(arr4,10);
    printf("\nBefore sorting arr5\n");
    printarray(arr5,1);
    printf("\nAfter sorting\n");
    mergesort(arr5,0,0);
    printarray(arr5,1);
    return 0;
}