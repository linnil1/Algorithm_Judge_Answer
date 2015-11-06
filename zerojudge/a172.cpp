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

struct seg
{
	int max,t;
	seg *l,*r;
	seg():max(0),t(0){}
	void pull()
	{
		max = std::max( l->max , r->max );
	}
};

struct {
	int o,n;//<=n
	seg *root;
	void init(int _o , int _n){
		n = _n;
		o = _o;
		root = build(o,n);
	}
	int ask(int y){
		return ask(root,o,n,o,y);
	}
	void fix(int i,int v){
		return fix(root,o,n,i,v);
	}
	
	int ori[M];
	seg* build(int l,int r)//l<=x<=r
	{
		seg* now = new seg();
		if(l==r)
		{
			//now->max = ori[l];
			return now;
		}
		int mid = (l+r)>>1;
		now->l = build(    l,mid);
		now->r = build(mid+1,  r);
		//now->pull();
		return now;		
	}
	int ask(seg* a,int l,int r,int &x,int &y)
	{
		if(l>y || r<x)
			return 0;
		if(x<=l && r<=y)
			return a->max ;
		int mid = (l+r)>>1;
		return std::max( ask(a->l,    l,mid,x,y) , 
					     ask(a->r,mid+1,  r,x,y) );
	}
	
	void fix(seg *a,int l,int r,int &i,int &v)
	{
		if(l==r)
		{
			//ori[l]+=v;
			if(v==1){
				a->t++;
				a->max=i;
			}
			else{
				if(--a->t==0)
					a->max =0;
			}
			return ;
		}
		int mid = (l+r)>>1;
		if(mid >=i) 
			fix(a->l,    l,mid,i,v);
		else
			fix(a->r,mid+1,  r,i,v);
		a->pull();	
	}	
}tree;

int toscat(int *arr,int &n){
	std::map<int,int> m;
	for(int i=0;i<n;++i)
		m[arr[i]];
	int len=1;
	for(auto &i : m )
		i.sd = len++;
	for(int i=0;i<n;++i)
		arr[i] = m[arr[i]];
	return len;
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		ARR(arr,n)cin >> arr[i];
				
		tree.init(1,toscat(arr,n)-1);
		int sum=0;
		FR(i,n){
			int t = tree.ask(arr[i]-1);
			if(t==0){
				++sum;
				tree.fix(arr[i],1);
			}
			else{
				tree.fix(t,0);
				tree.fix(arr[i],1);
			}
		}
		cout << sum << endl;
	};
}
	return 0;
};
/*






*/
