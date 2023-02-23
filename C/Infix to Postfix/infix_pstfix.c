#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    //int size;
    int top;
    char arr[100];
};

typedef struct stack stack;

char pop(stack *st)
{
    char popc;
    popc= st->arr[st->top--];
    return popc;
}

void push(stack *st,char pushc)
{
    if(st->top<100)
    {
        st->arr[++st->top]=pushc;
    }
    else
    {
        printf("\nStack overflow!!");
    }
    return;
}

int isempty(stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isoperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')')
    {
        return 1;
    }
    return 0;
}

int precedence(char c)
{
    switch(c)
    {
        case '^':return 3;
        case '/':
        case '*':return 2;
        case '+':
        case '-':return 1;
        default: return 0;
    }
}

void infix_to_postfix(char* infix,char *postfix)
{
    int i=0,p=0;
    char next;
    stack st;
    st.top=-1;
    while(infix[i]!='\0')
    {
        if(!isoperator(infix[i]))
        {
            postfix[p++]=infix[i++];
        }
        else
        {
            switch(infix[i])
            {
                case '(':push(&st,infix[i]);break;
                case ')':
                {
                    next=pop(&st);
                    while(next!='(')
                    {
                        postfix[p++]=next;
                        next=pop(&st);
                    }
                    break;
                }
                case '^':
                case '/':
                case '*':
                case '+':
                case '-':
                {
                    while(precedence(st.arr[st.top])>=precedence(infix[i]) && st.top!=-1)
                    {
                        postfix[p++]=pop(&st);
                    }
                    push(&st,infix[i]);
                    break;
                }
                default: break;
            }
            i++;
        }
    }
    while(st.top!=-1)
    {
        postfix[p++]=pop(&st);
    }
    postfix[p++]='\0';
}

int main()
{
    char infix[100],postfix[100];
    printf("\nEnter Infix expression:");
    gets(infix);
    infix_to_postfix(infix,postfix);
    printf("\nPostfix expression: %s",postfix);
    return 0;
}