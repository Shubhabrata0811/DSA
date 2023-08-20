#include<stdio.h>

int main(){
    int d,h,i,j,sd=0;
    scanf("%d",&d,printf("Enter the dimension:"));
    h = (d*2)-1;
    for(i=1;i<=h;i+=2){
        for(j=1;j<=h-i;j++){
            printf(" ");
        }
        for(j=i-sd;j<=i;j++){
            printf("%d ",j);
        }
        for(j=j-2;j>=i-sd;j--){
            printf("%d ",j);
        }
        sd++;
        printf("\n");
    }

    return 0;
}