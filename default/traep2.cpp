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

struct treap{
	treap *l,*r;
	int size,pri;
	int val,min,max,sum;
	int turn,plus;
	treap(){};
	treap(int v):size(1),pri(rand()){
		l=r=NULL;
		plus=turn =0;
		min = max =sum =val =v;
	}
}*root;

int trsize(treap *a){ return a?a->size:0;}
int trmin(treap *a){ return a?a->min:INT_MAX;}
int trmax(treap *a){ return a?a->max:INT_MIN;}
int trsum(treap *a){ return a?a->sum:0;}

void pull(treap *a){
	a->size = trsize(a->r)+trsize(a->l)+1;
	a->min  = MINN( trmin(a->r) ,trmin(a->l),a->val);
	a->max  = MAXX( trmin(a->r) ,trmin(a->l),a->val);
	a->sum  = trsum(a->r)+trsum(a->l) + a->val ;
}
void push(treap *a){
	if(a->turn){
		a->turn = 0 ;
		swap(a->r , a->l);
		if(a->l)a->l->turn ^=1;
		if(a->r)a->r->turn ^=1;
	}
	if(a->plus){
		a->val += a->plus ;
		if(a->l) a->l->plus += a->plus;
		if(a->r) a->r->plus += a->plus;
		a->val = 0;
	}
}

treap * merge(treap *a,treap *b){
	if(!a || !b) return a?a:b;
	if( a->pri > b->pri){
		push(a);
		a->r = merge( a->r , b);
		pull(a);
	}
	else{
		push(b);
		b->l = merge( a , b->l);
		pull(b);
	}		
}

void split(treap *t,int key,treap *&a,treap *&b){
	if(!t)  {a=b=NULL;return ;}
	push(t);
	if( trsize(t->l)+1 <=key){
		a = t ;
		split(t->r ,key-trsize(t->l)-1  , a->r , b);
		pull(a);
	}
	else{
		b=t;
		split(t->l , key , a , b->l );
		pull(b);
	}
}

void instr(){
	int x,v;
	cin >> x >> v;
	treap *l=NULL,*r=NULL,*ans=NULL;
	split( root,x,l,r);
	root = merge ( merge( l, new treap(v) ),r );
}
void deltr(){
	int x;
	cin >> x;
	treap *l=NULL,*r=NULL,*ans=NULL;
	split( root,x-1,l,r);
	split(r,1,ans,r);
	root = merge ( l,r );
}

void prpre(treap *a){
	if(!a)return ;
	prpre(a->l);	
	cout << a->val << " ";	
	prpre(a->r);
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n){
		root = NULL ;
		FR(i,n){
			int x;cin >> x;
			root = merge(root,new treap(x));
		}
		int m ;cin >> m;
		while(m--){
			//prpre(root);cout << endl;
			int mode;
			cin >> mode;
			switch(mode){
				case 1:instr();break;
				case 2:deltr();break;
				case 3:case 4:case 5:case 6:case 7:
					int x,y;
					cin >> x >> y;
					treap *l=NULL,*r=NULL,*ans=NULL;
					split( root,x-1,l,r);
					split( r,y-x+1,ans ,r);
					switch(mode){
						case 3: 
							ans->turn ^=1;break;
						case 4: int v;cin>>v;
							ans->plus += v;break;
						case 5: 
							cout << trmax(ans) << endl;break;
						case 6:
							cout << trmin(ans) << endl;break;
						case 7:
							cout << trsum(ans) << endl;break;
					}
					root = merge ( merge(l,ans),r);
				break;
			}
			
		}
		//prpre(root);cout << endl;
	};
}
	return 0;
};
/*






*/
