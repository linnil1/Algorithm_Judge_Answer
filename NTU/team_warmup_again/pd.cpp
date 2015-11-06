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
	double x,y,c,d;	
	inline void IN(){
		scanf("%lf%lf%lf%lf",&x,&y,&c,&d);
	}
}arr[10010];
int n;
#define pp(x) (x)*(x)
double test(double x,double y){
	double sum =0;
	FR(i,n)
		sum += ((arr[i].d + pp(arr[i].x-x) + pp(arr[i].y-y))/arr[i].c);
	//printf("%f!\n",test);
	return sum ;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	srand(time(NULL));
	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	while(times-- && ~scanf("%d",&n)){		
		FR(i,n)
			arr[i].IN();
		double x=0,y=0,sum=test(x,y),r=1e7;
		for(int i=0;i<60;++i,r/=2)
		  for(double j=rand(),the = 2*3.1415926535/7,t=0;t<7;++t,j+=the){
			double tx = x + cos(j)*r , ty = y + sin(j)*r ;
			double end = test(tx,ty);
			if( sum > end){
				sum = end;
				x = tx ;
				y = ty ;
			}
			//printf("%f %f %f %f \n",x,y,end,sum);
		}	/*	
		sum=0;
		FR(i,n)
			sum += ( (arr[i].d + pp(arr[i].x-x) + pp(arr[i].y-y))/ arr[i].c);*/
		printf("%.9f\n",(double)n/sum);
		
		
	};

	return 0;
};
/*






*/
