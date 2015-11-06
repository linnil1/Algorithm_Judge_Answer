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

struct node{
	node *l , *r ;
	int dep , val , pos ;
	node(int v):val(v){l=r=NULL;}
}*root;

void insert(node& *now ,int &x){
	if(now==NULL)
		 now = new root(x);
	else if( now->val > x )
		insert(now->l,x);
	else if( now->val < x )
		insert(now->r,x);	
}

VI d[250];int dmax;

int dfsdep(node *now){
	if(now==NULL)
		return ;
	now->pos = -1; 
	return now->dep  = 
		MAX( dfsdep(now->l) , dfsdep(now->r) ) + 1;
}
#define num(a) ( (1<<a)-1 ) 

void initpos(){
	node *now = root; 
	while(now->l)
		now = now-> l ;
	now->pos = 0 ;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		root = NULL ;
		while(n--){
			int x;scanf("%d",&x);
			insert(root,x);
		}
		dfsdep(root);
		
		initpos();
		FR(i,250)
			v[i] = VI();
		dmax=0;
	};
}
	return 0;
};
/*






*/
