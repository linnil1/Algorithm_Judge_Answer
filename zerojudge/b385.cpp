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

int fbnum(int n,int x,int y){
	x= (x-1)/2+1 ; y = (y-1)/2+1;
	int k = n/2;	
	if(y < k/2)
		return 2;
	if(y > k/2+2)
		return 3;
	if(y ==k/2+2 && x!=k/2+1 )
		return 2;		
	if(y ==k/2+1 && x==k/2+1 )
		return 2;
	return 1;
}
int fb(int n,int x,int y){
	int num = fbnum(n,x,y);
	int b[4][4] = {{},{4,2,1,3},{1,2,4,3},{4,3,1,2}};
	return b[num][((x-1)&1)*2+ ( (y-1)&1)];	//
}
int fa(int n,int x,int y){
	
	int k=n/2; x= (x-1)/2+1 ; y = (y-1)/2+1;
	int now=0,nx=0,ny=k/2+1;
	while(!( x==nx && y==ny)){
		//printf("%d %d\n",nx,ny);
		if(now%k==0){
			if(++nx>k)
				nx-=k;
		}			
		else
			--nx,--ny;
		if(ny==0)ny+=k;
		if(nx==0)nx+=k;
		++now;
	}
	return (now-1)*4;
}


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ; while(times--)
{	
	int n,x,y;
	/*while(cin >> n){
		FRE(i,n){
			FRE(j,n)
				printf("%3d ",fa(n*2,i,j));
			puts("");
		}
	}*/
	while(cin >> n >> x >> y){
		cout << fb(n,x,y)+fa(n,x,y) << endl;
	};
}
	return 0;
};
/*






*/
