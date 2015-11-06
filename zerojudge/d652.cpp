#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;



int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		ARR(arr,n)
			cin >> arr[i];
		int mth=0;
		FOR(i,1,n)
			if(arr[i]<arr[mth])
				mth = i ;
		
		int sum=0;
		while(mth+2<n)
		{
			sum += arr[mth]*arr[mth+1]*arr[mth+2];
			FOR(i,mth+2,n)
				arr[i-1] =arr[i];
			--n;
		}		
		int m=0;
		while(mth-2>=m)
		{
			sum += arr[mth]*arr[mth-1]*arr[mth-2];
			for(int i=mth-2;i>=m;--i)
				arr[i+1] =arr[i];
			++m;
		}	
		if(mth!=n-1 && mth!=m)
			sum += arr[m]*arr[m+1]*arr[m+2]	;
		cout << sum << endl ;
		
	};
}
	return 0;
};
/*
16min
reading question
*/
