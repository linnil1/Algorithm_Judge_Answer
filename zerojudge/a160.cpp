#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_pair
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;

int use[4][24],n,que[13],coun;

void chan(int i,int j,int k)
{
	use[0][i] = use[1][j] = use[2][i+j] = use[3][i-j+11] =  k ;
}

void dfs(int now)
{
	if(now==n)
	{	
		coun++;
		FR(i,n)
		{	
			FR(j,n)
				printf("%c",que[i]==j?'Q':'x');
			puts("");
		};
		puts("");
		return ;
	}
	
	FR(j,n)
		if( use[0][now] && use[1][j] && use[2][now+j] && use[3][now-j+11] )
		{
			chan(now,j,0);
			que[now]=j;
			dfs(now+1);
			chan(now,j,1);
		}
	
}

int main()
{
	//std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	while(~scanf("%d",&n) && n)
	{
		FR(i,4)
			FR(j,24)
				use[i][j]=1;
		coun=0;
		dfs(0);
		printf("%d\n\n",coun);
	};
}
	return 0;
};
/*
15min ok
*/
