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

struct big
{
	VI v;
	int sci,pm;
};

void nozero(VI &v)
{
	int len = v.size();
	while(len && !v[len-1])
		--len;
	v.resize(len);		
}

big rev(string s)
{
	big a;
	a.sci=0;
	a.pm=1;
	BFR(i,s.size())
		if(isdigit(s[i]))
			a.v.pb(s[i]-'0');
		else if(s[i]=='.')
			a.sci = -a.s.size();
		else if(s[i]=='-')
			a.pm=-1;
			
	nozero(a.v);		
	return a;
}




int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	string s;
	while(cin >> s)
	{
		big x = rev(s);
		
		big now = x,mult = x*x;
		int p=1;
		big sum = x ;
		
		FR(i,100)
		{
			now = now / p / (p+1);
			now = now * mult;
			p+=2;
		}
		
		sum.pr();
		
		
	};
}
	return 0;
};
/*
too many things
*/
