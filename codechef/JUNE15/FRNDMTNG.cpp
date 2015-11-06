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
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ; while(times--)
{	
	ll m1 , m2;
	while(cin >> m1 >> m2)
	{
		ll all = m1*m2, need = 0, t1,t2;
		cin >> t1 >> t2;
		
		/*if(t1==0 && t2==0)
		{
			cout << 1/(double)MAX(m2,m1) << endl;
			continue;
		}*/
		
		if(t2<m1)
		{			
			if(t2+m2>m1)
				need += (m1-t2)*(m1-t2);
			else
				need += (m1-t2+m1-m2-t2)*m2;
		}
		if(t1<m2)
		{			
			if(t1+m1>m2)
				need += (m2-t1)*(m2-t1);
			else
				need += (m2-t1+m2-m1-t1)*m1;
		}
		
		//cout << need << " "<<all << endl;
		cout << 1- (double)need/2/all << endl;
	};
}
	return 0;
};
/*
i don't know why not use the first if and correct





*/
