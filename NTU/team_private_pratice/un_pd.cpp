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
int IN(){
	char c[100];
	scanf("%s",c);
	int i;int sum=0,len = strlen(c);
	for(i=0;i<len && c[i]!='.';++i)
		sum = sum*10 + c[i]-'0';
	sum*=100;int t=10;
	for(++i;i<len;++i,t/=10)
		sum += (c[i]-'0')*t;
	return sum ;
}
struct xy{
	ll x,y;
	ll rx,ry;
	ll inty;
	void in(){
		x = IN();
		y = IN();
		rx = IN();
		ry = IN();
		if(rx < x){
			swap(rx,x);
			swap(ry,y);
		}		
		
		rx = rx - x;
		ry = ry - y;
		if(rx==0 && ry <0){
			y += ry;
			ry = - ry;
		}
		if(rx)
			inty = rx*y-ry*x; 
		else
			inty = x;
	}
	bool operator < (const xy &b)const{
		if(rx*b.ry != ry*b.rx )
			return rx*b.ry < ry*b.rx ;
		
		if(rx)
			if( inty*b.rx != b.inty*rx)
				return inty*b.rx < b.inty*rx ;
			else
				return x< b.x ;
		else if(x != b.x )
			return x < b.x;
		else
			return y<b.y;
	}
};

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d",&n) && n){		
		xy c[n];
		FR(i,n)
			c[i].in();
		sort(c,c+n);
		/*FR(i,n)
			printf("%I64d %I64d %I64d %I64d %I64d\n",c[i].x,c[i].y,
				c[i].rx,c[i].ry,c[i].inty);*/
		
		
		int sum=0;
		for(int i=0;i<n;){
			int j;
			ll maxx=c[i].x+c[i].rx,
			   maxy=c[i].y+c[i].ry;
			for(j=i+1;j<n ;++j)
				if(c[i].rx*c[j].ry != c[i].ry*c[j].rx || 
					c[i].inty*c[j].rx!=c[j].inty*c[i].rx)
						{break;}
				else {
					if(c[j].rx==0 )
						if(maxy >= c[j].y)
							maxy = MAX(maxy , c[j].y+c[j].ry);
						else
							break;
					else
						if(maxx >= c[j].x)
							maxx = MAX(maxx , c[j].x+c[j].rx);
						else
							break;				
				}
				
			++sum ;
			i = j ;
		}
		printf("%d\n",sum);
	};

	return 0;
};
/*






*/
