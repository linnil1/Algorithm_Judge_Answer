#include<bits/stdc++.h>
#define ll long long int
//#define yesT
#define M 1001000

char c[M];
int num[M][26];
ll count[M];
ll vans [M];
void init(char *c,int &len)
{
	for(int j=0;j<26;++j)
		num[0][j]=0;
	int i;
	for(i=0;c[i];++i)
	{
		for(int j=0;j<26;++j)
			num[i+1][j] = num[i][j]; 
		
		++ num[i+1][ c[i]-'a' ] ;	
	};
	len = i ;
}

struct strans
{
	char a,b;
	int x,y,num;
	bool operator < (const strans &s)const
	{
		return a != s.a ? a < s.a : b < s.b ;
	}
}ans[M];

void tocount(char a,char b)
{
	count[0]=0;
	for(int i=0;c[i];++i)
	{
		count[i+1]=count[i];
		if(c[i] == b )
			count[i+1] += num[i+1][a-'a'];
	}
}

int cal(int i)
{
	int &x = ans[i].x,
		&y = ans[i].y;
		
	--x;
	vans [ ans[i].num ] = count[y] - count[x] - 
		( num[ x ][ ans[i].a-'a' ] ) * 
	    ( num[ y ][ ans[i].b-'a' ] - 
		  num[ x ][ ans[i].b-'a' ] ) ;
	
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	scanf("%s",c);
	#endif	
	{
		int n,len;		
		init(c,len);
		
		scanf("%d",&n);		
		for(int i=0;i<n;++i)
		{
			char ch[10];
			scanf("%s%s%d%d",ch,ch+5,&ans[i].x,&ans[i].y);
			ans[i].a = ch[0];
			ans[i].b = ch[5];
			ans[i].num = i ;			
		}
		std::sort(ans,ans+n);
		
		char l=0,r=0;
		for(int i=0;i<n;++i)
		{		
			if(l!=ans[i].a || r!=ans[i].b)
			{
				l = ans[i].a ;
				r = ans[i].b ;	
				tocount(l,r);		
			}			
			cal(i);			
		};
		
		for(int i=0;i<n;++i)
			printf("%lld\n",vans[i]);
		
	};
	return 0;
};
/*
*/
