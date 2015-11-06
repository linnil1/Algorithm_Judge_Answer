#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
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

int cost[3][3];

int ftime(int a)
{
	if((21<=a && a<= 24)||(0<=a && a<6) || (14<=a && a<16))
		return 0;
	else if(( 6<=a && a<9)|| (17<=a && a< 19))
		return 2;
	else
		return 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ; while(times--)
{	
	int m,n;
	//while
	(cin >> m>>n);
	{
		FR(i,3)
			FR(j,3)
				cin >> cost[i][j] ;
		
		int use = ftime(n),
			mcost = INT_MAX;
		string muse = "Walk home";
		
		if(cost[2][use]*10 <= m && cost[2][use]*10 < mcost)		
			muse = "HSR" , mcost = cost[2][use]*10 ;
		if(cost[1][use]*6 <= m && cost[1][use]*6< mcost)		
			muse = "Train" , mcost = cost[1][use]*6  ;
		if(cost[0][use]*4 <= m && cost[0][use]*4  < mcost)		
			muse = "Bus" , mcost = cost[0][use]*4  ;
		if(mcost == INT_MAX)
			cout << "Walk home\n";
		else
			cout << muse <<endl;
		
	};
}
	return 0;
};
/*
16min slow
do not do it by yourself
*/
