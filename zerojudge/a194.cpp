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


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;



int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		ARR(arr,n)
			cin >> arr[i];
		int len=1;
		FOR(i,1,n)
		{
			if(arr[i]<=arr[len-1])
			{
				arr[len++]=arr[i];
				continue;
			}
			FR(j,len)
				if(arr[i]>arr[j])
				{
					arr[j] = arr[i];
					break;					
				};
		}
		cout << len << endl;
	};
}
	return 0;
};
/*
<=problem
12min
*/
