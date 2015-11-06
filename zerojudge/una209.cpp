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
	int n,m;
	while(cin >> m >> n)
	{
		int ch[n][m];
		FR(i,n)
			FR(j,m)
				cin >> ch[i][j];
		int squ[n][m];
		FR(i,n)
			if(ch[i][0])
				squ[i][0]=1;
			else
				squ[i][0]=0;
		FR(j,m)
			if(ch[0][j])
				squ[0][j]=1;
			else
				squ[0][j]=0;
		FOR(i,1,n)
			FOR(j,1,m)
				if(!ch[i][j])
					squ[i][j]=0;
				else
				{
					squ[i][j] = 1+ min (squ[i-1][j] ,
								min(squ[i-1][j-1] , squ[i][j-1]));
										
				}	
		/*	*/
		int x=n-1,y=m-1,sum=0;
		while(y>=0)
		{
			
			int now = squ[x][y],okx=0,oky=0;
			FR(i,now)
			{
				if(ch[x][y-i])
					oky=1;
				if(ch[x-i][y] )
					okx=1;
			};
			if(!okx)
			{
				okx=1;
				FOR(i,1,now)
					if( squ[x][y] <= squ[x][y-i] )
						okx=0;
			}
			if(okx && oky)
			{
				/*for(int i=0;i<n;++i,puts(""))
					FR(j,m)
						cout << ch[i][j] ;
				cout << endl;*/
				
				FR(i,now)
					FR(j,now)
						ch[x-i][y-j]=0;
				++sum;
				//cout << x << y << endl;
			}
			--x;
			if(x<0)
				--y,x+=n;			
		}
		cout << sum << endl;
		
	};
}
	return 0;
};
/*
*/
