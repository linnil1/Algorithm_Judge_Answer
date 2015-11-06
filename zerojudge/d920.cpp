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

int c[5][5],max,n=4;
int vx[4]={0,0,1,-1},
	vy[4]={1,-1,0,0};
void dfs(int x,int y,int now){
	if(now>10 )
		return ;
	int ok=1,coun=1;
	FR(i,n)
		FR(j,n-(i==n-1))
			if(c[i][j]!=coun++)
				ok=0;
	if(ok){
		max =MIN(max,now);
		//cout <<"!!";
		return ;
	}
	FR(i,4){
		int tx = x+vx[i],
			ty = y+vy[i];
		if(tx>=0 && ty>=0 && tx<n && ty<n){
			swap(c[x][y] , c[tx][ty]);			
			dfs(tx,ty,now+1);
			swap(c[x][y] , c[tx][ty]);
		}
	}
	
	
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	while(cin >> c[0][0]){
		FR(i,n)
			FOR(j,i==0,n)
				cin>>c[i][j];		
		int x,y;
		FR(i,n)
			FR(j,n)
				if(c[i][j]==0)
					x=i,y=j;
		max=11;
		dfs(x,y,0);
		if(max<=10)
			cout << max;
		else
			cout << "TOO LONG";
		cout << endl;
	};
}
	return 0;
};
/*






*/
