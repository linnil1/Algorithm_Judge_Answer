#include<cstdio>
int main()
{
    int a;
    printf("��J�@�ӫD0���Q�i�쥿���:");
    while(~scanf("%d",&a))
    {
		if(a<0)
		{
			printf("error\n");
			continue;
		}
		int ans[100],now=0,c[2];
		c[0]=c[1]=0;
		while(a)
		{
			ans[now++]=a&1;
			++c[a&1];
			a>>=1;
		};
		if(now==0)
			printf("0"),c[0]++;
		while(now--)
			printf("%d",ans[now]);
		printf("\n0���Ӽ�:%d\n1���Ӽ�:%d\n",c[0],c[1]);
		
	};
    return 0;
};
