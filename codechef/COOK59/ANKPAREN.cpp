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
using std::sort;using std::endl;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MINN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\..\\in.txt","r",stdin);
int times;cin >> times ; while(times--)
{	
	string s;
	int n;
	(cin  >> s>> n);{
		int left=0,ok=1;
		FR(i,s.size())
			if(s[i]=='(')
				++left;
			else if(s[i]==')' && --left<0)
				break;
		if(left)
			ok=0;
			
		if(ok==0){
			if(n==1)
				cout << s << endl;
			else
				cout << "-1\n"; 
		}
		else{
			int now=0,i;
			
			for(i=0;i<s.size();++i)
				if(s[i]==')')
					if(i==0 || s[i]!=s[i-1])
						if(++now == n)
							break;
			if(now==n)
			{			
				FR(j,s.size())
					if(j!=i)
						cout << s[j];
				cout << endl;
				continue;
			}
			for(i=s.size()-1;i>=0;--i)
				if(s[i]=='(')
					if(i==0 || s[i]!=s[i-1])
						if(++now == n)
							break;
			if(now==n)
			{			
				FR(j,s.size())
					if(j!=i)
						cout << s[j];
				cout << endl;
				continue;
			}
			cout << "-1\n";					
		}		
	};
}
	return 0;
};
/*






*/
