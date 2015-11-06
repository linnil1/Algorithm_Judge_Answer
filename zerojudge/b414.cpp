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
#define MINN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;
struct seg
{
	int yes,time;
	seg *l,*r;
	seg(){}
	
	void pull()
	{
		yes = l->yes + r->yes;
	}
}*root;

seg* build(int l,int r)//l<=x<=r
{
	seg* now = new seg();
	if(l==r)
	{
		now->yes = 0;
		now->time = 0;
		return now;
	}
	int mid = (l+r)>>1;
	now->l = build(    l,mid);
	now->r = build(mid+1,  r);
	now->pull();
	return now;		
}
int ask(seg* a,int l,int r,int x,int y)
{
	if(l>y || r<x)
		return 0;
	if(x<=l && r<=y)
		return a->yes ;
		
	int mid = (l+r)>>1;
	return  ask(a->l,    l,mid,x,y) +
			ask(a->r,mid+1,  r,x,y) ;
}

void fix(seg *a,int l,int r,int i,int io)
{
	if(l==r)
	{
		//ori[l]+=v;
		if(io==0){//in
			if(a->time++ == 0)
				a->yes=1;
		}
		else{//out
			if(--a->time==0)
				a->yes=0;
		}
		return ;
	}
	int mid = (l+r)>>1;
	if(mid >=i) 
		fix(a->l,    l,mid,i,io);
	else
		fix(a->r,mid+1,  r,i,io);
	a->pull();	
}

void renew (seg* a,int l,int r){
	if(l==r){
		a->time = a->yes=0;
		return ;
	}
	int mid = (l+r)>>1;
	renew(a->l,l,mid);
	renew(a->r,mid+1,r);	
	a->time = a->yes = 0 ;
}


struct structask{
	int x,y,a,b,num,blo;
	bool operator < (const structask &s)const{
		if(blo != s.blo)
			return blo < s.blo;
		else
			return y < s.y ;
	}
}stask[1000010];
int  arr[100100] ,ans[1000100],n;


void moteam(int &l,int &r,int x,int y){
	while(r<=y)
		fix(root,1,n,arr[r++],0);
	while(l<x)
		fix(root,1,n,arr[l++],1);
	while(x<l)
		fix(root,1,n,arr[--l],0);	
}


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int m,gap;
	while(~scanf("%d%d",&n,&m)){
		root = build(1,n);
		FR(i,n)
			scanf("%d",arr+i);
		
		gap = (int)sqrt(n);
		FR(i,m){
			scanf("%d%d%d%d", 
				&stask[i].x, &stask[i].y, &stask[i].a, &stask[i].b );
			stask[i].num=i;
			stask[i].blo = stask[i].x/gap;
		}
		std::sort(stask,stask+m);
		
		int l=0,r=0,now=-1;
		
		FR(i,m){
			if( stask[i].blo != now){
				renew(root,1,n) ;
				now = stask[i].blo;
				l = r = now*gap;
			}
			moteam(l,r,stask[i].x,stask[i].y);
			ans[ stask[i].num ] = ask(root,1,n,stask[i].a,stask[i].b);
		} 
		
		FR(i,m)
			printf("%d\n",ans[i]);
		
	};
}
	return 0;
};
/*






*/
