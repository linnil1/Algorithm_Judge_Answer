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



int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	string s;
	while(cin >> n >> s)
	{
		int ch=0,q=1;
		FOR(i,2,s.size())
			ch = ch*10 + s[i]-'0',
			q*=10;
		
		ll sum=n;
		while(n*ch>=q)
		{
			int k ;
			sum += k = n*ch/q;
			cout << k << endl;
			n = k + n - k*q/ch ;
		}			
		
		cout<< sum << endl ;
	};
}
	return 0;
};
/*
10min something wrong
*/
