#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter the string over th alphabets {a,b,c}: ");
    scanf("%s",s);
    int q=0,p;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]!='a'&&s[i]!='b'&&s[i]!='c')
        {
            printf("Invalid String");
        }
    
     p=q;
     switch(q)
     {
        case 0:q=(s[i]=='a')?1:0; break;
        case 1:q=(s[i]=='b')?2:
               (s[i]=='a')?1:0; break;
        case 2:q=(s[i]=='c')?3:
               (s[i]=='a')?1:0; break;
        case 3:(s[i]=='a')?1:0; break;
     }
     printf("q%d---%c--->q%d\n",p,s[i],q);
    }
    if(q==3)
    printf("String accepted");
    else
    printf("String not accepted");
    return 0;
}


---Output:
  Enter the string over th alphabets {a,b,c}: ababc 
q0---a--->q1
q1---b--->q2
q2---a--->q1
q1---b--->q2
q2---c--->q3
String accepted