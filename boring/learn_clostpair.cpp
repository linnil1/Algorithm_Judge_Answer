#include<bits/stdc++.h>
#define ll long long 
#define M 3000010
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

struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
	
	double dis(xy &b){
		return hypot(x-b.x,y-b.y);
	}
	
	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
	
};
bool cmp(const xy &a,const xy &b){
		if(a.y!=b.y)
			return a.y<b.y;
		else
			return a.x<b.x;
	}

xy arr[M];
double min = 0 ;
void find(int l,int r){
	if(l+1 >= r)
		return ;
	
	int mid = (l+r)>>1;
	find(l,mid);
	find(mid,r);	
	std::vector< xy > la,lb;
	FOR(i,l,mid)
		if( arr[i].x-arr[mid].x < min)
			la.pb ( arr[i] );
	FOR(i,mid,r)
		if( arr[i].x-arr[mid].x < min)
			lb.pb ( arr[i] );
	
	sort(ALL(la),cmp);
	sort(ALL(lb),cmp);
		
	int j=0;
	FR(i,la.size()){
		while(j<lb.size() && lb[j].y < la[i].y)++j;
		for(int k=-1;k<=1;++k)
			if(0<=j+k && j+k < lb.size())
				min = MIN(min , la[i].dis(lb[j+k]));		
	}
}


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		FR(i,n)
			scanf("%d%d",&arr[i].x,&arr[i].y);
		std::sort(arr,arr+n);
		if(n<=2){
			puts("0.0000\n");
			continue;
		}
		min = arr[0].dis(arr[1]);
		find(0,n);
		printf("%.4lf\n",min);
	};
}
	return 0;
};
/*






*/
