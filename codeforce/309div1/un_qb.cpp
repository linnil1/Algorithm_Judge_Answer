#include<bits/stdc++.h>
#define ll long long 
#define M 52
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
ll inv(ll a,ll p){return a==1 ? 1 : inv(p%a,p)*(p-p/a)%MOD;}
ll fact[M],afact[M];
void initfact(){
	fact[0]=afact[0]=1;
	FOR(i,1,M){
		fact[i] = fact[i-1]*i%MOD;
		afact[i] = inv(fact[i],MOD);
	}
}
ll C(ll a,ll b){
	return fact[a]*afact[b]%MOD*afact[a-b]%MOD;
}


ll t[M];
int n;

ll dfs(int now){
	if(t[now]!=-1)
		return t[now];
	ll sum=0;
	sum+=dfs(now-1) ; //i==1
	for(int i=2;now-i>=0;++i){
		sum += dfs(now-i) * fact[i-2];
	}	
	return t[now] = sum;
}

void builtt(){	
	FR(i,M)
		t[i]=-1;
	t[0]=1;
	dfs(M-1);
}
VMP v;

ll myfact(int n){return n<=2 ? 1 : fact[n];}
void find(int now,int need){
	if(now==n)return ;
	for(int i=1;now+i<=n ; ++ i){
		if( myfact(i-2) * t[n-now-i] <= need){
			need -= myfact(i-2) * t[n-now-i];
		}
		else{
			int k = need / t[n-now-i] ;
			v.pb( mp(i,k+1) );
			need %= t[n-now-i];
			find(now+i,need);
			return ;
		}
	}
	//special
	v.pb( mp(n-now,myfact(n-now-2)+1) );
}

void pr(int now,int vi){	
	if( vi>=v.size())
		return ;
	cout << now+v[vi].ft << " ";
	
	VI tmp;
	FOR(i,now,now+v[vi].ft-1)
		tmp.pb( i);
		
	int k=1;
	while(tmp.size()){
		FR(i,tmp.size())
			if(now+k==tmp[i])
				continue;
			else if(v[vi].sd >= fact[tmp.size()-1])
				v[vi].sd-= fact[tmp.size()-1];
			else{
				cout << tmp[i]+1 << " ";
				tmp.erase(tmp.begin()+i);
				++k;
			}
	}
	pr(now+v[vi].ft , vi+1);
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 
	initfact();
	builtt();
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	FR(i,M)
		cout << t[i] << " ";
	cout << endl;
	ll m;
	while(cin >> n >> m){
		v = VMP();
		find(0,m-1);
		FR(i,v.size())
			cout << v[i].ft << " " << v[i].sd << endl;
		
		
		pr(0,0);
		cout << endl;
	};
}
	return 0;
};
/*






*/
