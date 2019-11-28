#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
int i,j,k,p,c;
char s[120],r[100];
char par[6]={'(',')','{','}','[',']'};
char sym[9]={'.',';',':',',','<','>','?','$','#'};
char key[9][10]={"main","if","else","switch","void","do","while","for","return"};
char dat[4][10]={"int","float","char","double"};
char opr[5]={'*','+','-','/','^'};
char *fp;
clrscr();
printf("\n\n\t enter file name");
scanf("%s",s);
fp=fopens(s,"r");
c=0;
do
{
    fscanf(fp,"%s",r);
    getch();
    for(i=0;i<6;i++)
        if(strchr(r,par[i])!=NULL)
            printf("\n paranthesis:%c",par[i]);
    for(i=0;i<9;i++)
        if(strchr(r,sym[i])!=NULL)
            printf("\n symbol:%c",sym[i]);
    for(i=0;i<9;i++)
        if(strstr(r,key[i])!=NULL)
            printf("\n keyword:%s",key[i]);
    for(i=0;i<4;i++)
        if((strstr(r,dat[i])&&(!strstr(r,"printf")))!=NULL)
    {
        printf("\n data type:%s",dat[i]);
        fscanf(fp,"%s",r);
        printf("\n identifiers :%s",r);
    }
    for(i=0;i<5;i++)
        if(strchr(r,opr[i])!=NULL)
        printf("\n operator:%c",opr[i]);
    p=c;
    c=ftell(fp);
    }while(p!=c);
    return 0;
}



