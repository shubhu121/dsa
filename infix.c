#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<string.h>
 
#define MAX 20
 
void push(int);
char pop();
void in2prefix();
int priority ( char );
 
char stk[20],infix[20],postfix[20];
int top=-1;
 
 
int main()
{
    int cont;
    printf("\n Enter the Infix Expression : ");
    scanf("%s",infix);
    in2prefix();
    return 0;
}
 

void push(int pos)
{
 
    if(top==MAX-1)
    {
        printf("stackfull!!!!");
    }
 
    else {
        top++;
        stk[top] = infix[pos];
    }
}

char pop()
{
    char ch;
 
    if(top < 0)
    {
        printf("stackempty!!!!");
        exit(0);
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
 

void in2prefix()
{
    int i=0,j=0;
 
    strrev(infix);
   
    while(infix[i]!='\0')
    {
 
        if(infix[i]>='a' && infix[i]<='z')        
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
 
   
        else if(infix[i]==')' || infix[i]=='}'  || infix[i]==']')      
            {
                push(i);
                i++;
            }
   
        else if(infix[i]=='(' || infix[i]=='{'  || infix[i]=='[')      
        {
            if(infix[i]=='(')
            {
                while(stk[top]!=')')        
                {
                    postfix[j]=pop();
                    j++;
                }
                pop();
                i++;
            }
 
            else if(infix[i]=='[')
            {
                while(stk[top]!=']')    
                {
                    postfix[j]=pop();
                    j++;
                }
                pop();
                i++;
            }
 
            else if(infix[i]=='{')
            {
            while(stk[top]!='}')    
                {
                    postfix[j]=pop();
                    j++;
                }
                pop();
                i++;
            }
        }
       
     
        else            
        {
            if(top==-1)        
            {
                push(i);
                i++;
            }

            else if( priority(infix[i]) < priority(stk[top]))
            {
                postfix[j]=pop();
                j++;
           
                while(priority(stk[top]) > priority(infix[i])){
                    postfix[j] = pop();
                    j++;
                    if(top < 0) {
                        break;
                    }
                }
                push(i);
                i++;
            }
           
            else if(priority(infix[i]) >= priority(stk[top]))
            {
                push(i);
                i++;
            }
        }
    }

    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
   

    strrev(postfix);
    postfix[j]='\0';
    printf("The converted postfix string is : %s ",postfix);
}
 

int priority ( char alpha )
{
    if(alpha == '+' || alpha =='-')
    {
        return(1);
    }
 
    if(alpha == '*' || alpha =='/')
    {
        return(2);
    }
 
    if(alpha == '$')
    {
        return(3);
    }
    return 0;
}
