#include<stdio.h>

int main(){
	int x;
	scanf("%d",&x,printf("Enter the dimension:"));
	for(int i=x;i>=1;i--){
		for(int j=1;j<=x-i;j++)
			printf(" ");
		for(int j=1;j<=i;j++)
			printf("* ");
		printf("\n");
	}
	return 0;
}