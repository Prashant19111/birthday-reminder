#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
     int d,m;
     time_t now;
     time(&now);
     struct tm *loc=localtime(&now);
     d=(*loc).tm_mday;
     m=(*loc).tm_mon+1;
     char s[10],s1[20],s2[20];
     sprintf(s,"%02d-%02d",d,m);
     
     FILE *ptr;
     ptr=fopen("birthdate.txt","r");
    
     int i=strlen(s);
     
     while(!feof(ptr))
     {
         fgets(s1,i+1,ptr);
         int x=strcmp(s1,s);
         if(x>0||x<0)
         {
             strcpy(s2,s1);
             fgets(s1,10,ptr);
             strcat(s2,s1);
         }
         
         if(x==0)
         {
             printf("Todat is %s",s2);
             printf(" birthday");
             break;
         }
     }
     

    return 0;
}
