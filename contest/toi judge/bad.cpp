#include<cstdio>
#include<cstdlib>
#include<cstring>

#include<ctime>

#include<algorithm>
/*
#include<string>
#include<iostream>
using namespace std;
*/
struct re
{
	int x1,x2,y1,y2,num;
};
#define lld long long int
int com(re &a,int &x,int &y)
{
	//printf("%d %d %d\n",a.x1,a.x2,x);
	if(!(x > a.x1 && x < a.x2))
		return -1;
	return (lld)(a.y2-a.y1)*(x-a.x1)+(lld)a.y1*(a.x2-a.x1) < (lld)y*(a.x2-a.x1);
};

bool operator < (re a,re b)
{
	if(a.x2 < b.x1 || a.x1 > b.x2)
		return 1;
	int t= com(b,a.x1,a.y1);
	if(t!=-1)
		return t;
	t= com(b,a.x2,a.y2);
	if(t!=-1)
		return t;
	//puts("zxc");
	return !(b<a);
};

struct treap
{
	treap *l,*r;
	int key,pri,bring,sum;

	treap(){};
	treap(int _k,int _b):key(_k),bring(_b),sum(1),pri(rand()),l(NULL),r(NULL){};
}*root;

int size(treap *a){return a?a->sum:0;}

void tosize(treap *a){a->sum=size(a->r)+size(a->l)+a->bring;}

treap* merge(treap *a,treap *b)
{
	if(!a || !b)return a?a:b;
	else if(a->pri > b->pri)
	{
		a->r = merge(a->r , b);
		tosize(a);
		return a;
	}
	else
	{
		b->l = merge(a , b->l);
		tosize(b);
		return b;
	};
};
void spilt(treap *t,int key,treap *&a,treap *&b)
{
	if(t==NULL)a=b=NULL;
	else if(t->key < key)
	{
		a=t;
		spilt(t->r , key , a->r , b);
		tosize(a);
	}
	else
	{
		b=t;
		spilt(t->l , key , a , b->l);
		tosize(b);
	};
};


void go(re *c,int &n,int *fin)
{
    std::sort(c,c+n);
    for(int i=0;i<n;++i)
    {
		//printf("%d %d\n",c[i].x1,c[i].y1);
		treap *r=NULL,*l=NULL,*want=NULL;
		int b=c[i].x2,
			s=c[i].x1;
		
		spilt(root,s,l,r);
		spilt(r,b ,want,r);

		int bri=size(want);
		root=merge(l,merge( new treap(c[i].y1 > c[i].y2 ? c[i].x2 : c[i].x1 ,bri) , r ));
		
		//printf("%d",bri);
		fin[c[i].num]=bri;
		
	};
};

#define ch(a,b){int e=a;a=b;b=e;}
int main()
{
	int i,j;
	int n,l,w,h;
	srand(time(NULL));
	while(~scanf("%d%d%d%d",&n,&l,&w,&h))
	{
		re c[n];
		for(i=0;i<n;++i)
		{
			re &t=c[i];
			scanf("%d%d%d%d",&t.x1,&t.y1,&t.x2,&t.y2);
			if(t.x1 > t.x2)
			{
				ch(t.x1,t.x2);
				ch(t.y1,t.y2);
			}
			c[i].num=i;
		};
		
		//init
		root=NULL;

		for(i=0;i<=l;++i)
		    root=merge(root,new treap(i,1));

		
		int fin[n];
		memset(fin,0,sizeof(fin));
		go(c,n,fin);
		
		for(i=0;i<n;++i)
		    printf("%I64d\n",(lld)w*fin[i]);
		
	};
	return 0;
};
