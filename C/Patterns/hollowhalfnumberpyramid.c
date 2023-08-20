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

/*
Enter the dimension:9
1 
1 2
1   3
1     4
1       5
1         6
1           7
1             8
1 2 3 4 5 6 7 8 9
*/