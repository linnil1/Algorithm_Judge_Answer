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
	int n;
	while(cin >> n)
	#endif	
	{
		int n,s;
		cin >> n >> s;
		s*=s;
		xy duck[n];
		for(int i=0,x,y;i<n;++i)
			cin >> duck[i].x >> duck[i].y ;
		xy look;
		cin >> look.x >> look.y ;
		int sum=0;
		for(int i=0;i<n;++i)
			if((duck[i].x-look.x)*(duck[i].x-look.x)+
			   (duck[i].y-look.y)*(duck[i].y-look.y)<=s)
				++sum;
		cout << sum << endl ;
		
		 
	};
	return 0;
};
/*
7min
*/
