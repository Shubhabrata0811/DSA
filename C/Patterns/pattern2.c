#include<stdio.h>

int main(){
	int x;
	scanf("%d",&x,printf("\nEnter the dimension:"));
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x-i;j++){
			printf(" ");
		}
		for(int j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

/*
Enter the dimension:5                                                                                                                                                                   
    *                                                                                                                                                                                   
   **                                                                                                                                                                                   
  ***                                                                                                                                                                                   
 ****                                                                                                                                                                                   
***** 
*/