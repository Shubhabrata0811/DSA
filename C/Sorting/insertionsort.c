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
    //Unit testing
    int arr[]={1,2,3,4,5,6,7,8,9,10};//sorted array
    int arr2[]={10,9,8,7,6,5,4,3,2,1};//reverse sorted array
    int arr3[]={4,8,2,6,1,9,5,3,7,10};//random array
    int arr4[]={1,1,1,1,1,1,1,1,1,1};//same element array
    int arr5[]={1};//single element array
    printf("\nBefore sorting arr\n");
    printarr(arr,10);
    printf("\nAfter sorting\n");
    insertionsort(arr,10);
    printarr(arr,10);
    printf("\nBefore sorting arr2\n");
    printarr(arr2,10);
    printf("\nAfter sorting\n");
    insertionsort(arr2,10);
    printarr(arr2,10);
    printf("\nBefore sorting arr3\n");
    printarr(arr3,10);
    printf("\nAfter sorting\n");
    insertionsort(arr3,10);
    printarr(arr3,10);
    printf("\nBefore sorting arr4\n");
    printarr(arr4,10);
    printf("\nAfter sorting\n");
    insertionsort(arr4,10);
    printarr(arr4,10);
    printf("\nBefore sorting arr5\n");
    printarr(arr5,1);
    printf("\nAfter sorting\n");
    insertionsort(arr5,1);
    printarr(arr5,1);
    return 0;
} 