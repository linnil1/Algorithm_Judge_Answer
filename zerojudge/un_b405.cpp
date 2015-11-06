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
}pmem[1000000],*mem = pmem;

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
	treap *t;
	if( rand()%(a->size+b->size) < a->size){
		push(a);
		t = new (mem++) treap(*a);
		t->r = merge( a->r , b);
	}
	else{
		push(b);
		t = new (mem++) treap(*b);
		t->l = merge( a , b->l);
	}		
	pull(t);
	return t;
}

void split(treap *t,int key,treap *&a,treap *&b){
	if(!t)  {a=b=NULL;return ;}
	push(t);
	if( trsize(t->l)+1 <=key){
		a = new (mem++) treap(*t) ;
		split(t->r ,key-trsize(t->l)-1  , a->r , b);
		pull(a);
	}
	else{
		b = new (mem++) treap(*t) ;
		split(t->l , key , a , b->l );
		pull(b);
	}
}

void instr(treap *&root,treap *&now,int myxor){
	int x,v;
	cin >> x >> v;
	x^=myxor ; v^=myxor;
	treap *l=NULL,*r=NULL,*ans=NULL;
	split( root,x,l,r);
	now = merge ( merge( l, new (mem++)treap(v) ),r );
}
void deltr(treap *&root,treap *&now,int myxor){
	int x;cin >> x;
	x^=myxor ;
	treap *l=NULL,*r=NULL,*ans=NULL;
	split( root,x-1,l,r);
	split(r,1,ans,r);
	now  = merge ( l,r );
}
void findxy(treap *&root,treap *&now,int& myxor,int mode){
	int x,y;
	cin >> x >> y;
	x^=myxor ; y^=myxor;
	treap *l=NULL,*r=NULL,*ans=NULL;
	split( root,x-1,l,ans);
	split( ans,y-x+1,ans ,r);
	switch(mode){
		case 3: 
			ans->turn ^=1;break;
		case 4: int v;cin>>v;v^=myxor;
			ans->plus += v;break;
		case 5: 
			cout << (myxor=trmax(ans)) << endl;break;
		case 6:
			cout << (myxor=trmin(ans)) << endl;break;
		case 7:
			cout << (myxor=trsum(ans)) << endl;break;
	}
	now = merge ( merge(l,ans),r);
}
void prpre(treap *a){
	if(!a)return ;
	prpre(a->l);	
	cout << a->val << " ";	
	prpre(a->r);
}

treap *his[1000000];
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	srand(time(0));
	int n;
	while(cin >> n){
		his[0] = NULL ;
		mem = pmem;
		FR(i,n){
			int x;cin >> x;
			his[0] = merge(his[0],new (mem++)treap(x));
		}
		int m ;cin >> m;
		FRE(i,m){
			prpre(his[i-1]);cout << endl;
			his[i]=NULL;
			int mode , myxor=0;
			cin >> mode;
			mode^=myxor;
			switch(mode){
				case 0:{int x;cin >> x;x^=myxor;
					his[i] = his[x] ;break;	}
				case 1:instr(his[i-1],his[i],myxor);break;
				case 2:deltr(his[i-1],his[i],myxor);break;
				case 3:case 4:case 5:case 6:case 7:
					findxy(his[i-1],his[i],myxor,mode);					
					break;
				default :
					cout << "WRONG!\n";break;
			}
			
		}
		//prpre(root);cout << endl;
	};
}
	return 0;
};
/*






*/
