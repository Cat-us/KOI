/*
 * 2017
 * Made by Jaewon Lee.
 * 재귀함수 
 * 문제 : 좋은수열
 */

#include <stdio.h>

FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");

int a, num[1001],st=0;

void goodnumber(int cnt)
{
    int i, j, k, chk;

    if(st==1)
        return;

    for(j=1;j<=cnt/2;j++)
    {
        chk=0;
        for(k=1;k<j+1;k++)
        {
            if(num[cnt-k] == num[cnt-(k+j)])
            {
                chk++;
            }
        }
        if(chk == j)
        {
            return;
        }
    }

    if(cnt>a)
    {
        for(i=1;i<=a;i++)
            fprintf(out,"%d",num[i]);
        fprintf(out,"\n");
        st=1;
        return;
    }

    for(i=1;i<=3;i++)
    {
        num[cnt]=i;

        goodnumber(cnt+1);
    }
}

int main(void)
{
    fscanf(in,"%d",&a);

    goodnumber(1);

    return 0;
}
