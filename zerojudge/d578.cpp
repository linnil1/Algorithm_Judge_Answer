#include<bits/stdc++.h>
#define ll long long 
#define M 1002
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

int use[M][257];

int main()
{
	//std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m;
	while(~scanf("%d %d",&n,&m )&& n && m)
	{
		char c[M];
		fgets(c,M,stdin);
		FR(i,M)
			for(int j=32;j<=126;++j)
				use[i][j]=0;
		int all = n*m-1;
		
		FR(i,all)
		{
			fgets(c,M,stdin);
			for(int i=0;c[i];++i)
				++use[i][c[i]];
		};
		FR(i,M)
			for(int j=32;j<=126;++j)
				if(use[i][j]%m)
					printf("%c",j);
		puts("");
	};
}
	return 0;
};
/*
24min ascii
*/
