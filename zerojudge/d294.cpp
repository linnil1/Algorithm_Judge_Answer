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

ll calbig(ll a)
{
	if(a%2)
		return (a+1)/2*a;
	else
		return a/2*(a+1);
}

ll calgrid(ll a,ll b)
{
	return calbig(abs(a))*calbig(abs(b));
}
int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int x[4],y[4];
	while(cin >> x[0]>>y[0])
	{		
		FOR(i,1,4)
			cin >> x[i] >> y[i];
		
		int x1[4],y1[4];		
		FR(i,4)
			cin >> x1[i] >> y1[i];
			
		ll sum= 0 ;
		FR(i,4)
			sum -= calgrid( x[i]-x1[i] , y[i]-y1[i] );
		//cout  << sum << endl;
		for(int i=0;i<4;i+=2)
			sum += calgrid( y1[i]-y[i] , x[i]-x[i+1] );
		for(int i=1;i<4;i+=2)
			sum += calgrid( x1[i]-x[i] , y[i]-y[i+1] );
		
		sum+=  calgrid(x1[0]-x[0]+1,x[2]-x1[2]+1)*calgrid(y1[1]-y[1]+1,y[3]-y1[3]+1);	
			
		cout << sum << endl;
	};
}
	return 0;
};
/*
*/
