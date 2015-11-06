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
#define mult(a,b) (a-b)*(a-b)
int arr[300][300][3],tmp[300][300][3];
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int x,y,r,w,h;
	while(cin >> y>>x >> r >> w >> h){		
		FR(i,h)
			FR(j,w)
				FR(k,3){
					cin >> arr[i][j][k];
					tmp[i][j][k] = arr[i][j][k];	
				}
		if(r>=0)
		FR(i,h)
			FR(j,w)
				if(mult(i,x)+mult(j,y) <= r*r ){					
					int c[3]={0,0,0},t=0;
					
					for(int q=-5;q<=5;++q)
						if(q+i>=0 && q+i < h)
							for(int e=-5;e<=5;++e)
								if(e+j>=0 && e+j < w){
									++t;
									FR(k,3)
										c[k]+=arr[i+q][j+e][k];	
								}
					if(t)
						FR(k,3)
							tmp[i][j][k] = (int)floor((double)c[k]/t+0.5);
				}		
						
		cout << w <<" "<< h << endl;
		FR(i,h){
			FR(j,w)
				FR(k,3)
					cout << tmp[i][j][k] <<" ";
			cout << endl;
		}
		
		
	};
}
	return 0;
};
/*






*/
