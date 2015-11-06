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
void com(ll &a,ll &b,char &c){
	switch(c){
		case '+':a+=b;break;
		case '-':a-=b;break;
		case '*':a*=b;break;
		case '/':a/=b;break;
		case '%':a%=b;break;
	}
}
ll getnum(string &s,int &i){
	ll sum=0;
	for(i;i<s.size() &&isdigit(s[i]) ;++i)
		sum= sum*10+s[i]-'0';
	--i;
	return sum;
}


ll cal(string &s){
	ll st=0,now=0,t=0;
	char ch='+',ch1='+';
	for(int i=0;i<s.size();++i){
		if(isdigit(s[i])){		
			t = getnum(s,i);
			com(now,t,ch1);
			ch1 = '+';
		}
		else	
			switch(s[i]){
				case '+':case'-':
					com(st,now,ch);
					ch = s[i];
					now=0;
					break;
				case '*':case '/':case '%':
					ch1=s[i];
					break;
			}
		cout << st << " " << now << endl;
	}
	com(st,now,ch);
	return st;
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	string s;
	while(cin >> n){
		cin.ignore();
		while(n--){		
			std::getline(cin,s);
			cout <<cal(s) << endl;
		}
	};
}
	return 0;
};
/*






*/
