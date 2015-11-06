#include<bits/stdc++.h>
#define ll long long int
#define yesT




int todig(char *c)
{
	int sum=0;
	int len=strlen(c);
	for(int i=len-1;i>=0;--i)
	{
		sum<<=1;
		if(c[i]=='1')
			sum|=1;
	};
	return sum;
}

/*
  0 1
 2 3 4
 5 6 7
  8 9
 10 11
  12

*/
int turn[3][6] = { { 0, 3, 6, 8, 5, 2},
				   { 1, 4, 7, 9, 6, 3},
				   { 6, 9,11,12,10, 8}  };
int toturn(int now,int a,int b)
{
	if(!b)
		b=-1;
	int t[6];
	for(int i=0;i<6;++i)
	{
		t[i] = now & (1<<turn[a][i]) ,	
		now ^= (now& (1<<turn[a][i]) );
	}
	
	for(int i=0;i<6;++i)
		if(t[i])
			now |= (1<<turn[a][(i+b+6)%6]);
	return now ;
	
}

int dp[1<<13];
std::vector< std::pair<int,int> > v[1<<13];
void find(int s)
{
	std::queue<int> q;
	q.push(s);
	dp[s]=0;
	
	int e = todig("0001001011000");
	while(q.size())
	{
		int now = q.front();
		q.pop();
		if(now==e)
			continue;
		for(int i=0;i<3;++i)
			for(int j=0;j<=1;++j)
			{
				
				int one = toturn(now,i,j);
				if(dp[one] > dp[now]+1)
				{
					dp[one] = dp[now]+1;
					
					v[one] = v[now];
					v[one].push_back( std::make_pair(i,j) );
					q.push(one);
				}			
				
			}
		
	}
	
	printf("%d\n",dp[e]);
	for(auto i:v[e])
		printf("%d %d\n",i.first,i.second);
}
/*
#define pr printf("%d",a&1);a>>=1;
#define sp printf(" ");
#define en puts("");
int todec(int a)
{
	  sp pr sp pr  en
	pr sp pr sp pr en
	pr sp pr sp pr en
	 sp pr sp pr   en
	 sp pr sp pr   en
   sp sp pr		   en
   puts("zxczxczxc");
};

void test()
{
	while(1)
	{
		scanf("%*d");
		char ch[100]={"1001001001001"};
		//scanf("%s",ch);	
		
	
		todec(todig(ch));
		
		for(int i=0;i<3;++i)
			for(int j=0;j<=1;++j)
				todec(  toturn(todig(ch),i,j ) );
	}
}
*/
int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T=100;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		//test();
		char c[20];
		scanf("%s",c);
		for(int i=0;i< (1<<13) ;++i)
			dp[i]=INT_MAX,
			v[i].clear();
		
		find(todig(c));
	};
	return 0;
};
/*
*/
