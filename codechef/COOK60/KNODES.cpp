#include<bits/stdc++.h>
#define ll long long 
#define M 100100
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
VI v[M];
int pre[20][M];

int dep[M];
void bfs(int n){
	FRE(i,n)
		dep[i]=-1;
	QI q;
	q.push(1);dep[1]=0;pre[0][1] = 1;
	while(q.size()){
		int now = q.front();q.pop();
		for(int &j:v[now])
			if( dep[j]==-1 ){
				pre[0][j] = now ;
				dep[j] = dep[now]+1;
				q.push(j) ;
			}
	}
}
void gofa(int n){
	for(int i=1;i<18;++i)
		FRE(j,n)
			pre[i][j] = pre[i-1][ pre[i-1][j] ];
}

int findeq(int a,int b){ 
	if( dep[a] < dep[b])
		return findeq(b,a);
		
	int gap = dep[a] - dep[b] ;	
	
	for(int i=0;gap;++i,gap>>=1)
		if(gap&1)
			a = pre[i][a];
	return a;	
}
int findfa(int a,int b){
	if(dep[a] > dep[b])
		a = findeq(a,b);
	else if(dep[a] < dep[b])
		b = findeq(b,a);
	if(a==b)
		return a;
	for(int i=17;i>=0;--i)
		if( pre[i][a]!= pre[i][b]){
			a=pre[i][a];
			b=pre[i][b];
		}	
	return pre[0][a] ;
}

bool cmp(int x,int y){
	return dep[x]>dep[y] ;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0);
	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d",&n)){		
		FRE(i,n)
			v[i] = VI();
		FOR(i,1,n){
			int x,y;scanf("%d%d",&x,&y);
			v[x].pb(y);
			v[y].pb(x);
		}
				
		bfs(n);
		gofa(n);
		/*while(1){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d ",findfa(x,y));
		}*/
		/*FRE(i,n)
			printf("%d ",pre[0][i]);
		puts("");*/
		
		
		int m;scanf("%d",&m);
		while(m--){
			int k;scanf("%d",&k);
			ARR(st,k)
				scanf("%d",st+i);
			
			sort(st,st+k,cmp);
			int two=1,a=st[0],b,ok=1;
			for(int i=1;i<k &&ok ;++i){
			
				int oa = findeq( a,st[i] )==st[i];
				int ob;
				if(two==2)
					ob = findeq( b,st[i] )==st[i] ;
					
				if(two==1 )
					if(oa==0){				
						two=2;
						b=st[i];
					}
					else
						a=st[i];
				else if(oa==0 && ob==0)
					ok=0;
				else if(oa==1 && ob==0)
					a = st[i] ;
				else if(oa==0 && ob==1)
					b = st[i] ;
				else if(oa==1 && ob==1)
					if(i!=k-1)
						ok=0;
					else if( dep[st[i]] < dep[findfa(a,b)])
						ok=0;					
			}
			puts(ok ? "Yes" : "No");
		}
	};

	return 0;
};
/*






*/
