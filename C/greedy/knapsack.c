#include<stdio.h>
#define SIZE 4
struct element
{
    float p;
    float w;
    float r;
    int enindex;
};
typedef struct element element;

element newele()
{
    element new;
    static int a=1;
    new.enindex=a;
    printf("\nEnter %d elements data:",a);
    scanf("%f",&new.p,printf("\nEnter the profit of new element:"));
    scanf("%f",&new.w,printf("\nEnter the maximum available weight of new element:"));
    new.r=new.p/new.w;
    a++;
    return new;
}
float total(float *arr)
{
    float sum=0;
    for(int i=0;i<SIZE;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
float main()
{
    element arr[SIZE];
    float profit[SIZE];
    float weight[SIZE];
    float maxweight;
    int j;
    scanf("%f",&maxweight,printf("\nEnter the maximum available weight of knapsack:"));
    element se;
    for(int i=0;i<SIZE;i++)
    {
        arr[i]=newele();
    }
    printf("\nAvailable elments: ");
    for(int i=1;i<SIZE;i++)
    {
        j=i-1;
        se=arr[i];
        while(j>-1 && arr[j].r>se.r)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=se;
    }
    for(int k=0;k<SIZE;k++)
    {
        printf("\n%d.(user index = %d , p = %.2f , w = %.2f , r = %.2f)",k+1,arr[k].enindex,arr[k].p,arr[k].w,arr[k].r);
    }
    for(int i=SIZE-1;i>-1;i--)
    {
        if(arr[i].w>=maxweight)
        {
            weight[i]=maxweight;
            profit[i]=weight[i]*arr[i].r;
            maxweight=0;
        }
        else
        {
            weight[i]=arr[i].w;
            profit[i]=arr[i].p;
            maxweight-=weight[i];
        }
    }
    printf("\nTotal weight taken %.2f.",total(weight));
    printf("\nTaken weight :");
    for(int j=0;j<SIZE;j++)
    {
        printf("%d. %.2f\t",j+1,weight[j]);
    }
    printf("\nProfit list :");
    for(int j=0;j<SIZE;j++)
    {
        printf("%d. %.2f\t",j+1,profit[j]);
    }
    printf("\nTotal profit %.2f.",total(profit));
    return 0;
}