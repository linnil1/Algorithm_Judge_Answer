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



int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	string na,b,c;
	while(cin >> na && na!="A")
	{
		cin >> b >> c;
		int n=0;
		for(char i:na)
			n = n*26 + i - 'A' ;
		
		int r=0;
		BFR(i,n)
		{
			b[i] = b[i]-'A'+c[i] + r;
			if(b[i]>'Z')
			{
				b[i]-=26;
				r=1;
			}
			else
				r=0;
		}
		if(r)
			cout << char('A'+r);
		cout << b << endl ;
	};
}
	return 0;
};
/*
12min
the problem of cout 
*/
