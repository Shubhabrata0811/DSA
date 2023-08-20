#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x,printf("Enter the dimension:"));
    for(int i=1;i<=x;i++){
        if(i!=x){
            for(int j=1;j<=x-i;j++){
                printf(" ");
            }
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

/*
Enter the dimension:5
    1 
   1 2
  1   3
 1     4
1 2 3 4 5
*/