#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

int main()
{
    /*char x=-128; 
    while(x<=127){
        printf("\n%d = %c",x,x);
        x++;
        if(x==127)
            break;
    }*/
    char str[50],c;
    char new[50];
    //char *new;
    int j=0;
    printf("\nEnter the string:");
    gets(str);
    scanf("%c",&c,printf("Enter the c:"));
    printf("\nThe string is:%s",str);
    for(int i=0;i<strlen(str);i++){
        if(str[i]==c)
            continue;
        new[j++]=str[i];
    }
    new[j]='\0';
    printf("\n%s",new);
    return 0; 
}