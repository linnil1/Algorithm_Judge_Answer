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
#define ARR(arr,n) ll arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

ll mnum(ll *arr,int n,ll s){
	int l =0 ,r=0;
	ll now=0,sum=0;
	FR(l,n){		
		while(r<n && now<=s)
			now += arr[r++];
		sum+= r-l-(now>s);
		now -= arr[l];
	}
	//cout << s <<" " << sum << endl;
	return sum;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		ARR(arr,n)
			cin >> arr[i];
		std::sort(arr,arr+n);
		FOR(i,1,n)
			arr[i-1] = arr[i]-arr[i-1];
		ll want = (ll)n*(n-1)/2;
		if(want&1)
			want = want/2;
		else
			want = want/2-1;
		
		
		--n;
		ll min=0,max = 1000000001 , mid ;
		while(min+1<max){
			mid = (min + max)>>1;
			if(mnum(arr,n,mid)<=want)
				min = mid ;
			else
				max = mid;
		}		
		max = mnum(arr,n,min)>=want+1 ? min : max;
		cout << max << endl;
	};
}
	return 0;
};
/*

forget to change int to ll




*/
