#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 1000010
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>



bool  ok(int a,int b)
{
	std::set< pii > s;
	if(a<b)
		std::swap(a,b);
	while(a!=b)
	{
		
		a-=b;
		b+=b;
		if(a<b)
			std::swap(a,b);
		if( s.count( mp(a,b)) )
			return 0;
		else
			s.insert( mp(a,b) );
	}
	return 1;
}

int gcd(int a,int b){return b==0 ? a:gcd(b,a%b);}

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
		for(int i=1;i<1000;++i)
			for(int j=1;j<i;++j)
				if( ok(i,j))
					printf("%d %d %d\n",i,j,i+j);
		
					
		
	};
	return 0;
};
/*
*/
