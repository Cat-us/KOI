/* 
 * 2017
 * Made by Jaewon Lee.
 * 재귀함수
 * 문제 : 부분집합모두출력하기
 */

#include <stdio.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int n, num[100], card[100],st=1;

void door(int cnt)
{
    int i, j;

    if(cnt>n)
        return;

    for(i=st;i<=n;i++)
    {
        st=i+1;
        card[cnt] = num[i];

        for(j=1;j<=cnt;j++)
            fprintf(out,"%c",card[j]);
        fprintf(out,"\n");

        door(cnt+1);
    }
}

int main()
{

    int i;

    fscanf(in,"%d",&n);
    for(i=1;i<=n;i++)
    {
		num[i]=96+i;
    }

    door(1);

    return 0;
}
