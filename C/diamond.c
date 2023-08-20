#include<stdio.h>

int main(){
	int x;
	scanf("%d",&x,printf("Enter the dimension:"));

	for(int i=1;i<=x;i++){
		for(int j=i;j<x;j++)
			printf(" ");
		for(int j=1;j<=i;j++)
			printf("* ");
		printf("\n");
	}
	for(int i=x-1;i>=1;i--){
		for(int j=i;j<x;j++)
			printf(" ");
		for(int j=1;j<=i;j++)
			printf("* ");
		printf("\n");
	}
}