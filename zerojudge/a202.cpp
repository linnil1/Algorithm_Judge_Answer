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
	int r,c;
	while(~scanf("%d%d",&r,&c))
	{
		char ch[30][30];
		FR(i,c)
			scanf("%s",ch[i]);
		int ok=1;
		FR(j,r)
			FR(i,c-1)
				if(ch[i][j]=='O' && ch[i+1][j]=='O')
					ok=0;
		if(!ok)
		{
			puts("ERROR\n");
			continue;
		}

		ARR(arr,c+1)
			arr[i]=i;
		FR(j,r)
			FR(i,c)
				if(ch[i][j]=='O')
				{
					swap(arr[i],arr[i+1]);
				}
		FR(i,c+1)
		{
			putchar('A'+i);
			FR(j,r)
				putchar('-');
			putchar('A'+arr[i]);puts("");putchar(' ');

			
			if(i==c)
				break;				
	
			FR(j,r)
				putchar(ch[i][j]=='O'?'|':' ');
			puts("");		
		}
					
		puts("");
			
	};
}
	return 0;
};
/*
10min ok qucik!!
*/
