#include<stdio.h>
#include<conio.h>

int main()
{
    /*int i,j,k;
    for(i=1;i<150;i++)
    {
        j=i*57;
        printf("\n%d",j);
        if(j>99&&j<1000)
        {
            k=j%100;
            printf("\n%d",k);
            printf("\n%d",i);
            if(k==i)
            {
                printf("\nA number %d",j);
            }
        }
        if(j>999&&j<10000)
        {
            k=j%1000;
            printf("\n%d",k);
            printf("\n%d",i);
            if(k==i)
            {
                printf("\nA number %d",j);
            }
        }
        if(j>9999&&j<100000)
        {
            k=j%10000;
            printf("\n%d",k);
            printf("\n%d",i);
            if(k==i)
            {
                printf("\nA number %d",j);
            }
        }

    }*/
    int i;
    while(scanf("%d",&i,printf("\nEnter any non-digits for exit or enter any digits to continue:")))
    {
        printf("\nRunning!");
    }
    return 0;
}