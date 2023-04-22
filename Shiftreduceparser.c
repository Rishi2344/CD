code:
***************
#include<stdio.h>
#include<string.h>
int k=0,z=0,i=0,j=0,c=0;
char a[20],ac[20],s[20],act[20];
void check();
int main()
{
  puts("Grammar is E-->E+E\n E-->E*E\n E-->(E)\n E-->id\n");
  puts("Enter the string ");
scanf("%s",a);
  c=strlen(a);
  strcpy(act,"SHIFT-->");
  puts("Stack \t Input \t Action");
  for(k=0,i=0;j<c;k++,i++,j++){
  if(a[j]=='i'&&a[j+1]=='d')
  {
    s[i]=a[j];
    s[i+1]=a[j+1];
    s[i+2]='\0';
    a[j]=' ';
    a[j+1]=' ';
    printf("\n$%s\t%s$\t%sid",s,a,act);
    check();
  }
  else
  {
     s[i]=a[j];
     s[i+1]='\0';
     a[j]=' ';
         printf("\n$%s\t%s\t%s symbols",s,a,act);
  check();
  }
 }
  if(strlen(s)>1)
  printf("\nString not accepted\n");
  else
  printf("\nString accepted\n");
}
void check()
{
     strcpy(ac,"reduce to E");
     for(z=0;z<c;z++)
     if(s[z]=='i'&&s[z+1]=='d')
     {
         s[z]='E';
         s[z+1]='\0';
             printf("\n$%s\t%s\t%s",s,a,act);
             j++;
     }
     for(z=0;z<c;z++)
     if(s[z]=='E'&&s[z+1]=='+'&&s[z+2]=='E')
     {
        s[z]='E';
        s[z+1]='\0';
        s[z+2]='\0';
            printf("\n$%s\t%s$\t%s",s,a,ac);
            i-=2;
     }
     for(z=0;z<c;z++)
     if(s[z]=='E'&&s[z+1]=='*'&&s[z+2]=='E')
     {
        s[z]='E';
        s[z+1]='\0';
        s[z+2]='\0';
            printf("\n$%s\t%s$\t%s",s,a,ac);
            i-=2;
     }
     for(z=0;z<c;z++)
     if(s[z]=='('&&s[z+1]=='E'&&s[z+2]==')')
     {
        s[z]='E';
        s[z+1]='\0';
        s[z+2]='\0';
            printf("\n$%s\t%s$\t%s",s,a,ac);
            i-=2;
     }
}


output:
**********
Grammar is E-->E+E
E-->E*E
E-->(E)
E-->id
Enter the string 
id*id+id*id
Stack 	 Input 	 Action

$id	  *id+id*id$	SHIFT-->id
$E	  *id+id*id	SHIFT-->
$E*	   id+id*id	SHIFT--> symbols
$E*id	     +id*id$	SHIFT-->id
$E*E	     +id*id	SHIFT-->
$E	     +id*id$	reduce to E
$E+	      id*id	SHIFT--> symbols
$E+id	        *id$	SHIFT-->id
$E+E	        *id	SHIFT-->
$E	        *id$	reduce to E
$E*	         id	SHIFT--> symbols
$E*id	           $	SHIFT-->id
$E*E	           	SHIFT-->
$E	           $	reduce to E
String accepted
