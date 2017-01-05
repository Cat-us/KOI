/* 
 * 2017
 * Made by Jaewon Lee.
 * 재귀함수
 * 문제 : 삼각형 만들기
 */
#include <stdio.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int n, num[100], card[100],count=0,max,mmaaxx,min,st=1,check[100]={0,};

void door(int cnt)
{

    int i,j;

    if(cnt > 3)
    {
		max=-1;

		for(j=1;j<=3;j++)
		{
			if(card[j]>max)
			{
				max=card[j];
				mmaaxx=j;
			}
		}

		min=0;

		for(j=1;j<=3;j++)
		{
			if(mmaaxx==j)
				continue;
			min=min+card[j];
		}

		if(min>max)
			count++;

        return;
    }

    for(i=st;i<=n;i++)
    {
		if(check[i]==0)
		{
			check[i]=1;
			st=i;
			card[cnt] = num[i];
			door(cnt+1);
			check[i]=0;
		}
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
	fprintf(out,"%d\n",count);

    return 0;
}
