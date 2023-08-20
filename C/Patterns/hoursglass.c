#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x,printf("Enter the dimension:"));
    for(int i=x;i>=1;i--){
        for(int j=i;j<x;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    for(int i=2;i<=x;i++){
        for(int j=i;j<x;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}