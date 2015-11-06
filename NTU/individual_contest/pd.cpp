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
int man[M];
ll val[M];
VMP v[M];

int st[M];int io[M];

void topo(int n){
	int stn=0;
    QI q;
    FRE(i,n)
        if(io[i]==1)
            q.push( i),
            --io[i];
    while(q.size()){
        int now=q.front();q.pop();
        st[stn++]=now;
        for(MP &i: v[now])
            if(--io[i.ft]==1)
                q.push(i.ft);       
    }
    /*for(int i:st)
        printf("%d ",i);
    puts("zxc");*/
}

void bfs(int n){
    FRE(i,n)
        io[i]=1;
    for(int k=0;k<n;++k){
    	int &i = st[k];
        io[i]=0;
        for(MP &j :v[i])
            if(io[j.ft]){
                man[j.ft]+=man[i];
                val[j.ft]+=(ll)man[i] * j.sd + val[i];
            }
    }
    /*FRE(i,n)
        printf("%d ",val[i]);
    puts("zxc");*/
    FRE(i,n)
        io[i]=1;
    BFR(k,n){
        int &i = st[k];
        io[i]=0;
        for(MP &j :v[i])
            if(io[j.ft]){
                val[j.ft] =val[i] + (ll)(n-2*man[j.ft])*j.sd;   
                //printf("%d %d!!\n",(n-2*man[j.ft]),j.sd);         
            }
    }
    
}


int main(){
    //std::ios::sync_with_stdio(false);std::cin.tie(0); 

    //freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{   
    int n;
    (~scanf("%d",&n));{
        FRE(i,n){       
            man[i]=1;
            val[i]=0;
            v[i] = VMP();
            io[i]=0;
        }
        FOR(i,1,n){
            int x,y,val;
            scanf("%d%d%d",&x,&y,&val);
            ++io[x];++io[y];
            v[x].pb( mp(y,val) );
            v[y].pb( mp(x,val) );
        }
        
        topo(n);
        bfs(n);
        FRE(i,n)
            printf("%lld ",val[i]);
        puts("");
        
    };
}
    return 0;
};
/*






*/
