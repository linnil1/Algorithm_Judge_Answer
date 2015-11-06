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
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;
struct xy{
	typedef double POI; // to change [double , ll , int]
	POI x,y;
	xy(){};
	xy(POI _x,POI _y):x(_x),y(_y){};
	friend std::istream& operator >> (std::istream &in, xy &a){
		in >> a.x >> a.y;
	}
	friend std::ostream& operator << (std::ostream &out, xy &a){
		out << a.x <<" "<< a.y<< endl;
	}
	xy operator + (const xy &b)const{
		return xy(x+b.x,y+b.y);
	}
	xy operator - (const xy &b)const{//ab = a-b
		return xy(x-b.x,y-b.y);
	}
	POI operator * (const xy &b)const{
		return x*b.x + y*b.y ;
	}
	POI operator / (const xy &b)const{
		return x*b.y - y*b.x;
	}
	bool operator < (const xy &b)const{
		return x!=b.x ? x<b.x : y <b.y;
	}
};


xy v[M];


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		FR(i,n)
			cin >> v[i];
		double max=0;
		FR(i,n)
			FOR(j,i,n)
				FOR(k,j,n){
					double now = v[i]/v[j] + v[j]/v[k] + v[k]/v[i];
					if(std::fabs(now) > max)
						max= fabs(now);
				}
		printf("%.6lf\n",max/2);
	};
}
	return 0;
};
/*






*/
