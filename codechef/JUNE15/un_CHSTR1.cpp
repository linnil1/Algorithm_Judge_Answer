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
#define MANN(a,b,c) MIN(MIN(a,b),c)
 
 
#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;
ll inv(ll a,ll p){return a==1 ? 1 : inv(p%a,p)*(p-p/a)%MOD;}
ll fact[5001],afact[5001];
void makefact()
{
	fact[0]=1;
	fact[1]=1;
	FOR(i,2,5001)
		fact[i] = fact[i-1]*i%MOD;
		
	FOR(i,0,5001)
		afact[i] = inv(fact[i],MOD);
};
 
struct word
{
	word *w[26];
	int t;
	word(){FR(i,26)w[i]=NULL;t=0;};	
};
word m[10000],*mem;
void toac(int n)
{			
	char ch[5005];
	scanf("%s",ch);
	FR(i,n)
		ch[i]-='a';
	mem = m;
	word *root=new (mem++) word();
	FR(i,n)
	{
		word *now = root ;
		FOR(j,i,n)
		{							
			if(now->w[ch[j]]==NULL)
				now->w[ch[j]] =new (mem++) word();			
			now = now->w[ch[j]];		
			++now->t;
		}
	}
}
ll arr[5001];
void toarr(int n)
{
	FRE(i,n)
		arr[i]=0;

	for(word *f = m+1 , *end = mem;f!=end;++f)
		++arr[ f->t ];	
};
ll C(int a,int b)
{
	return fact[a]*afact[b]%MOD*afact[a-b]%MOD;
}
ll ans[5001];
ll toans(int n)
{
	/*FRE(i,n)
		PR(arr[i]);*/
	FRE(i,n)
		if(arr[i])
			arr[i] = arr[i]*fact[i]%MOD;
	
	FRE(i,n)
	{
		ans[i]=0;
		for(int j=i;j<=n;++j)
			if(arr[j])
				ans[i] = 
				(ans[i]+ arr[j]*afact[i]%MOD*afact[j-i]%MOD)%MOD;
	}
	/*FRE(i,n)
		PR(ans[i]);*/
}
 
int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
 
makefact();
	//freopen("..\\in.txt","r",stdin);
int times;scanf("%d",&times); while(times--)
{	
	int n,t;
	//while(cin >> n >> t)
	scanf("%d%d",&n,&t);
	{
		//cout << C(n,t) << endl;continue;	
		
		toac(n);
		toarr(n);
		toans(n);
		while(t--)
		{
			int k;
			scanf("%d",&k);
			printf("%lld\n",k<=n ? ans[k]:0 );
		}
		
	};
}
	return 0;
};
/*
1000 10
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 
 
 
 
*/
 
