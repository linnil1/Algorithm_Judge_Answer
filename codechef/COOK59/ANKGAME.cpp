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

ll arr[M];
int c[M];
int k[M];
int gokmp(int n){
	
	k[0]=0;
	for(int i=1,now=0;i<n;++i){
		while(now && arr[now]!=arr[i])
			now = k[now-1];
		if(arr[i]==arr[now])
			++now;
		k[i]=now;
	}
	return n-k[n-1];
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n){
		FR(i,n){
			cin >> arr[i];
			if(arr[i]!=1)
				arr[i]=2;
		}
		int one=0;
		BFR(i,n)
			if(arr[i]==1)
				++one;
			else
				break;
		if(one==n)
		{
			if(n%2)
				cout << "0\n";
			else
				cout << "1\n";
			continue;
		}
		
		
		FR(i,n)
			if(arr[i]==1)
				c[i]=-1,++one;
			else
				c[i] = one,one=0;
		
		
		int k = gokmp(n);		
		
		ll sum=0;
		FR(i,k)
			if(c[i]!=-1)
				sum = (sum+(c[i]>>1)+1)%MOD;
		cout << sum << endl;
		
	};
}
	return 0;
};
/*
100
6
1 1 2 1 1 2
3
1 1 2
2
2 3

*/
