#include <stdio.h>
#include <stdlib.h>

void printarray(int *array,int length)
{
    for(int i=0;i<length;i++)
    {
        printf("\t%d",array[i]);
    }
}
void merge(int *array,int low,int mid,int high)
{
    int tempa1[mid-low+1];
    int tempa2[high-mid];
    int ta1i,ta2i,ai;
    ta1i=ta2i=0;
    ai=low;
    for(int i=0;i<mid-low+1;i++)
    {
        tempa1[i]=array[low+i];
    }
    for(int i=0;i<high-mid;i++)
    {
        tempa2[i]=array[mid+1+i];
    }
    while(ta1i<mid-low+1 && ta2i<high-mid)
    {
        if(tempa1[ta1i]<tempa2[ta2i])
        {
            array[ai++]=tempa1[ta1i++];
        }
        else
        {
            array[ai++]=tempa2[ta2i++];
        }
    }
    for(;ta1i<mid-low+1;)
    {
        array[ai++]=tempa1[ta1i++];
    }
    for(;ta2i<high-mid;)
    {
        array[ai++]=tempa2[ta2i++];
    }
}

void mergesort(int *array,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(array,low,mid);
        mergesort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}
int main()
{
    int array[100];
    int length;
    scanf("%d",&length,printf("\nEnter the length of the array:"));
    printf("\nEnter %d values:",length);
    for(int i=0;i<length;i++)
    {
        scanf("%d",&array[i]);
    }
    mergesort(array,0,length-1);
    printf("\nThe sorted array:");
    printarray(array,length);
    return 0;
}
