#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define ARR(arr,n) int arr[n];for(int i=0;i<n;++i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define QI std::queue<int>
#define VI std::vector<int>

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
		++n;
		ARR(f,n)
			f[i]=i;
		FOR(i,2,n)
		{
			int t;
			FOR(j,1,n)
			{
				if(j%i==1)
					t=f[j];
				else
					f[j-1]=f[j];
				if(j%i==0)
					f[j]=t;
			}	
			f[n-1]=t;
		}
		FOR(i,1,n)
			cout << f[i] << " ";
		cout << endl ;
				
		
	};
}
	return 0;
};
/*
*/
