#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>


//Convert a whole string to upper case

//using character array for strings
void mstrtoupper_ca(char *str){
    for(;*str;){
        if(isalpha(*str))
            *str = toupper(*str);
        str++;
    }
    return;
}
//using character pointer for strings (not arrays)
void mstrtoupper_cp(char **strp){
    char *temp = (char*) malloc((strlen(*strp)+1)*sizeof(char));
    strcpy(temp,*strp);
    temp[strlen(*strp)]='\0';
    char *cpy=temp;
    for(;*cpy;){
        printf("\n%c",*cpy);
        if(isalpha(*cpy))
            *cpy=toupper(*cpy);
        printf("\n%c",*cpy);
        cpy++;
    }
    printf("\n%s",temp);
    strcpy(*strp,temp);
    *(*strp+strlen(temp))='\0';
    free(temp);
    return;
}

//convert a whole string to lower case
//using character pointer for strings (not arrays)
void mstrtolower_cp(char **strp){
    
}
//using character array for strings
void mstrtolower_ca(char *str){
    for(;*str;){
        if(isalpha(*str))
            *str = tolower(*str);
        str++;
    }
    return;
}


//swap two string

//using character pointer for strings (not arrays)
void mstrswap_cp(char **s1p, char **s2p){
    char *temp = *s1p;
    *s1p = *s2p;
    *s2p = temp;
    return;
}

//using character array for strings
void mstrswap_ca(char *s1, char *s2){
    char *temp = (char*) malloc((strlen(s1)+1)*sizeof(char));
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
    free(temp);
    return;
}

//check given string is palindrome (case sensitive)
int mstrispalindrome(char *s){
    char *temp = (char*) malloc((strlen(s)+1)*sizeof(char));
    strcpy(temp,s);
    strrev(temp);
    if(!strcmp(temp,s))
        return 1;
    else
        return 0;
}