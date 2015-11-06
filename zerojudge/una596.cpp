#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;

int ok,minu;
void dfs(int now,int n,int*c,int *use,int len)
{
	if(now==n)
	{
		++ok;
		if(len<=2)
			++minu;
		FR(i,len)
			PR(use[i])
		return ;
	}
	dfs(now+1,n,c,use,len);
	
	use[len]=c[now];
	if(len ==0)
		dfs(now+1,n,c,use,len+1);
	else if(c[now]==use[len-1])
		return ;	
	else if(len==1)
		dfs(now+1,n,c,use,len+1);
	else if( ((use[len-1]-use[len-2]>0)^(use[len]-use[len-1]>0))>0 )
		dfs(now+1,n,c,use,len+1);

}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		ok=0;
		ARR(c,n)
			cin >> c[i];
		/*int use[n];
		dfs(0,n,c,use,0);
		cout << ok << -minu << "sdf\n";*/
		
		int dp[2][n];
		FR(i,n)
			dp[0][i]=dp[1][i]=1;
		FR(i,n)
			BFR(j,i)
			{
				if(c[i]>c[j])
					dp[1][i]+=dp[0][j];
				else if(c[i]<c[j])
					dp[0][i]+=dp[1][j];
			}
		
		int sum=0;
		FR(i,n)
			sum+=dp[0][i]+dp[1][i];
		sum-=n*2;
		FR(i,n)
			FOR(j,i+1,n)
				sum -= (c[i]!=c[j]);
		cout << sum << endl ;
	};
}
	return 0;
};
/*
78min undone slow
*/
