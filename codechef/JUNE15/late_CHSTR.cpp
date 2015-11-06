#include<bits/stdc++.h>
#define ll long long 
#define M 5010
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
ll fact[M],afact[M];
void makefact()
{
	fact[0]=1;
	fact[1]=1;
	for(int i=2;i<=5000;++i)
		fact[i] = fact[i-1]*i%MOD;
	for(int i=0;i<=5000;++i)
		afact[i] = inv(fact[i],MOD);
};
ll C(int a,int b)
{
	return fact[a]*afact[b]%MOD*afact[a-b]%MOD;
}

int sa[M],da[M];
struct word
{
	int w;
	word *n;
	word(){	};
	word(int _w):w(_w),n(NULL){};
};

void sasort(char *ch,int n)
{	
	word *f[27],*b[27],*tf,*tb;
	FR(i,n)
		ch[i]=ch[i]-'a'+1,
		ch[n+i]=0;
		
	for(int i=0;i<=26;++i)
		f[i]=b[i]=NULL ;	
	tf = tb = new word(0);
	FOR(i,1,n)
	{	
		tb -> n = new word(i);
		tb = tb->n;
	};
	BFR(i,n)
	{
		//dispute;
		while( tf != NULL )
		{
			int now=ch[tf->w+i];
			if(f[now]==NULL)
				f[now]=b[now]= tf;
			else
			{
				b[now]->n = tf ;
				b[now] = b[now]->n ;
			}
			tf = tf->n ;
			b[now]->n = NULL;
		}
		//merge
		tf = tb = NULL ;
		for(int j=0;j<=26;++j)
		{
			if(f[j]!=NULL)
				if(tf == NULL)
				{
					tf = f[j];
					tb = b[j];
				}
				else
				{
					tb->n = f[j];
					tb = b[j];
				};
			f[j]=b[j]=NULL;
		}
	}
	//to suffix array
	int i=0;
	while(tf != NULL)
	{
		sa[i++] = tf->w ;
		tf = tf->n;
	}
	/*FR(i,n)
		PR(sa[i]);*/
}
void satoda(char*ch ,int n)
{	
	int r[n];
	FR(i,n)
		r[sa[i]]=i;
	FR(i,n)
		if(r[i]==0)
			da[0]=0;
		else 
		{
			int len = i==0 ? 0 : MAX(0,da[r[i-1]]-1);
			while(ch[i+len]==ch[sa[r[i]-1]+len])
				++len ;
			da[r[i]] = len ;
		}
}

ll cor[M];

void tocor(int n)
{
	
	for(int i=0;i<=n;++i)
		cor[i]=0;		
		
		
	std::stack< MP > s;
	FR(i,n)
	{
		while(s.size() && da[i]<s.top().ft)
		{ 
			MP now = s.top();s.pop();
			cor[ i-s.top().sd ] += now.ft - MAX(da[i] ,s.top().ft);
		}
		if(s.size() && s.top().ft == da[i])
			s.top().sd=i;
		else
			s.push( mp(da[i],i) );
	}
	while(s.top().ft)
	{
		MP now = s.top();s.pop();
		cor[ n-s.top().sd ] += now.ft - s.top().ft;
	}
	
	/*for(int i=0;i<=n;++i)
		PR(cor[i]);	*/	
}
ll ans[M];
ll toans(int n)
{
	/*FR(i,n)
		cout << da[i] << " "<<sa[i]<<endl;
	FRE(i,n)
		PR(cor[i]);*/
	for(int i=0;i<=n;++i)
		if(cor[i])
			cor[i] = cor[i]*fact[i]%MOD;
	ans[0]=0;
	ans[1] = (ll)n*(n+1)/2;
	for(int i=2;i<=n;++i)
	{
		ans[i]=0;
		for(int j=i;j<=n;++j)
			if(cor[j])
				ans[i]= (ans[i]+cor[j]*afact[j-i]%MOD*afact[i]%MOD)%MOD;
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

makefact();
	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ; while(times--)
{	
	int n,t;
	(cin >> n >> t);
	{
		char ch[2*n+3];
		cin >> ch;
		
		sasort(ch,n);
		satoda(ch,n);
		
		tocor(n);
		toans(n);
		while(t--)
		{
			int k;
			cin >> k ;
			if(k<=n)
				cout << ans[k] << endl;
			else
				cout << "0\n";
		}
		
	};
}
	return 0;
};
/*
debug too long the tocor funciton





*/
