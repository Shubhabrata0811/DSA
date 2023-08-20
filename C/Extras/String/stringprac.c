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
    char s1[100], s2[100];
    printf("Enter the 1st string:");
    gets(s1);
    //fflush(stdin);
    printf("Enter the second string:");
    gets(s2);
    //fflush(stdin);
    if(mstrcheckanagram(s1,s2))
        printf("\n%s and %s are anagram!",s1,s2);
    else
        printf("\n%s and %s are not anagram!",s1,s2);
    return 0;
}