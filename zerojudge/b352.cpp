#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string

int gcd(int a,int b){return b ? gcd(b,a%b) : a ;}

string tostr(int a,int b,int c)
{
	char ch[100];
	sprintf(ch,"%d-%d-%d",a,b,c);
	return string(ch);
}

int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int no=0,max=0;
		std::map<string,int> m;
		for(int i=0,a,b,c;i<n;++i)
		{		
			scanf("%d%d%d",&a,&b,&c);
			if(a>b)std::swap(a,b);
			if(a>c)std::swap(a,c);
			if(b>c)std::swap(b,c);
			if((ll)a+b<=c)
				{++no;continue;}
			
			int g = gcd( gcd(a,b) ,c );		
			a/=g;b/=g;c/=g;
			
			string now = tostr(a,b,c);
			if(++m[now]>max)
				max = m[now];
		}
		printf("%d %d\n",n-no,max-1);
		
		
	};
	return 0;
};
/*
15min
*/
