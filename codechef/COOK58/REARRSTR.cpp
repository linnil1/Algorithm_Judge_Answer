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
		return x>b.x;
	}
};

int alpha[500];

void pr(int n)
{
	char c[n+2];c[n]='\0';
	for(int i=0;i<n;++i)
		c[i]=' ';
	int len=0;
	xy arr[30];
	for(int i='a';i<='z';++i)
		if(alpha[i])
			arr[len++] = xy(alpha[i],i);
	sort(arr,arr+len);
	int now=0;
	for(int i=0,j=0;i<len;++i)
	{
		char ch = (char)arr[i].y;
		int time = arr[i].x ;
		while(now<n && time)
		{
			c[now]=ch;
			now+=2;
			--time;
		}
		if(time==0)
			--now;
		for(j;j<n&& time;++j)
			if(c[j]==' ')
			{
				c[j]=ch;
				--time;
			}
		
	}
	cout << c << endl;
	
	
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
		string s;
		cin >> s;
		for(int i='a';i<='z';++i)
			alpha[i]=0;
		int n = s.size() , l = (n+1)/2;
		for(int i=0;i<n;++i)
			++alpha[s[i]];
		int ok=1;
		for(int i='a';i<='z'&&ok;++i)
			if(alpha[i]>l)
				ok=0;
		if(ok==0)
			cout << -1 << endl;
		else
			pr(n);
		
	};
	return 0;
};
/*
*/
