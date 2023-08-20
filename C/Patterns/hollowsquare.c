#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x,printf("Enter the dimenssion:"));
    for(int i=1;i<=x;i++){
        if(i==1 || i==x){
            for(int j=1;j<=x;j++)
                printf("* ");
        }
        else{
            for(int j=1;j<=x;j++){
                if(j==1 || j==x){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}