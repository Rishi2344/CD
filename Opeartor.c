code:
********************
#include<stdio.h>
#include<string.h>
void main()
{
   char stack[20],ip[20],opt[10][10][1],ter[10];
   int i,j,k,n,top=0,col,row;
   for(i=0;i<10;i++)
   {
      stack[i]=0;
      ip[i]=0;
      for(j=0;j<10;j++)
      {
        opt[i][j][1]=0;
      }
   }
   printf("Enter no of terminals:");
   scanf("%d",&n);
   printf("\nEnter the terminals:");
   scanf("%s",ter);
   printf("\nEnter the table values :");
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
        printf("\nEnter the value for%c%c : ",ter[i],ter[j]);
        scanf("%s",opt[i][j]);
     }
   }
   printf("\n operator precedence table : ");
   for(i=0;i<n;i++)
   {
      printf("\t %c",ter[i]);
   }
   printf("\n");
   for(i=0;i<n;i++)
   {
     printf("\n%c",ter[i]);
     for(j=0;j<n;j++)
     {
       printf("\t %c",opt[i][j][0]);
     }
    }
    stack[top]='$';
    printf("\n Enter the input string:");
    scanf("%s",ip);
    i=0;
    printf("\n STACK \t\t INPUT \t\t\t Action");
    printf("\n%s\t\t\t%s\t\t\t",stack,ip);
    while(i<strlen(ip))
    {
      for(k=0;k<n;k++)
      {
        if(stack[top]==ter[k])
         col=k;
        if(ip[i]==ter[k])
         row=k;
      }
      if((stack[top]=='$')&&(ip[i]=='$'))
      {
        printf("string accepted");
        break;
      }
      else if((opt[col][row][0]=='<')||(opt[col][row][0]=='='))
      {
         stack[++top]=opt[col][row][0];
         stack[++top]=ip[i];
         printf("shift %c",ip[i]);
         i++;
      }
      else
      {
        if(opt[col][row][0]=='>')
        {
          while(stack[top]!='<')
          {
            --top;
          }
           top=top-1;
           printf("Redduce");
         }
         else
         {
           printf("\n string not accepted");
           break;
         }
      }
      printf("\n");
      for(k=0;k<=top;k++)
      {
         printf("%c",stack[k]);
      }
      printf("\t\t\t");
      for(k=i;k<strlen(ip);k++)
      {
        printf("%c",ip[k]);
      }
      printf("\t\t\t");
   }
 }


      
    output:
*********************88

Enter no of terminals:4

Enter the terminals:+*i$

Enter the table values :
Enter the value for++ : >

Enter the value for+* : <

Enter the value for+i : <

Enter the value for+$ : >

Enter the value for*+ : >

Enter the value for** : >

Enter the value for*i : <

Enter the value for*$ : >

Enter the value fori+ : >

Enter the value fori* : >

Enter the value forii : =

Enter the value fori$ : >

Enter the value for$+ : <

Enter the value for$* : <

Enter the value for$i : <

Enter the value for$$ : A

 operator precedence table : + * i $

+ > < < >
* > > < >
i > > = >
$ < < < A
 Enter the input string:i+i*i$

 STACK INPUT Action
$ i+i*i$ shift i
$<i +i*i$ Redduce
$ +i*i$ shift +
$<+ i*i$ shift i
$<+<i *i$ Redduce
$<+ *i$ shift *
$<+<* i$ shift i
$<+<*<i $ Redduce
$<+<* $ Redduce
$<+ $ Redduce
$ $ string accepted  