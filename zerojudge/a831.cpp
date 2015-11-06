#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define ARR(arr,n) int arr[n];for(int i=0;i<n;++i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define QI std::queue<int>
#define VI std::vector<int>

#define MP std::pair<int,int>
using namespace std;



int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m,a;
	while(cin >> n >> m >> a)
	{
		if(n%a)
			n+=a;
		if(m%a)
			m+=a;
		
		cout << (ll)(n/a)*(m/a) << endl;
	};
}
	return 0;
};
/*
*/
