#include <stdio.h>
#include <stdlib.h>

struct job
{
    float profit;
    int deadline;
    int enjobindex;
};
typedef struct job job;

int jobnum;

job newjob()
{
    job njob;
    static int a=1;
    scanf("%f",&njob.profit,printf("\nEnter the profit of job %d",a));
    scanf("%d",&njob.deadline,printf("\nEnter the deadline of job %d",a));
    return njob;
}
int maxll(job *ja) //ja->to pass the "list of job"
{
    int maxdeadline;
    maxdeadline=ja[0].deadline;
    for(int i=1;i<jobnum;i++)
    {
        if(ja[i].deadline>maxdeadline)
        {
            maxdeadline=ja[i].deadline;
        }
    }
    return maxdeadline;
}
int partition(job *a,int l,int h)
{
    int i,j;
    job s;
    job pivot=a[l];
    i=l;j=h;
    while(i<j)
    {
        do{
            i++;
        }while(a[i].profit<=pivot.profit);
        do{
            j--;
        }while(a[j].profit>pivot.profit);
        if(i<j)
        {
            s=a[i];
            a[i]=a[j];
            a[j]=s;
        }
        return j;
    }
}
void quicksort(job *a,int l,int h)
{
    int ;
    if(l<h)
    {
        j=partition(a,l,j);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
    else
    {
        return;
    }
}
int main()
{
    int maxdeadline,timeperjob,nojdone;//timeperjob->"how much unit of time needs to complete a job",nojdone->"Number of job can be done"
    scanf("%d",&jobnum,printf("\nEntered the number of jobes available:"));
    scanf("%d",&timeperjob,printf("\nEntered how much unit of time needs to complete a job:"));
    job jobarr[10];
    for(int i=0;i<jobnum;i++)
    {
        jobarr[i]=newjob();
    }
    maxdeadline=maxdl(jobarr);
    nojdone=maxdeadline/timeperjob;
    quicksort(jobarr,0,jobnum-1); //sort the job array according to their profit
}