#include<bits/stdc++.h>
#define ll long long 
#define M 100100
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
#define SC(a) scanf("%d",&a);
#define PR(a) printf("%d ",a);
#define VMP std::vector<MP>
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
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
	typedef ll POI; // to change [double , ll , int]
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
typedef std::vector<xy> VXY ; 
struct convexhull{
	VXY convex(xy *arr,int n){	
		assert(n>=3);
		std::sort(arr,arr+n);
		//down
		VXY v;
		v.pb(arr[0]);
		v.pb(arr[1]);
		for(int i=2;i<n;++i){
			while( v.size()>=2 && 
			(v[v.size()-1] -v[v.size()-2] ) / ( arr[i]-v.back()) <= 0 )
				v.pop_back();
			v.pb(arr[i]);
		}
		//up
		v.pb(arr[n-2]);	
		int k = v.size();
		for(int i=n-3;i>=0;--i){
			while( v.size()>=k && 
			(v[v.size()-1] -v[v.size()-2] ) / ( arr[i]-v.back()) <= 0 )
				v.pop_back();
			v.pb(arr[i]);
		}
		return v;//the last one is the first one
	}
}con;

double isstable(double &cx,double &cy ,xy &a ,xy li ){
	return (cx-a.x)*(li.x) + (cy-a.y)*(li.y);
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d",&n)){		
		xy arr[n];
		FR(i,n)
			scanf("%lld%lld",&arr[i].x,&arr[i].y);
		
				
		double cx=0,cy=0,all=0;
		FOR(i,2,n){
			double now = (arr[0]-arr[i-1])/(arr[i]-arr[i-1]) ;
			all += now ;
			cx += now * (arr[0].x + arr[i-1].x + arr[i].x);
			cy += now * (arr[0].y + arr[i-1].y + arr[i].y);
		}
		cx/=all*3;
		cy/=all*3;		
		
		//printf("%f %f\n",c.x,c.y);
		
		VXY v = con.convex(arr,n);
		int ans=0;
		FOR(i,1,v.size()){
			//cout << c << v[i-1] << v[i] <<"!\n";
			if( isstable(cx,cy,v[i-1],v[i]-v[i-1])>0 && 
				isstable(cx,cy,v[i]  ,v[i]-v[i-1])<0 )
				++ans;//,puts("ok")
		}
		printf("%d\n",ans);
		
		 
	};

	return 0;
};
/*






*/
