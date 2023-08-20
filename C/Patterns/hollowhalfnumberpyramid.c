#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x,printf("Enter the dimension:"));
    for(int i=1;i<=x;i++){
        if(i!=x){
            for(int j=1;j<=i;j++){
                if(j==1 || j==i){
                    printf("%d ",j);
                }else{
                    printf("  ");
                }
            }
        }else{
            for(int j=1;j<=i;j++){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}