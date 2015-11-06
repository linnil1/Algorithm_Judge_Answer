#include<bits/stdc++.h>
#define ll long long 
#define M 100010
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

int co[M],ok=0,mi,ma;

VMP road[M];
void dfs(int now,int sum)
{
	if(ok)
		return ;
	FR(i,road[now].size())
		if( co[ road[now][i].ft ]==-1 )
		{
			int &t = co[ road[now][i].ft ] = sum + road[now][i].sd ;
			if(mi<= t && t <=ma)
			{
				ok=1;
				break;
			}
			dfs( road[now][i].ft , t );	
			if(ok)
				break;	
		}
}

int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		cin >> mi >> ma;
		FR(i,n)
			road[i] = VMP();
			
		FOR(i,1,n)
		{
			int x,y,cost;
			cin >> x >> y >> cost ;
			road[x].pb( mp(y,cost) );
			road[y].pb( mp(x,cost) );			
		}
		FR(i,n)
			co[i]=-1;
		co[0]= ok = 0;
		dfs(0,0);	
		cout << (ok?"Eat Eat Eat\n":"Go find other chickens\n") ;
	};
}
	return 0;
};
/*
20min 
*/
