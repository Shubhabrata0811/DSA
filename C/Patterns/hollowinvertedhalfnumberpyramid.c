#include<stdio.h>

void rightpyramid(){
    int x;
	scanf("%d",&x,printf("Enter the dimension:"));
    for(int i=1;i<=x;i++){
        if(i==1){
            for(int j=1;j<=x;j++)
                printf("%d ",j);
        }else{
            for(int j=i;j<=x;j++){
                if(j==i || j==x){
                    printf("%d ",j);
                }else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
    return;
}

/*
Enter the dimension:5
1 2 3 4 5 
2     5
3   5
4 5
5
*/

void leftpyramid(){
    int x;
	scanf("%d",&x,printf("Enter the dimension:"));
    for(int i=1;i<=x;i++){
        if(i==1){
            for(int j=1;j<=x;j++)
                printf("%d ",j);
        }else{
            for(int j=1;j<=x;j++){
                if(j==i || j==x){
                    printf("%d ",j);
                }else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
    return;
}

int main(){
    rightpyramid();
    leftpyramid();
    return 0;
}