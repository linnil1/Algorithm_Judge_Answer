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
#define ARR(arr,n) ll arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

struct act
{
	int s,e,v;
};

bool operator <(act a,act b)
{
	return a.s < b.s;
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		std::map<int,int> m;
		act arr[n];
		FR(i,n)
			cin >> arr[i].s >> arr[i].e >> arr[i].v,
			m[arr[i].s]=m[arr[i].e];
			
		sort(arr,arr+n);		
		int len=0;
		for(auto &i:m)
			i.sd = len++;
		
		ARR(pack,len)
			pack[i]=0;
			
		int now=0;
		FR(i,n)
		{
			int l = m[arr[i].s],r=m[arr[i].e];
			for(now;now<l;++now)
				if(pack[now]>pack[now+1])
					pack[now+1]=pack[now];
			if( pack[l]+arr[i].v > pack[r])
				pack[r] = pack[l]+arr[i].v;
		}
		for(now;now<len;++now)
			if(pack[now]>pack[now+1])
				pack[now+1]=pack[now];
		cout << pack[len-1] << endl;
			
	};
}
	return 0;
};
/*

3:00
3:15
15min ok


*/
