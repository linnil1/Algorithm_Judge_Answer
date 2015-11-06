#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define FORE(i,a,n) for(int i=a;i<=n;++i)
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
#define MP std::pair<double,double>
//using namespace std;

struct xy{
	double x,y;
	int num;
	xy(){};
	xy(double _x,double _y ,int n):
		x(_x),y(_y),num(n){};
	
	bool operator < (const xy b)const{
		return y*b.x > x*b.y;
	}
};
xy v[8];
void rect(double x1,double y1,double r,int &n,int num){	
	v[n++] = xy(x1-r,y1-r,num);
	v[n++] = xy(x1+r,y1+r,num);
	v[n++] = xy(x1-r,y1+r,num);
	v[n++] = xy(x1+r,y1-r,num);
}
bool cross(){
	if(v[0].x <=0 && v[0].y<=0 && v[1].x>=0 && v[1]>)
	
	
	sort(v,v+8);
	for(int i=3;i<8;++i){
		int four=1;
		for(int j=1;j<=3;++j)
			if( v[i-j].num != v[i].num)
				four=0;
		if(four)
			return 0;
	}
	return 1;
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	double x1,x2,y1,y2;
	while(cin >> x1 >> y1 >> x2 >> y2){
		double max = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) , min  = 0,mid;
		FR(ti,1000000){
			mid = (max+min)/2;
			int n=0;
			rect(x1,y1,mid,n,1);
			rect(x2,y2,mid,n,0);
			if( cross() )
				max = mid;
			else
				min = mid;
		}
		cout << max << endl;
	};
}
	return 0;
};
/*






*/
