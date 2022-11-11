#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int p,h;
    scanf("%d",&p);
    scanf("%d",&h);
    char file_name[30]="pigeonhole_",end[]=".cnf",num1[2],num2[2];
    sprintf(num1,"%d",p);
    sprintf(num2,"%d",h);
    strcat(file_name,num1);
    strcat(file_name,"_");
    strcat(file_name,num2);
    strcat(file_name,end);
    FILE *f=fopen(file_name,"w");

    int c=p;

    for(int j=1;j<=h;j++)
        for(int i=1;i<=h;i++)
            for(int k=i+1;k<=p;k++)
                c++;

    fprintf(f,"p cnf %d %d\n",p*h,c);
    for(int i=1;i<=p;i++)
    {
        for(int j=1;j<=h;j++)
            fprintf(f,"%d ",h*(i-1)+j);
        fprintf(f,"0\n");
    }

    for(int j=1;j<=h;j++)
        for(int i=1;i<=p;i++)
            for(int k=i+1;k<=p;k++)
                fprintf(f,"-%d -%d 0\n",h*(i-1)+j,h*(k-1)+j);

}