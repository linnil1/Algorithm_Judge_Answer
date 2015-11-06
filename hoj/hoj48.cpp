#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string

int r[1010][1010],
	o[1010][1010];

int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int a,b,day;
	while(~scanf("%d%d%d",&a,&b,&day))
	#endif	
	{
		for(int i=0;i<a;++i)
			for(int j=0;j<b;++j)
				scanf("%d",&o[i][j]),
				r[i][j]=0;
		r[0][0]=day-1;
		for(int i=0;i<a;++i)
			for(int j=0;j<b;++j)
			{
				r[i+1][j]+=r[i][j]/2;
				r[i][j+1]+=r[i][j]/2;
				
				if(r[i][j]%2==1)
				{
					if(o[i][j]==0)
						++r[i+1][j];
					else
						++r[i][j+1];	
					o[i][j] = !o[i][j];
				}
			}
		int x=0,y=0;
		while(x<a && y<b)
		{
			if(o[x][y]==0)
				++x;
			else
				++y;
		}
		printf("%d %d\n",x+1,y+1);
					
	};
	return 0;
};
/*
*/
