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
	typedef ll POI;
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
	
	VXY v;
	void type(){
		FR(i,v.size())
			cout << v[i];
	}
	ll area(){
		if(v.size()<=2)
			return 0;
		ll sum=0;
		FOR(i,1,v.size())
			sum += v[i-1]/v[i];
		sum += v[v.size()-1]/v[0];
		return sum;
	}
	double area2(){
		return (double)area()/2;
	}
	
	VXY convex(xy *arr,int n){	
		if(n<3)
			puts("ERROR");
		std::sort(arr,arr+n);
		//down
		v = VXY();
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
};


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	(cin >> n);{
		xy a[n];
		FR(i,n)
			cin >> a[i];
		int m;cin >> m;
		xy b[m];
		FR(i,m)
			cin>> b[i];
			
		xy st[n*m];int len=0;	
		FR(i,n)
			FR(j,m)
				st[len++] = xy( b[j] -a[i]);
		convexhull v;
		v.convex(st,len);
		//type(v);
		printf("Case #%d: %.1lf\n",cases,v.area2());
		//cout << "Case #"<< cases << ": "<< << endl;
	};
}
	return 0;
};
/*
71min too slow





*/
