#include<bits/stdc++.h>
#define ll long long 
#define M 200010
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

struct bri{
	int x,y,dir,num;
} q[M];

bool pkx(bri a,bri b){
	return  a.x<b.x;
}
bool pky(bri a,bri b){
	return  a.y<b.y;
}


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,all;
	while(cin >> all >> n){
		//
		std::map<int,int> m;		
		char ch[100];
		FR(i,n)
		{
			cin>>q[i].x >> q[i].y >> ch ;
			q[i].dir = ch[0];
			q[i].num=i;
		}
		std::sort(q,q+n,pkx);
		
		int ans[n];		
		int y=0;
		FR(i,n)
			if(q[i].dir=='U'){
				if(y <= i)
					y = i+1;
				while(y<n && q[y].dir=='U')
					++y;
				if(y==n)
					ans[ q[i].num ] = q[i].y;
				else
					ans[ q[i].num ] = q[i].y - q[y].y;
			}
		std::sort(q,q+n,pky);
		int x=0;
		FR(i,n)
			if(q[i].dir=='L'){
				if(x <= i)
					x = i+1;
				while(x<n && q[x].dir=='L')
					++x;
				if(x==n)
					ans[ q[i].num ] = q[i].x;
				else
					ans[ q[i].num ] = q[i].x - q[x].x;
			}
		FR(i,n)
			cout << ans[i] << endl;
			
	};
}
	return 0;
};
/*






*/
