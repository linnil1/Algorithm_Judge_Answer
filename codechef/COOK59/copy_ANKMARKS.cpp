#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
// template end here
int a[1000],b[1000];
int dp[5000],tt;
int main(){
    CASET{
        vector<LL>d;
        tt++;
        DRI(N);
        REP(i,N)RI(a[i]);
        MS0(b);
        REPP(i,1,N){
            if(a[i]>a[i-1])b[i]=max(b[i-1]+1,b[i]);
        }
        for(int i=N-2;i>=0;i--){
            if(a[i]>a[i+1])b[i]=max(b[i+1]+1,b[i]);
        }
        DRI(K);
        dp[0]=tt;
        int gg=0;
        REP(i,K){
            DRI(x);
            if(!gg)gg=x;
            else gg=__gcd(gg,x);
            for(int j=0;j+x<5000;j++){
                if(dp[j]==tt)dp[j+x]=tt;
            }
        }
        d.PB(0);
        while(d.back()<(1LL<<61)){
            LL lt=d.back();
            LL now=lt*2+gg;
            while(now<5000&&dp[now]!=tt)now++;
            d.PB(now);
        }
        LL an=0;
        REP(i,N)an+=d[b[i]];
        printf("%.9f\n",an*1./N);
    }
    return 0;
}
