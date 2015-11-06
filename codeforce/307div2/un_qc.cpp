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


int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,stu;
	while(cin >> n >> stu)
	{
		ARR(box,n)
			cin >> box[i];
		while(n && box[n-1]==0)
			--n;
		
		int b=0,f=stu;
		ll t=1;
		FR(i,n)
		{
			int now = MIN(box[i],f);
			box[i]-=now;f-=now;b+=now;
			++t;
			
			if(box[i])
			{
				int now = box[i]/stu;
				t+=now;
				box[i]-=now*stu;
				
				f=b;b=0;
				
					++t;
					now = MIN(box[i],f);
					box[i]-=now;f-=now;b+=now;
			}
		}
		cout << t-(f==stu) << endl;
		
	};
}
	return 0;
};
/*
2 1
1 1
3 2
1 0 2
4 100
3 4 5 4
1 1
100
2 1
100 100
2 3
8 7
*/
