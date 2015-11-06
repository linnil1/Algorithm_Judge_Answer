#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 10010
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string

int p[M],pl;
int fect[5000010];
void prim()
{
	int c[M];
	for(int i=0;i<M;++i)
		c[i]=1;
	
	pl=0;
	for(int i=2;i<M;++i)
	{
		if(c[i])p[pl++]=i;
		for(int j=0;j<pl && i*p[j]<M;++j)
		{
			c[i*p[j]]=0;
			if(i%p[j]==0)
				break;
		}
		//printf("%d\n",p[pl-1]);
	}
	
}

/*int many(int a,int b)
{
	int sum=0;
	while(a)
	{
		sum+=a/b;
		a/=b;
	}
	return sum;
}*/

void init()
{
	fect[1]=0;
	for(int i=2;i<=5000000;++i)
	{
		int ok=1,j;
		int li = (int)sqrt(i) + 2;
		for(j=0;j<pl && p[j]<li;++j)
			if(i%p[j]==0)
				{ok=0;break;}
		if(ok==1)
			fect[i]=1;
		else
			fect[i]=1+fect[i/p[j]];			
	}
	for(int i=3;i<=5000000;++i)
		fect[i]+=fect[i-1];
	
	
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	prim();
	init();
	
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	
	int n;
	//while(~scanf("%d",&n))
	#endif	
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",fect[a]-fect[b]);
	};
	return 0;
};
/*
*/
