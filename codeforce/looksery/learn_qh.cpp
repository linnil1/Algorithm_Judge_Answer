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

double cross(double x1,double y1,double x2,double y2)
{
	return x1*y2 - x2*y1 ; 
}
#define eps 1e-12
int find(double x1,double y1,double x2,double y2,double d)
{
	return cross(x1-d,y1+d , x2+d ,y2-d)<=0 &&  cross(x1+d,y1-d , x2-d ,y2+d)>=0;
}

int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	double x1,y1,x2,y2;
	while(cin >> x1 >>y1 >> x2 >> y2)
	{
		double min=0,max=1000000000;
		int t=100000;		
		while(t--)
		{
			double mid = (min+max)/2;
			if( find(x1,y1,x2,y2,mid) )
				max = mid;
			else
				min = mid;
		}
		printf("%.11lf\n",max);
		
	};
}
	return 0;
};
/*






*/
