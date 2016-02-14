char need_time=0;
#define M 100010
#define MOD 1000000007
#include<bits/stdc++.h>
#define ll long long 
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_pair
#define ft first
#define sd second
#define pb push_back
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MINN(a,b,c) MIN(MIN(a,b),c)

#define QI std::queue<int>
#define VI std::vector<int>
#define VMP std::vector<MP>
#define MP std::pair<int,int>
#define IN(a) scanf("%d",&a)
#define INN(a,b) scanf("%d%d",&a,&b)

//using namespace std;

char c[M];
int len;
int link[M];

int e[M];
void back()
{
	int tmp[4];
	FR(i,4)tmp[i]=len;

	int eo=len;
	BFR(i,len)
	{
		switch(c[i]){
			case 'e':link[i] = tmp[1];eo=i;break;
			case 'a':tmp[1] = link[i] = tmp[2];break;
			case 's':tmp[2] = link[i] = tmp[3];break;
			case 'y':tmp[3] = link[i] = i ;break;
		}
		e[i] = eo; 
	}
	link[len] = len;
}

int sum[M];
void gosum(){
	sum[0]=0;
	int i=0;
	while(i<len)
	{
		int k = e[i] ,now = sum[i];

		FOR(j,i+1,link[k])
			sum[j] = now;
		i = link[k];
//		if(i<len)
			sum[i] = now+1;
	}
//	sum[len] = sum[len-1];
}

int main(){
//	std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);

	int n;
	while(~scanf("%s%d",c,&n)){
		len=strlen(c);
		
		back();
		gosum();
//		FR(i,len)
//			printf("%d ",sum[i]);
//		puts("");

		FR(i,n)
		{
			int a,b;
			INN(a,b);
			--a;--b;
			if( link[e[a]] > b)
				puts("0");
			else
				printf("%d\n",sum[b] - sum[ link[e[a]] ]+1 );
		}

		if(need_time && ++go_t==time)break;
	};
	return 0;
};
/*






*/
