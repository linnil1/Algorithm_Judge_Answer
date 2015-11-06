#include<bits/stdc++.h>
#define ll long long 
#define M 1000010
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

struct treap
{
	static treap mem[M],*pmem;
	treap *l,*r;
	int pri,val;
	int size;
	treap(){};
	treap(int _val):l(NULL),r(NULL),pri(rand()),val(_val),
					size(1){}	
	
}treap::mem[M],*treap::pmem = treap::mem;

int size(treap *a){return a ? a->size : 0 ;} 

void pull(treap *a)
{
	a->size = size(a->r) + size(a->l) + 1; 
}

treap* merge (treap* a,treap* b)
{
	if(!a || !b) return a? a:b ;
	else if ( a->pri > b->pri)
	{
		a->r = merge( a->r , b);
		pull(a);
		return a;
	}
	else
	{
		b->l = merge (a , b->l);
		pull(b);
		return b;
	}
}


void split(treap*t , int key ,treap* &a,treap* &b)
{
	if(!t) a=b=NULL;
	else if( t->val < key)
	{
		a = t ;
		split (t->r , key , a->r , b);
		pull(a);
	}
	else
	{
		b=t;
		split (t->l , key , a , b->l);
		pull(b);
	}
}

treap *root ;




struct xy
{
	int x,y,num;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
	
	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
};


void fix(xy &a){
	treap *l=NULL,*r=NULL;
	split(root,a.y,l,r);
	root = merge(merge(l,new (treap::pmem++)treap(a.y)) ,r);
}
int fsize(xy &a){
	treap *l=NULL,*r=NULL;
	split(root,a.y+1,l,r);
	int ans = size(l);
	root = merge(l,r);
	return ans;
}
#define squ(a,b) ((a-b)*(a-b))
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 
srand(time(NULL));
	//freopen("..\\in.txt","r",stdin);
	int cas=1;
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	
	while(cin >> n && n){
		
		root = NULL ;
		xy cor[n];
		FR(i,n){
			cin >> cor[i].x >> cor[i].y ;
			
		}		
		xy o[2];		
		cin >> o[0].x >> o[0].y >> o[1].x >> o[1].y ; 
		FR(i,n)
			cor[i] = xy ( squ(cor[i].x,o[0].x) + squ(cor[i].y,o[0].y) ,
						  squ(cor[i].x,o[1].x) + squ(cor[i].y,o[1].y) );
	
		int m;cin>>m;
		xy ask[m];			
		FR(i,m){
			cin >> ask[i].x >> ask[i].y ;
			ask[i].x *= ask[i].x ;
			ask[i].y *= ask[i].y ;
			ask[i].num = i ;
		}
			
		sort(cor,cor+n);
		sort(ask,ask+m);
		int ans[m];	
		int j=0;
		FR(i,m){
			while(j<n && cor[j].x <= ask[i].x)
				fix(cor[j++]);
			ans [ ask[i].num ] = fsize(ask[i]);			
		}
		cout << "Case "<<(cas++) << ":\n";
		FR(i,m)
			cout << ans[i] << endl;
	};
}
	return 0;
};
/*






*/
