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
#define MP std::pair<string,int>
//using namespace std;

struct con{
	string name;
	std::vector< MP > ani;
};



std::map<string,int> m;
bool mycomp (MP a,MP b){
	return m[a.ft] < m[b.ft];
}
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		con c[n];int len=0;
		m.clear();int mlen=1;
		while(n--){
			string ani,wh;
			int num;
			cin >> ani >> num >> wh;
			if(!m[ani])
				m[ani]=mlen++;
				
			int ok=1;
			FR(i,len)
				if(wh == c[i].name)
				{
					int mok=1;
					FR(j,c[i].ani.size())
						if(c[i].ani[j].ft == ani){						
							c[i].ani[j].sd+=num;
							mok=0;
							break;
						}
					if(mok){
						c[i].ani.pb( mp(ani,num));
					}					
					ok=0;
					break;
				}
			if(ok){
				c[len].name=wh;
				c[len].ani.clear();
				c[len++].ani.pb( mp(ani,num) );
			}
		}
		
		FR(i,len){
			cout << c[i].name << " : ";
			std::sort(ALL(c[i].ani),mycomp);
			FR(j,c[i].ani.size()){
				if(j)
					cout << ", ";
				cout << c[i].ani[j].ft << " " << c[i].ani[j].sd ;
			}
			cout << endl;
		}
		
	};
}
	return 0;
};
/*






*/
