#include<bits/stdc++.h>
#define ll long long 
#define M 300010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define FORE(i,a,n) for(int i=a;i<=n;++i)
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
#define MP std::pair<ll,char>
//using namespace std;

char ori[M];
VI v;
ll max=0;

MP p[5010];int lenp=0;

void turnc ()
{
	lenp=0;
	int same=0,now=-1;
	for(int i=0;ori[i];++i)
	{	
		if(isdigit(ori[i]))
			p[lenp++] = mp(ori[i]-'0' , 0);

		if(ori[i]=='*' )
		{		
			if(now==ori[i])
			{		
				if(same>=2 )
				{
					p[lenp-3].ft *= p[lenp-1].ft;
					lenp = lenp-1;
				}
				else
					++same,p[lenp++] = mp(-1 , '*');
			}
			else
				now=ori[i],same=1,
				p[lenp++] = mp(-1 , '*');			
		}
		if(ori[i]=='+' )
		{		
			if(now==ori[i])
			{		
				if(same>=2 )
				{
					p[lenp-3].ft += p[lenp-1].ft;
					lenp = lenp-1;
				}
				else
					++same,p[lenp++] = mp(-1 , '+');;
			}
			else
				now=ori[i],same=1,
				p[lenp++] = mp(-1 , '+');			
		}
	};
	//FR(i,lenp)
	//	cout << p[i].ft << " "<< p[i].sd << endl;
	v.pb(-1);
	FR(i,lenp)
		if(p[i].sd=='*')
			v.pb(i);	
	v.pb(lenp);
}
void todo(MP &a,MP &b)
{
	if(a.sd=='+')
		a.ft+=b.ft;
	else
		a.ft*=b.ft;
}

ll cal(MP *p,int a,int b)
{
	MP st[10];int now=0;
	st[0].ft=0;
	for(a;a<b;++a)
		if(p[a].ft!=-1)
			st[now++].ft = p[a].ft;
		else 
			if(p[a].sd == '+' )
			{				
				while(now>1)
				{
					todo(st[now-2],st[now-1]);
					--now;
				}
				st[now-1].sd = '+';				
			}
			else
			{
				while(now>1 && st[now-2].sd=='*')
				{
					todo(st[now-2],st[now-1]);
					--now;
				}
				st[now-1].sd = '*';
			};
	while(now>1)
	{
		todo(st[now-2],st[now-1]);
		--now;
	}
	//cout << st[0].ft << " ";
	return st[0].ft;
}

int h[2];
void dfs(VI &v,int now,int t)
{
	if(t==2)
	{
		ll all =cal(p,h[0]+1,h[1]);
		MP copy[lenp];int clen=h[0]+1;
		FR(i,clen)
			copy[i] = p[i];
		copy[clen++] = mp(all , 0 );
		FOR(i,h[1],lenp)
			copy[clen++] = p[i];
		all = cal(copy,0,clen);
		
		if(all > max)
			max = all;
		return ;
	}
	for(now;now<v.size();++now)
	{
		h[t]=v[now];
		dfs(v,now+1,t+1);
	}
}


int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> ori)
	{
		v = VI();
		turnc();
		max= cal(p,0,lenp);
		dfs(v,0,0);
		cout << max << endl ;
	};
}
	return 0;
};
/*






*/
