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


struct structask{
	int x,y,a,b,num,blo;
	bool operator < (const structask &s)const{
		if(blo != s.blo)
			return blo < s.blo;
		else
			return y < s.y ;
	}
}stask[1000010];
int  arr[100100] ,ans[1000100],n,gap;
int blo[100100],bloh[100100],blon;


inline void fix(int &a,int io){
	if(io==0){//in
		if(blo[a]++==0)
			++bloh[a/gap];
	}
	else {//out
		if(--blo[a]==0)
			--bloh[a/gap];
	}
}


void moteam(int &l,int &r,int x,int y){
	while(r<=y)
		fix(arr[r++],0);
	while(l<x)
		fix(arr[l++],1);
	while(x<l)
		fix(arr[--l],0);	
}

void renew(){
	FRE(i,n)
		blo[i]=0;
	for(int i=0;i<=blon;++i)
		bloh[i]=0;
}
int ask(int a,int b){
	int sum=0;
	if(a/gap == b/gap){
		for(int i=a;i<=b;++i)
			if(blo[i])
				++sum;
		return sum;
	}
	//mid
	int ga = (a/gap+1),
		gb = (b/gap);
	
	for(int i=ga;i<gb;++i)
		sum += bloh[i];
	for(int i=ga*gap-1;i>=a;--i)
		if(blo[i])
			++sum;
	for(int i=gb*gap;i<=b;++i)
		if(blo[i])
			++sum;
	return sum ;	
}




int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int m;
	while(~scanf("%d%d",&n,&m)){
		FR(i,n)
			scanf("%d",arr+i);
		
		gap = (int)sqrt(n);
		blon = n/gap+1 ;
		FR(i,m){
			scanf("%d%d%d%d", 
				&stask[i].x, &stask[i].y, &stask[i].a, &stask[i].b );
			stask[i].num=i;
			--stask[i].x;
			--stask[i].y;
			stask[i].blo = stask[i].x/gap;
		}
		std::sort(stask,stask+m);
		
		int l=0,r=0,now=-1;
		
		FR(i,m){
			if( stask[i].blo != now){
				now = stask[i].blo;
				renew() ;
				l=r=gap*now;
			}
			moteam(l,r,stask[i].x,stask[i].y);
			ans[ stask[i].num ] = ask(stask[i].a,stask[i].b);
		} 
		
		FR(i,m)
			printf("%d\n",ans[i]);
		
	};
}
	return 0;
};
/*






*/
