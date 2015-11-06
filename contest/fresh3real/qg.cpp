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


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;

struct treap
{
	int f,b,pri,size;
	treap *l,*r;
	treap(){};
	treap(int _f,int _b):f(_f),b(_b),pri(rand()),size(1),
						l(NULL),r(NULL){};
	
		
};

int tosize(treap* a){return a? a->size : 0 ;}
void pull(treap *a)
{
	a->size = tosize(a->l) + tosize(a->r) + 1;
}


treap* merge(treap *a,treap *b)
{
	if(!a || !b)return a? a:b;
	if( a->pri > b->pri)
	{
		a->r = merge(a->r,b);
		pull(a);
		return a;
	}
	else
	{
		b->l = merge(a,b->l);
		pull(b);
		return b;
	}
}

int mi ,ma ,tt;

void splitf(treap*t , int key ,treap* &a,treap* &b)
{
	if(!t) a=b=NULL;
	else if( t->b < key)
	{		
		a = t ;
		splitf (t->r , key , a->r , b);
		pull(a);
	}
	else
	{		
		if(t->b==key)++tt;	
		mi = min (mi,t->f);
		b=t;
		splitf (t->l , key , a , b->l);
		pull(b);
	}
}

void splitb(treap*t , int key ,treap* &a,treap* &b)
{
	if(!t) a=b=NULL;
	else if( t->f <= key)
	{
		if(t->f==key)++tt;	
		ma = max (ma,t->b);
		a = t ;
		splitb (t->r , key , a->r , b);
		pull(a);
	}
	else
	{
		b=t;
		splitb (t->l , key , a , b->l);
		pull(b);
	}
}

void preout(treap *a)
{
	if(!a)return ;
	cout << a->f <<" "<< a->b<<endl;
	preout(a->l);
	preout(a->r);	
}

int main()
{
	//std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	srand(time(NULL));
	
	
	int n,q;
	while(cin >> n >> q)
	{
		treap *root=new treap(0,1);
		int mode,ml,mr;
		while(q--)
		{
		/*	puts("_________");
			preout(root);
			puts("_________");*/
			
			cin >> mode >> ml >> mr;
			if(ml > mr)
				swap(ml,mr);
			// i assume ml <= mr 
			++mr;
			mi = ml ; ma = mr; tt=0;
			
			treap *l,*now,*r;l=now=r=NULL;
			splitf(root,ml,l,now);
			splitb(now,mr,now,r);
			
			if(mode==3)
			{
				cout << tosize(now)-tt << endl ;
			}
			else if(mode==1)
			{
				now = new treap(mi,ma);
			}
			else //==2
			{
				now = NULL ;
				if( mi < ml)
					now = merge(now,new treap(mi,ml));
				if( mr < ma)
					now = merge(now,new treap(mr,ma));
			}
			root = merge( l , merge(now,r) );	
					
		}
	};
}
	return 0;
};
/*
start 80
end  96
end 190
test treap
take 30min debug the <= can be incorrect
*/
