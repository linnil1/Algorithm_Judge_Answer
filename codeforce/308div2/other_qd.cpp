// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(), (x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
#define IO() {ios_base::sync_with_stdio(0); cin.tie(0);}
#define nl '\n'
#define cint1(a) int a; cin>>a
#define cint2(a,b) int a,b; cin>>a>>b
#define cint3(a,b,c) int a,b,c; cin>>a>>b>>c
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<class A, class B> inline bool mina(A &x, B y) {return(x>y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return(x<y)?(x=y,1):0;}
template<class A, class B> inline A geta(A &x, const B y) {A t=x;x=y;return t;}

#define MAXN (2004)

int N;
int X[MAXN];
int Y[MAXN];

PII P[MAXN];

int main()
{
	IO();
	cin >> N;
	FOR(i,0,N) cin >> X[i] >> Y[i];

	LL res = 0;
	FOR(i,0,N)
	{
		int n = 0;
		FOR(j,0,N) if(j != i)
		{
			int x = X[j] - X[i];
			int y = Y[j] - Y[i];
			int g = __gcd(abs(x),abs(y));
			x /= g;
			y /= g;
			if(y < 0 || (y == 0 && x < 0))
			{
				x = -x;
				y = -y;
			}
			P[n++] = PII(x,y);
		}
		sort(P, P+n);
		for(int j = 0; j < n; )
		{
			int k = j;
			while(k < n && P[j] == P[k]) ++k;
			int m = k - j;
			res += m * (m-1) / 2;
			j = k;
		}
	}

//	cout << res << endl;
//	cout << LL(N) * (N-1) * (N-2) / 6 << endl;
	cout << LL(N) * (N-1) * (N-2) / 6 - res/3 << endl;

	return 0;
}
