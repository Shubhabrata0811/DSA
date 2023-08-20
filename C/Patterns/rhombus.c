#include<stdio.h>

int main(){
	int x;
	scanf("%d",&x,printf("Entere the dimension:"));
	for(int i=1;i<=x;i++){
		for(int j=i;j>1;j--){
			printf(" ");
		}
		for(int j=1;j<=x;j++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}