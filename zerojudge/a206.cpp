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


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;



int main()
{
	//std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n,m,t;
	while(cin >> n >> m >> t)
	{
		int arr[t][n];
		FR(i,t)
			FR(j,n)
				cin >>  arr[i][j];
		char ch[n][m+3];
		FR(i,n)
			cin >> ch[i];
		int x[n*m],y[n*m],len=-1;
		FR(j,m)
		{
			int now=-1;
			FR(i,n)
				if(ch[i][j]!='-')
				{
					if(now!=ch[i][j])
						x[++len] = i;
					else						
						y[len] = i ;
					now = ch[i][j];
				}
		}
		/*for(int i=0;i<=len;++i)
			cout << x[i] << " " << y[i] << endl;*/
		
		int ok=1;
		FR(i,t)
		{
			for(int j=0;j<=len;++j)
				if(arr[i][x[j]] > arr[i][y[j]])
					swap(arr[i][x[j]] , arr[i][y[j]]);
			
			/*FR(j,n)
				cout << arr[i][j] << " ";
			cout << endl;*/
			
			FOR(j,1,n)
				if(arr[i][j-1] > arr[i][j])
					ok=0;
			if(!ok)
				break;	
		}
		if(ok)
			cout << "This is a reliable sorting ghost leg!\n";
		else
			cout << "So sad......This is just a  ghost leg.\n";
	
		
		
	};
}
	return 0;
};
/*
23min misplace m n  causion
*/
