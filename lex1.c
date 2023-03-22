#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define Max_Token_Len 100
enum TokenType {
     Number,
     Id,
     Keyword,
     Operator,
     Symbol,
     Error
  };
const char *TokenTypeStrings[]={
      "Number",
      "Id",
      "Keyword",
      "Operator",
      "Symbol",
      "Error"
  };
struct Token {
    enum TokenType type;
    char value[Max_Token_Len];
    };
 int isKeyword(const char* str){
     static const char *keywords[]={
"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","while","void","volatile"
    };
   for(int i=0;i<sizeof(keywords)/sizeof(keywords[0]);i++){
          if(strcmp(keywords[i],str)==0){
             return 1;
          }
       }
       return 0;
     }
   struct Token getNextToken(const char *input,int *start){
         int len=strlen(input);
         int lineIndex=0;
       char c=input[*start];
       while(*start<len){
            if(isspace(c)){
               (*start)++;
               c=input[*start];
           continue;
       }
      if(isdigit(c)){
         struct Token t={Number,""};
         do{
            t.value[lineIndex++]=c;
            (*start)++;
            c=input[*start];
          }while(isdigit(c));
        return t;
      }
     if(isalpha(c)){
        struct Token t={Id,""};
        do{
          t.value[lineIndex++]=c;
          (*start)++;
          c=input[*start];
        }while(isalnum(c));
        t.type=isKeyword(t.value)?Keyword:Id;
       return t;
      }
      if(ispunct(c)){
         if(c=='+'||c=='-'||c=='*'||c=='/'||c=='='||c=='%'||c=='<'||c=='>'||c=='!'||c=='|'||c=='&'){
            struct Token t={Operator,""};
            t.value[lineIndex++]=c;
            (*start)++;
            return t; 
            }
            else{
          struct Token t={Symbol,""};
          t.value[lineIndex++]=c;
          (*start)++;
          return t;
          }
     }
     struct Token t={Error,""};
     t.value[lineIndex++];
     (*start)++;
     return t;
    }
   struct Token t={EOF,""};
   return t;
  }
   int main(){
     char input[1000];
     printf("Enter a string: ");
     scanf("%[^\n]s",input);
     int start=0;
     struct Token t;
     while((t=getNextToken(input,&start)).type!=EOF){
        printf("%s\t%s\n",TokenTypeStrings[t.type],t.value);
      }
    return 0;
   }



-----Output:
Enter a string: void main()
Keyword void
Id      main
Symbol  (
Symbol  )