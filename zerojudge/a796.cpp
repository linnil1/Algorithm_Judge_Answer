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



int main()
{
	//std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		int can[n+2][n+2];
		FRE(i,n)FRE(j,n)can[i][j]=0;
		int r;
		cin >> r;
		while(r--)
		{
			int x,y;
			cin >> x >> y ;
			can[x][y]= can[y][x]=1;
		}
		ARRE(road,n)
		{
			road[i]=0;
			FRE(j,n)
				if(can[i][j])
					++road[i];
		}
		cin >> r;
		while(r--)
		{
			int k,x,y;
			cin >> k ;
			if(k==1)
			{
				cin >> x ;
				cout << road[x];
			}
			else
			{
				cin >> x >> y;
				cout << (can[x][y]?"Yes":"No");
			}
			cout << endl ;
		}
	};
}
	return 0;
};
/*
10min is it to equal  is problem
slow 
*/
