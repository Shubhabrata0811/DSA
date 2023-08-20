#include<stdio.h>

int main(){
	int x;
	scanf("%d",&x,printf("Enter the dimension:"));

	for(int i=x;i>=1;x--){
		for(int j=i;j<x;j++)
			printf(" ");
		for(int j=1;j<=i;j++)
			printf("* ");
		printf("\n");
	}
	for(int i=1;i<=x;x++){
		for(int j=i;j<x;j++)
			printf(" ");
		for(int j=1;j<=i;j++)
			printf("* ");
		printf("\n");
	}
	return 0;
}