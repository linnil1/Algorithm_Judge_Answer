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


struct pict{
	int a[4];
}pic[300][300];

int n,m;
int vx[4]={0,0,1,-1};
int vy[4]={1,-1,0,0};

ll dis (pict& a, pict& b){
	ll sum=0;
	FR(i,3)
		sum += (a.a[i]-b.a[i])*(a.a[i]-b.a[i]) ;
	return sum ;
}

void deal(int x,int y,ll d){
	if(d<0)
		return ;
	d*=d;
	std::queue< int > q;
	pic[x][y].a[3]=0;
	q.push(x*300+y);
	while(q.size()){
		int tmp = q.front();q.pop();
		int nx = tmp/300 , ny = tmp%300;
		FR(i,4){
			int tx = nx+vx[i],ty=ny+vy[i];
			if(tx>=0 && ty >=0 && tx<n && ty < m && pic[tx][ty].a[3] &&
				dis(pic[tx][ty],pic[x][y])<=d){					
				pic[tx][ty].a[3]=0;
				q.push(tx*300+ty);
			}
		}
	}
}

void all(int x,int y,ll d){
	if(d<0)
		return ;
	d*=d;
	FR(i,n)
		FR(j,m)
			if(dis(pic[x][y],pic[i][j])<=d)
				pic[i][j].a[3]=0;
}


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int x,y,t;
	ll d;
	while(cin >> y >> x >> t >> d){
		cin >> m >> n;
		cout << m << " "<< n <<endl;
		FR(i,n){
			FR(j,m)
				FR(z,4)
					cin >> pic[i][j].a[z] ;
		}
		if(x>=0 && y >=0 && x <n && y<m && (t==0||t==1) )
			if(t==1)
				deal(x,y,d);
			else if(t==0)
				all(x,y,d);
		
		FR(i,n){
			FR(j,m)
				FR(z,4)
					cout<< pic[i][j].a[z] << " ";
			cout << endl ;
		}
	};
}
	return 0;
};
/*






*/
