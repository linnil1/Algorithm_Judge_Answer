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

int lose(int,int,int);
int win(int now,int odd,int even)//s
{
	if(now<=0)
		if(odd%2)
			return 1;
		else
			return 0;
	if(odd && !lose(now-1,odd-1,even))
		return 1;
		
	if(even && !lose(now-1,odd,even-1))
		return 1;
	return 0;
}
int lose(int now,int odd,int even)//d
{
	if(now<=0)
		if(odd%2)
			return 0;
		else
			return 1;
	if(odd && !win(now-1,odd-1,even))
		return 1;
		
	if(even && !win(now-1,odd,even-1))
		return 1;
	return 0;
}

int iswin(int all,int city,int odd,int even)
//s = 1 odd
//d = 0 even
{
	if(all == city)
		return odd%2==1;
	if(city==0)
		return 0;
	
	int now = (all-city);
	
	if(now%2==1)
	{
		if(city%2==0)
			if(now/2 >= odd || now/2 >=even)
				return 0;
		if(city%2==1)
			if(now/2>=odd)
				return 0;
		return 1;
	}
	else
	{
		if(city%2==0)
			return 0;
		else if(now/2 >= even)
			return 1;	
		return 0;
	}
	
	/*if(now==0 )
		if(odd%2)
			return 1;
		else
			return 0;
	if(now == odd +even)
		return 0;	
	if(odd == 0 )
		return 0;	
	if(now/2 >=odd)
		return 0;
		
	if(now%2==1)
	{
		if(now/2 >=even && odd-(now-even) %2 == 0)
			return 0;
		return 1 ;
	}	
	else
	{
		if(now/2 >=even && odd-(now-even)%2==1)
			return 0;
		return 1;
	}
		
		
	if(now/2 >=even && (odd-(now-even))%2==0)
		return 0;
	if(now/2 >=even && (odd-(now-even))%2==1)
		return 1;	
	
		
	if( now%2==0 && (now <= odd && now <=even))
		return 0;
	if ( now%2==0 && now>=even && (odd-(now-even))%2==0)
		return 0;	*/
	/*if( now%2==0 && now>=even && (odd+even-now)%2==0)
		return 0;
	return 1;*/
}
int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	/*int n,m;
	while(cin >> n >> m)
	{
		ARR(arr,n)
			cin>>arr[i];
		int odd=0,even=0;
		FR(i,n)
			if(arr[i]&1)
				++odd;
			else
				++even;
		cout
	}*/
	{		
		FR(i,100)
			for(int j=0;j<=i;++j)
				for(int k=0;k<=i;++k)
				{					
					if( win(i-j,k,i-k)!=iswin(i,j,k,i-k))
					{					
						printf("%d %d %d %d -- ",i,j,k,i-k);
						printf("%c %d\n",win(i-j,k,i-k)?'S':'D' , iswin(i,j,k,i-k));
					}
				}
	};
}
	return 0;
};
/*






*/
