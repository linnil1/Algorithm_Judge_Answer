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

struct avl{
	avl *l,*r;
	int val,dep,ti;
	avl(){};
	avl(int _val):val(_val),dep(1),ti(1){l=r=NULL;};
	
	
};
avl pmem[100020],*mem;
int fdep(avl *t){return t ? t->dep : 0;}

void rot_L(avl * &t){
	avl *k = t -> r ;
	t -> r = k -> l ;
	k -> l = t ;
	t->dep = std::max(fdep(t->l),fdep(t->r) ) + 1 ;
	t = k ;	
	//cout << "L";
}
void rot_R(avl *&t){
	avl *k = t -> l ;
	t -> l = k -> r ;
	k -> r = t ;
	t->dep = std::max(fdep(t->l),fdep(t->r) ) + 1 ;
	t = k ;	
	//cout  << "R" ;
}	
void bal(avl *&t){
	if(!t)return ;
	if(fdep(t->l) >= fdep(t->r)+2 ){
		if( fdep(t->l->l) < fdep(t->l->r))
			rot_L(t->l);
		rot_R(t);
	}
	else if(fdep(t->l)+2 <= fdep(t->r) ){
		if( fdep(t->r->l) > fdep(t->r->r) )
			rot_R(t->r);
		rot_L(t);
	}
	//pull
	t->dep = std::max(fdep(t->l),fdep(t->r) ) + 1 ;
}	
void insert(avl * &t,int &val){
	if(!t) t= new (mem++)avl(val);
	else if(val < t->val)
		insert(t->l , val);
	else if(val > t->val)
		insert(t->r , val);
	else
		t->ti++; 
	bal(t);
}

void midorder(avl *t){
	if(!t)return ;
	
	midorder(t->l);
	printf("%d %d\n",t->val,t->ti);		
	midorder(t->r);
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)){
		avl *root=NULL;
		mem = pmem;
		while(n--){
			int x;
			scanf("%d",&x);
			insert(root,x);
		}
		midorder(root);
		
	};
}
	return 0;
};
/*






*/
