#include<stdio.h>

int main(){
    char c = -128;
    /*while(1){
        printf("\n%c = %d",c,c);
        c++;
        if(c==-128)
            break;
    }*/
    do{
        printf("\n%c = %d",c,c);
        c++;
    }while(c!=-128);
    return 0;
}