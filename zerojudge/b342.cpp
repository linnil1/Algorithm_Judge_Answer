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



struct seg
{
	int sum,name;
	seg *l,*r;
	seg():sum(0),name(-2){}
	void push(){
		if(name!=-1)
			l->name = r-> name = name;
	}
	void pull()
	{
		sum = l->sum + r->sum ;
	}
};

seg* build(int l,int r)//l<=x<=r
{
	seg* now = new seg();
	if(l==r)
	{
		return now;
	}
	int mid = (l+r)>>1;
	now->l = build(    l,mid);
	now->r = build(mid+1,  r);
	//now->pull();
	return now;		
}
int ask(seg* a,int l,int r,int x,int y)
{
	if(l>y || r<x)
		return 0;
	if(x<=l && r<=y)
		return a->sum ;
		
	int mid = (l+r)>>1;
	return  ask(a->l,    l,mid,x,y) +
			ask(a->r,mid+1,  r,x,y) ;
}

int askname(seg* a,int l,int r,int i){
	if(l==r)
	{
		return a->name;
	}
	a->push();
	int mid = (l+r)>>1;
	if(mid >=i) 
		return askname(a->l,    l,mid,i);
	else
		return askname(a->r,mid+1,  r,i);
}
int fixname(seg* a,int l,int r,int x,int y,int num)
{
	if(l>y || r<x)
		return 0;
	if(x<=l && r<=y)
		return a->name = num ;
	a->push();
	a->name = -1 ;
	int mid = (l+r)>>1;
	fixname(a->l,    l,mid,x,y,num) ;
	fixname(a->r,mid+1,  r,x,y,num) ;
}
void fix(seg *a,int l,int r,int i,int v)
{
	if(l==r)
	{
		//ori[l]+=v;
		a->sum=v;
		return ;
	}
	int mid = (l+r)>>1;
	if(mid >=i) 
		fix(a->l,    l,mid,i,v);
	else
		fix(a->r,mid+1,  r,i,v);
	a->pull();	
}




struct blo{
	int lx,rx,ly,ry,num;
	bool operator < (const blo &b)const{
		return ly < b.ly ;
	}
}blnum[33000];
struct xy{
	int x,y,num,out;
	xy(){};
	xy(int _x,int _y,int _num,int _out):
		x(_x),y(_y),num(_num),out(_out){};
	bool operator < (const xy &b)const{
		if(x!=b.x)
			return x < b.x ;
		else
			return out < b.out ;
	}
}cor[M];

std::map<int,int> sca;

VI ans,bloans;

void scanline(std::vector<xy>& v){
	int number=0;
	for(auto &i : sca)
		i.sd = number ++;	
	
	seg *root;
	root = build(0,number-1);
	
	for( xy &now : v){
		if(now.out == 2)//2 3 
			   ans[now.num] =  askname(root,0,number-1, sca[ now.y] );
		else if(now.out == 3)
			bloans[now.num] =  ask(root,0,number-1,0, sca[ now.y] );
		else if(now.out == 0){//in
			fix(root,0,number-1,sca[ blnum[now.num].ly ] , 1);
			fix(root,0,number-1,sca[ blnum[now.num].ry ] , -1);
			fixname(root,0,number-1,sca[ blnum[now.num].ly ],sca[ blnum[now.num].ry],blnum[now.num].num);
		}
		else {//1
			fix(root,0,number-1,sca[ blnum[now.num].ly ] , 0);
			fix(root,0,number-1,sca[ blnum[now.num].ry ] , 0);	
			fixname(root,0,number-1,sca[ blnum[now.num].ly ],sca[ blnum[now.num].ry],-2);		
		}
	}
}


int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,m;
	while(cin >> n ){
		sca = std::map< int,int>();
		FR(i,n){
			cin >> blnum[i].lx >> blnum[i].ly >> blnum[i].rx >> blnum[i].ry ;
			blnum[i].num = i;
		}
		sort(blnum,blnum+n);
		
		std::vector< xy > v;
		FR(i,n){
		 	sca[blnum[i].ly];
		 	sca[blnum[i].ry];	
		 	v.pb (xy( blnum[i].lx,blnum[i].ly,i,3));//block
			v.pb ( xy( blnum[i].lx,0,i,0) );//in
			v.pb ( xy( blnum[i].rx,0,i,1) );//out		
		}
		
		bloans = VI(n);
		cin >> m;
		ans = VI(m);
		FR(i,m){
			int x,y;
			cin >> x >> y;			
			v.pb ( xy(x,y,i,2));//ans
			sca[y];
		}		
		sort(ALL(v));
		scanline(v);
		FR(i,n)
			cout << bloans[i] << " " ;
		cout << endl;
		FR(i,m){
		
			if(ans[i]==-2)
				ans[i]=-1;
			cout << ans[i] << endl ;
		}
		
	};
}
	return 0;
};
/*






*/
