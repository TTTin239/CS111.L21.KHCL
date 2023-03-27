#include<stdio.h>
#include<string.h>
int k=0, z=0, i=0, j=0, c=0;
char a[16], ac[20], stk[15], act[10], a1[20], a2[20], a3[20];
void check();
int main(){
  puts("GRAMMAR is P-> E \n E-> E+T | T \n T-> T*F | F \n F-> (E) | id");
  puts("enter input string ");
  gets(a);
  c=strlen(a);
  strcpy(act,"SHIFT->");
  puts("stack \t input \t\t action");
  for(k=0,i=0; j<c; k++,i++,j++)
    {
      if(a[j]=='i' && a[j+1]=='d')
        {
          stk[i]=a[j];
          stk[i+1]=a[j+1];
          stk[i+2]='\0';
          a[j]=' ';
          a[j+1]=' ';
          printf("\n$%s\t%s$\t%sid",stk,a,act);
          check();
        }
      else
        {
          stk[i]=a[j];
          stk[i+1]='\0';
          a[j]=' ';
          printf("\n$%s\t%s$\t%ssymbols",stk,a,act);
          check();
        }
  check();
  }
  if(stk[0] == 'P' && stk[1] == '\0'){
      printf("Accept\n");
  }
  else{
      printf("Reject\n");
  }
}
void check(){
  strcpy(ac, "REDUCE TO E-> ");
  strcpy(a1, "REDUCE TO F-> ");
  strcpy(a2, "REDUCE TO T-> ");
  strcpy(a3, "REDUCE TO P-> ");
  for(z=0; z<c; z++)
    if(stk[z]=='i' && stk[z+1]=='d')
      {
        printf("%sid", a1);
        stk[z]='F';
        stk[z+1]='\0';
        printf("\n$%s\t%s$\t",stk,a);
        j++;
      }
    else
      if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')')
        {
          printf("%s(E)", a1);
          stk[z]='F';
          stk[z+1]='\0';
          stk[z+2]='\0';
          printf("\n$%s\t%s$\t", stk, a);
          i=i-2;
        }
  for(z=0; z<c; z++)
    if(stk[z]=='T' && stk[z+1]=='*' && stk[z+2]=='F')
      {
        printf("%sT*F", a2);
        stk[z]='T';
        stk[z+1]='\0';
        stk[z+2]='\0';
        printf("\n$%s\t%s$\t",stk,a);
        i=i-2;
      }
    else
      if(stk[z]=='F')
        {
          printf("%sF", a2);
          stk[z]='T';
          stk[z+1]='\0';
          printf("\n$%s\t%s$\t", stk, a);
        }
  for(z=0; z<c; z++)
    if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T')
      {
        printf("%sE+T", ac);
        stk[z]='E';
        stk[z+1]='\0';
        stk[z+2]='\0';
        printf("\n$%s\t%s$\t",stk,a);
        i=i-2;
      }
    // else
    //   if(stk[z]=='T')
    //     {
    //       printf("%sT", ac);
    //       stk[z]='E';
    //       stk[z+1]='\0';
    //       printf("\n$%s\t%s$\t", stk, a);
    //     }
  for(z=0; z<c/4;z++)
    if(stk[z]=='T')
        {
          printf("%sT", ac);
          stk[z]='E';
          stk[z+1]='\0';
          printf("\n$%s\t%s$\t", stk, a);
        }
  for(z=c-1; z<c; z++)
    if(stk[z]=='E' )
      {
        printf("%sE", a3);
        stk[z]='P';
        stk[z+1]='\0';
        printf("\n$%s\t%s$\t",stk,a);
      }
  return ;
}