#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 100100

char ch[4]={"rgb"};
int count[3];//rgb
char c[M];
int min;
int len;

void play(int *pri)
{	
	int sum=0,now=0;
	char tmp[M];
	for(int i=0,con=0;i<len;++i)
		if(c[i] == pri[0])
			++con;
		else
		{
			tmp[ now++ ] = c[i] ;
			sum += con ;
		};
	for(int i=0,con=0;i<now;++i)
		if(tmp[i] == pri[1])
			++con;
		else
			sum += con ;
			
	if(sum<min)
		min = sum;
}

void dfs(int *pri,int now)
{
	if(now==3)
	{
		play(pri);
		return ;
	}
	for(int i=0;i<3;++i)
	{
		int ok=1;
		for(int j=0;j<now;++j)
			if(pri[j]==i)
				ok=0;
		if(ok)
		{
			pri[now]=i;
			dfs(pri,now+1);
		}		
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		scanf("%s",c);
		
		count[0]=count[1]=count[2]=0;
		int i;
		for( i=0;c[i];++i)
			switch(c[i])
			{
				case 'r' : c[i]=0;++count[0];break;
				case 'g' : c[i]=1;++count[1];break;
				case 'b' : c[i]=2;++count[2];break;
			}
		len = i;
		
		
		min= INT_MAX;
		int pri[3];
		dfs(pri,0);
		
		printf("%d\n",min);
		//puts("zxczxcz");
		
	};
	return 0;
};
/*
*/
