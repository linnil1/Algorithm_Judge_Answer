#include<bits/stdc++.h>
#define ll long long 
#define M 500010
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
#define MANN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

#include<bits/stdc++.h>
#define lld long long int


struct tree
{
	tree *l,*r;
	int val;
	tree(){};
	tree(int _v):val(_v),l(NULL),r(NULL){};
};

struct treap
{
	static treap mem[M],*pmem;
	treap *l,*r;
	int pri,f,b;
	int size,max;
	tree **t;
	treap(){};
	treap(int va,int vb,tree **_t):
		l(NULL),r(NULL),pri(rand()),t(_t),
		f(va),b(vb){};	
	
}treap::mem[M],*treap::pmem = treap::mem;


treap* merge (treap* a,treap* b)
{
	if(!a || !b) return a? a:b ;
	else if ( a->pri > b->pri)
	{
		a->r = merge( a->r , b);
		return a;
	}
	else
	{
		b->l = merge (a , b->l);
		return b;
	}
}

void splitf(treap*t , int key ,treap* &a,treap* &b)
{
	if(!t) a=b=NULL;
	else if( t->b < key)
	{
		a = t ;
		splitf (t->r , key , a->r , b);
	}
	else
	{
		b=t;
		splitf (t->l , key , a , b->l);
	}
}
void splitb(treap*t , int key ,treap* &a,treap* &b)
{
	if(!t) a=b=NULL;
	else if( t->f <= key)
	{
		a = t ;
		splitb (t->r , key , a->r , b);
	}
	else
	{
		b=t;
		splitb (t->l , key , a , b->l);
	}
}


void pre(tree *a)
{
	if(!a)return ;
	cout << a->val<< " ";
	pre(a->l);
	pre(a->r);
		
}

int main()
{
	srand(time(NULL));
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		tree *r =new tree(0);
		treap::pmem = treap::mem ;
		treap *root = new (treap::pmem++) treap(-1,INT_MAX,&r);
		
		FR(i,n)
		{
			int a;cin >> a;
			treap *tl,*tr,*now;
			tl = tr = now =NULL;
			splitf(root,a,tl,tr);	
			splitb(tr,a,now,tr);
			
			tree *t=new tree(a);
			*now->t = t ;
			now = merge( new (treap::pmem++)treap(now->f,a,&t->l),
						 new (treap::pmem++)treap(a,now->b,&t->r));
			
			root = merge( merge(tl,now),tr);	
			
		}
		pre(r);
		cout << endl ;
	};
}
	return 0;
};
/*






*/
