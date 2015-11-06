#include<cstdio>
#include<algorithm>
#define M 1100
int dp[M][M],n,sum,
	val[M][M];
struct good
{
	int p,j;
}t[M],*g;
bool operator < (good a,good b)
{
	if(a.p != b.p)
		return a.p > b.p ;
	else
		return a.j < b.j ;
};
void init()
{	
	for(int i=1;i<=n;++i)
		scanf("%d%d",&t[i].p,&t[i].j);
	std::sort(t+1,t+n+1);
	sum=0;
	for(int i=1;i<=n;++i)
		sum+=t[i].p;
		
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			dp[i][j]=val[i][j]=0;			
	
	if(g == &t[1])
		--n;
};
void name()
{
	char c[100];
	scanf("%s",c);
	if(c[0]=='P')
		g=&t[1];
	else
		g=&t[0];		
};

void todp()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=(i+1)/2;++j)
		{
			
			if(dp[i-1][j] < dp[i-1][j-1] + g[i].j)
			{
				dp[i][j] = dp[i-1][j-1] + g[i].j ; 
				val[i][j] = val[i-1][j-1] + g[i].p;
			}
			else if(dp[i-1][j] == dp[i-1][j-1] + g[i].j)
			{
				dp[i][j] = dp[i-1][j] ;
				val[i][j] = std::min(val[i-1][j] , val[i-1][j-1] + g[i].p);
			}
			else
			{
				dp[i][j] = dp[i-1][j] ;
				val[i][j] = val[i-1][j] ;
			};		
				
			
		};	
		//printf("%d\n",dp[i][(i+1)/2]);
	}
		
	printf("%d %d\n",sum-val[n][(n+1)/2],dp[n][(n+1)/2]);
};

int main()
{
	int time;
	while(~scanf("%d",&time))
	while(time--){
		scanf("%d",&n);
		name();
		init();
		
		
		todp();
	};
	return 0;
};
/*
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int N = 1005;
struct state {
	int p, j;
}s[N];
int n, k, sum, dp[N][N], val[N][N];

bool cmp(const state& a, const state& b) {
	if (a.p != b.p) return a.p > b.p;
	return a.j < b.j;
}

void init () {
	char str[N];

	sum = 0;
	memset(dp, 0, sizeof(dp));
	memset(val, 0, sizeof(val));
	scanf("%d%s", &n, str);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &s[i].p, &s[i].j);
		sum += s[i].p;
	}

	if (str[0] == 'P') k = 1;
	else k = 0;
	sort(s + 1, s + n + 1, cmp);
}

void solve () {
	for (int i = 1; i <= n-k; i++) {
		for (int j = 1; j <= (i+1)/2; j++) {
			if (dp[i-1][j] > dp[i-1][j-1] + s[i+k].j) {
				dp[i][j] = dp[i-1][j];
				val[i][j] = val[i-1][j];
			} else if (dp[i-1][j] == dp[i-1][j-1] + s[i+k].j) {
				dp[i][j] = dp[i-1][j];
				val[i][j] = min(val[i-1][j], val[i-1][j-1]+s[i+k].p);
			} else {
				dp[i][j] = dp[i-1][j-1] + s[i+k].j;
				val[i][j] = val[i-1][j-1] + s[i+k].p;
			}
		}
	}
	printf("%d %d\n", sum - val[n-k][(n-k+1)/2], dp[n-k][(n-k+1)/2]);
}

int main () {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		init();
		solve();
	}
	return 0;
}

*/
