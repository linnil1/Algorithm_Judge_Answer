#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
using namespace std;
struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
	
	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	cin>>T;
	while(T--)
	#else
	#endif	
	{
		int n=3;
		xy arr[n];
		for(int i=0;i<n;++i)
			cin >> arr[i].x >> arr[i].y ;
		sort(arr,arr+n);
		int ok=1;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(arr[i].y > arr[j].x)
					ok=0;
		cout << (ok?"Happy":"QQ" )<< endl ;
					
	};
	return 0;
};
/*
5min
*/
