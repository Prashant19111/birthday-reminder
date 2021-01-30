#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int main()
{
     int d,m;
     time_t now;
     time(&now);
     struct tm *loc=localtime(&now);
     d=(*loc).tm_mday;
     m=(*loc).tm_mon+1;
     char s[10],s1[2];
     sprintf(s,"%02d-%02d",d,m);
     
     FILE *ptr;
     ptr=fopen("D:/birthday-reminder-master/birthdate.txt","r");
    
    
    int i=1,flag=0,count=1;
    char name[50],date[10];
    char buf[100];
    char *c;
    do{
        if(i%2!=0){
            fgets(name,50,ptr);
        }
        if(i%2==0){
            fgets(date,6,ptr);
            if(!strcmp(s,date)){
                snprintf(buf,100,"Today Is Your Friend %s's Birthday",name);
                MessageBox(0,buf,"Today's Birthday",64);
                count++;
            }
            fgets(date,2,ptr);
        }
        i++;
    }while(!feof(ptr));
     
    return 0;
}
