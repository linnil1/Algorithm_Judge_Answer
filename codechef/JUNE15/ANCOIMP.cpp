#include<bits/stdc++.h>
#define ll long long 
#define M 1003
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

int ch[M][M];
int len,quiet[M];
VI v[2*M];
bool notok(int n)
{
	FR(i,n)
		if(ch[i][i])
			return 1;
	return 0;
}
bool findcon(int n)
{
	/*VI v[n];
	FR(i,n)
		FOR(j,i+1,n)
			if(ch[i][j])
			{
				v[i].pb(j);
				v[j].pb(i);			
			}*/
	ARR(use,n)
		use[i]=-1,quiet[i]=1;
	FR(i,n)
		FR(j,n)
			if(ch[i][j])
			{
				use[i]=2;
				quiet[i]=0;
				break;
			}
	
	len=0;
	FR(i,n)
		if(use[i]==2)
		{
			v[len]=v[len+1] = VI();
			std::queue< MP > q;
			q.push( mp(i,0) );
			while(q.size())
			{
				MP now = q.front();q.pop();    
				use[now.ft]=now.sd;
				v[len + now.sd].pb(now.ft);				
				FR(j,n)
					if(ch[now.ft][j] )
						if(use[j]==2)
							q.push( mp(j,!now.sd) ) ,use[j]=!now.sd;
						else if(now.sd == use[j])
							return 1;//cant xor
							
			}
			/*if(v[len]>v[len+1])
				swap(v[len],v[len+1]);*/
			
			len+=2;
		}
/*	FR(i,len)
		PR(v[i].size());*/
	return 0;
}
int p[M][M];
void pack(int n)
{
	int all=len/2;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=all;++j)
			p[i][j]=0;
	p[0][0]=1;
	for(int i=0;i<all;++i)
	{	
		int l1 = v[2*i].size(),l2 = v[2*i+1].size();
		for(int j=n;j>=0;--j)
			if(p[j][i])
			{
				if(j+l1<=n)
					p[j+l1][i+1]=1;
				if(j+l2<=n)
					p[j+l2][i+1]=1;				
			};		
	}
	/*for(int j=0;j<=n;++j,cout <<" ")
		for(int k=0;k<=len;++k)
			if(p[j][k])
				cout << k ;
	puts("!!");*/
}
int ans[M];
void findpack(int n)
{
	int end=n/2,min=INT_MAX,minth,real ,e=len/2;
	for(int i=0;i<=n;++i)
		if(p[i][e] && abs(i-end)<min)
		{
			min = abs(i-end);
			real = end-i;
			minth = i;
		}
	FR(i,n)
		ans[i]=0;
	if(min==INT_MAX)
	{
		FR(i,end)
			ans[i]=1;
		return ;
	}
	for(int i=0;i<n&& real>0 ;++i)
		if(quiet[i])
			ans[i]=1,--real;
		
	int now = minth;
	for(int i=e-1;i>=0;--i)
	{
		int l1 = v[2*i].size() ,l2 = v[2*i+1].size();
		if(now - l1>=0 && p[now-l1][i])
		{
			now -= l1;
			for(int &j:v[2*i])
				ans[j]=1;
		}
		else if(now - l2>=0 && p[now-l2][i])
		{
			now -= l2;
			for(int &j:v[2*i+1])
				ans[j]=1;
		};
	}
}

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;scanf("%d",&times) ; while(times--)
{	
	int n;
	scanf("%d",&n);
	{
		FR(i,n)
			FR(j,n)
				scanf("%d",ch[i]+j);
		
		if(notok(n) || findcon(n))
		{
			puts("-1");
			continue;
		}		
		pack(n);
		findpack(n);
		FR(i,n)
			printf("%d ",ans[i]);
		puts("");
	};
}
	return 0;
};
/*






*/
