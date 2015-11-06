#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
using namespace std;

int fri[M],need[M],use[M],n;

vi back[M];
vi getcircle(int a,int b)
{
	vi v;
	while(a!=b)
	{
		use[a]=-1;
		v.pb(a);
		a = fri[a];
	}
	use[b]=-1;
	v.pb(b);
	return v;
}

ll findmax(int now)
{
	use[now]=-1;
	ll nowmax=0;
	for(int i:back[now])
		if(use[i]!=-1)
			nowmax += findmax(i); 
	return max(0ll,nowmax+need[now]);
}

int findcircle()
{
	for(int i=0;i<n;++i)
		use[i]=1;
	ll have=0;//cout << "zxc\n" ;
	for(int i=0;i<n;++i)
		if(use[i]==1)
		{
			int now=i;
			while(use[fri[now]]==1)
			{
				use[now]=0;
				now = fri[now];
			}
			vi cir= getcircle( fri[now], now );
			
			
			ll sum=0,nowsum=0;
			for(int j:cir)
				sum+=need[j],
				need[j]=0;
			
			for(int j:cir)
				nowsum+=findmax(j);			
			if(nowsum+sum>0)
				have+= (nowsum+sum);
		}		
	cout << have << endl;
	
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	cin>>T;
	while(T--)
	#else
	int n;
	while(cin >> n)
	#endif	
	{
		cin>>n;		
		for(int i=0;i<n;++i)
			cin >> fri[i],
			--fri[i],
			back[i] = vi();
		for(int i=0;i<n;++i)
			cin >> need[i];
		for(int i=0;i<n;++i)
			back[ fri[i] ] .pb(i);
		
		findcircle();
		
		
	};
	return 0;
};
/*
*/
