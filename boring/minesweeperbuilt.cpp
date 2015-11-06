#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 100
#define MOD 1000000007
#define mp std::make_pair
#define pii std::pair<int,int>
#define pb push_back
#define qi std::queue<int>


char map[M][M];
int a,b;
void minesweeper()
{
	for(int i=0;i<a;++i)
		for(int j=0;j<b;++j)
			if(map[i][j]=='.')
				map[i][j] = '0';
	for(int i=0;i<a;++i)
		for(int j=0;j<b;++j)
			if(map[i][j]=='*')
				for(int q=-1;q<=1;++q)
					if(q+i >=0 && q+i<a)
						for(int w=-1;w<=1;++w)
							if(j+w>=0 && j+w<b && (q || w) && map[q+i][w+j]!='*')
								++map[q+i][w+j];
	
}


int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;++i)
			scanf("%s",map[i]);
				
		minesweeper();		
				
		for(int i=0;i<a;++i,puts(""))
			for(int j=0;j<b;++j)
				printf("%c",map[i][j]);
					
	};
	return 0;
};
/*
1
5 5
..**.
.*..*
....*
.....
....*


*/
