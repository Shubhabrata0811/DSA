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
void printarr(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("\t%d",arr[i]);
    }
    return;
}
int main()
{
    //Unit testing
    int arr[]={1,2,3,4,5,6,7,8,9,10};//sorted array
    int arr2[]={10,9,8,7,6,5,4,3,2,1};//reverse sorted array
    int arr3[]={1,3,5,7,9,2,4,6,8,10};//random array
    int arr4[]={1,1,1,1,1,1,1,1,1,1};//same element array
    int arr5[]={1};//single element array
    int arr6[]={2,1};//two element array
    int negarr[]={-5,-4,-1,0,1,2,-3,-2,3,4};//negative array
    printf("\n Before sorting arr");
    printarr(arr,SIZE);
    quicksort(arr,0,SIZE-1);
    printf("\n After sorting arr");
    printarr(arr,SIZE);
    printf("\n Before sorting arr2");
    printarr(arr2,SIZE);
    quicksort(arr2,0,SIZE-1);
    printf("\n After sorting arr2");
    printarr(arr2,SIZE);
    printf("\n Before sorting arr3");
    printarr(arr3,SIZE);
    quicksort(arr3,0,SIZE-1);
    printf("\n After sorting arr3");
    printarr(arr3,SIZE);
    printf("\n Before sorting arr4");
    printarr(arr4,SIZE);
    quicksort(arr4,0,SIZE-1);
    printf("\n After sorting arr4");
    printarr(arr4,SIZE);
    printf("\n Before sorting arr5");
    printarr(arr5,1);
    quicksort(arr5,0,0);
    printf("\n After sorting arr5");
    printarr(arr5,1);
    printf("\n Before sorting arr6");
    printarr(arr6,2);
    quicksort(arr6,0,1);
    printf("\n After sorting arr6");
    printarr(arr6,2);
    printf("\n Before sorting negarr");
    printarr(negarr,SIZE);
    quicksort(negarr,0,SIZE-1);
    printf("\n After sorting negarr");
    printarr(negarr,SIZE);
    return 0;
}