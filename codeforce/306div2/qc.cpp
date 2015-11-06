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

using std::cin;using std::cout;using std::string;
using std::sort;using std::endl;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MANN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

string tostr(int n)
{
	string a;
	if(n==0)
		return string("0");
	while(n)
		a.pb(n%10+'0'),
		n/=10;
	//cout << a << "!!\n";
	return a;
}

int check(string &a,string &s,int &ok)
{
	int zero = 3-a.size();
	int now=0;
	BFR(i,s.size())
		if(a[now]==s[i])
		{
			++now;
			if(now==a.size())
			{
				string ori = a;
				while(zero && i>=0 )
				{
					if(s[i]=='0')
						--zero,a.pb('0');
					--i;
				}
				if(zero )
				{
					ok = ori.size();
					a=ori;
					return 1;
				}
				else
				{
					for(--i;i>=0;--i)
						a.pb(s[i]);
					ok = a.size();
					return 1;
				}
			};
			
		}	
	
	return ok=0;
}

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	string s ;
	while(cin >> s)
	{
		string ans;
		for(int i=0;i<=1000;i+=8)
		{
			string a=tostr(i);
			
			int ok=0;
			int max=0;
			check(a,s,ok);			
			if(ok>max)
			{
				max=ok;
				ans = a;
			}
		}
		for(int i=0;i<ans.size()/2;++i)
			std::swap(ans[i],ans[ans.size()-1-i]);
		if(!ans.size())
			cout << "NO\n";
		else
			cout << "YES\n" << ans << endl ;
		
	};
}
	return 0;
};
/*






*/
