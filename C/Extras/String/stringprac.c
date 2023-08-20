#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "mystring.h"

/*
strcat();
strlen();
strcpy();
strcmp();
strrev();
*/
int main(){
    // char s1[40];
    //printf("Enter s1:");
    //gets(s1);
    char *s1 = "LogAn";
    printf("Before changing\ns1 = %s\ns2=\n",s1);
    mstrtoupper_cp(&s1);
    //mstrtolower(s2);
    printf("After swapping\ns1 = %s\ns2=\n",s1);
    return 0;
}