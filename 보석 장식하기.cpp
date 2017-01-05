/* 
 * 2017
 * Made by Jaewon Lee.
 * 재귀함수
 * 문제 : 보석장식하기
 */

#include <stdio.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int v, h, alpha[27]={0,};
char num[100], dia[100];

void door(int cnt)
{
    int i;

    if(cnt>h)
    {
        for(i=1;i<=h;i++)
            fprintf(out,"%c",dia[i]+96);
        fprintf(out,"\n");

        return;
    }

    for(i=1;i<=26;i++)
    {
        if(alpha[i] != 0)
            dia[cnt] = i;

        if(alpha[i] == 0)
            continue;

        alpha[i]--;
        door(cnt+1);
        alpha[i]++;
    }
}

int main(void)
{

    int i;

    fscanf(in,"%d %d\n",&v,&h);
    //scanf("%d %d",&v,&h);

    for(i=1;i<=v;i++)
    {
		fscanf(in,"%c ",&num[i]);
		//scanf("%c",&num[i]);
    }

    for(i=1;i<=v;i++)
    {
        alpha[((int)num[i]-96)]++;
    }

    door(1);

    return 0;
}
