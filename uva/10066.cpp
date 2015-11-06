#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<ctime>
#define lld long long int
int na[110],nb[110];
int dp(int a,int b)
{
	int d[110][110];
	for(int i=0;i<=a;++i)
		d[i][0]=0;
	for(int i=0;i<=b;++i)
		d[0][i]=0;
	for(int i=1;i<=a;++i)
		for(int j=1;j<=b;++j)
			d[i][j]=std::max(std::max(d[i-1][j],d[i][j-1]),d[i-1][j-1]+(na[i]==nb[j]));
	return d[a][b];
};
int main()
{
	int time=1,i=0,a,b;
	//freopen("textin.txt","r",stdin);
	//freopen("textout.txt","w",stdout);
	while(
		//--time || ~scanf("%d",&time) 
		~scanf("%d%d",&a,&b)
		 )
	{
		if(a==0 && b==0)
			break;
		for(int i=1;i<=a;++i)
			scanf("%d",na+i);
		for(int i=1;i<=b;++i)
			scanf("%d",nb+i);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",time++,dp(a,b));
	};
	return 0;
};
/*
*/
