#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x,printf("Enter the dimension:"));
    for(int i=x;i>=1;i--){
        if(i==1 || i==x){
            for(int j=i;j<x;j++){
                printf(" ");
            }
            for(int j=1;j<=i;j++){
                printf("* ");
            }
        }
        else{
            for(int j=i;j<x;j++){
                printf(" ");
            }
            for(int j=1;j<=i;j++){
                if(j==1 || j==i)
                    printf("* ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    for(int i=2;i<=x;i++){
        if(i==x){
            for(int j=1;j<=i;j++){
                printf("* ");
            }
        }
        else{
            for(int j=i;j<x;j++){
                printf(" ");
            }
            for(int j=1;j<=i;j++){
                if(j==1 || j==i)
                    printf("* ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}