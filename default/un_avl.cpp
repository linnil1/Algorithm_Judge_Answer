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

struct avl{
	avl *l,*r;
	int val,dep,size;
	avl(){};
	avl(int _val):val(_val),dep(1),size(1){l=r=NULL;};
	
	
};

int fdep(avl *t){return t ? t->dep : 0;}
int fsiz(avl *t){return t ? t->size : 0;}

void rot_L(avl * &t){
	avl *k = t -> r ;
	t -> r = k -> l ;
	k -> l = t ;
	t->dep = std::max(fdep(t->l),fdep(t->r) ) + 1 ;
	t = k ;	
	cout << "L";
}
void rot_R(avl *&t){
	avl *k = t -> l ;
	t -> l = k -> r ;
	k -> r = t ;
	t->dep = std::max(fdep(t->l),fdep(t->r) ) + 1 ;
	t = k ;	
	cout  << "R" ;
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
	if(!t) t= new avl(val);
	else if(val < t->val)
		insert(t->l , val);
	else
		insert(t->r , val); 
	bal(t);
}


void del(avl *&t){
	if(!t->l && !t->r)
		t=NULL;
	else if(t->l){
		rot_R(t);
		del(t->r);
	}
	else{ // t->r
		rot_L(t);
		del(t->l);
	}
	bal(t);	
}

void remove(avl *&t , int &val){
	if(!t)return ;
	if( val < t->val)
		remove(t->l , val);
	else if( val > t->val)
		remove(t->r , val);
	else{
		del(t);		
	}
	bal(t);
}
void midorder(avl *t){
	if(!t)return ;
	cout << t->val << " ";
	midorder(t->l);		
	midorder(t->r);
}
	
	



int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n,t;
	avl *root = NULL ;
	while(cin >> t >>n){
		if(t==0)
			insert( root ,n );
		else
			remove(root,n);
		midorder(root);
		cout << endl ;
		
	};
}
	return 0;
};
/*
0 20
0 40
0 60
1 40
0 80
0 100
0 110
0 120
0 130

1 120



*/
