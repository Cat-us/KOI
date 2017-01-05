/* 
 * 2017
 * Made by Jaewon Lee.
 * 재귀함수
 * 문제 : 숫자카드1
 */
#include <stdio.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int n, num[100], card[100];

void door(int cnt)
{

    int i,j;

    if(cnt > n)
    {
        for(j=1;j<=n;j++)
        {
            fprintf(out,"%d",card[j]);
        }
        fprintf(out,"\n");
        return;
    }

    for(i=1;i<=n;i++)
    {
        card[cnt] = num[i];
        door(cnt+1);
    }
}

int main()
{

    int i;

    fscanf(in,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(in,"%d",&num[i]);
    }

    door(1);

    return 0;
}
