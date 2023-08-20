#include<stdio.h>
int main(){
	int x;
	scanf("%d",&x,printf("Enter the dimension:"));
	for(int i=1;i<=x;i++){
		for(int j=1;j<=x-i;j++){
			printf(" ");
		}10
		for(int j=1;j<=i;j++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}

/*
Enter the dimension:10
         *                                                                                                                                                                              
        * *                                                                                                                                                                             
       * * *                                                                                                                                                                            
      * * * *                                                                                                                                                                           
     * * * * *                                                                                                                                                                          
    * * * * * *                                                                                                                                                                         
   * * * * * * *                                                                                                                                                                        
  * * * * * * * *                                                                                                                                                                       
 * * * * * * * * *                                                                                                                                                                      
* * * * * * * * * * 
*/