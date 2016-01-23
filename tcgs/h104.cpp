char need_time=1;
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
//#include<utility>
#include<limits.h>
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
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MINN(a,b,c) MIN(MIN(a,b),c)

#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define VMP std::vector<MP>
#define MP std::pair<int,int>
#define IN(a) scanf("%d",&a)
#define INN(a,b) scanf("%d%d",&a,&b)

//using namespace std;

#define matM 51 
struct mat
{
	double m[matM][matM];
	int r,c;
/*r=2 c=3
xxx
xxx*/
	mat(){};
	mat(int _r,int _c):r(_r),c(_c){memset(m,0,sizeof(m));};

	friend mat operator * (mat a,mat b)
	{
		if(a.c != b.r)
			puts("error");
		mat c(a.r,b.c);
		for(int i=0;i<c.r;++i)
			for(int j=0;j<c.c;++j)
				for(int k=0;k<a.c;++k)
					c.m[i][j] = c.m[i][j] + a.m[i][k]*b.m[k][j];
		return c;
	}

	mat pow(int time){
		if(c != r)
			puts("error:pow");
		
		mat now(c,c),b = *this;	
		for(int i=0;i<c;++i)
			now.m[i][i] = 1 ;
		
		while(time){
			if(time&1)
				now = now * b ;
			b = b*b ;
			time>>=1;
		}
		return now;	
	}	
	
};

struct fastmat
{	
	int n;
	mat init(){
		mat c(n,1);
		c.m[0][0] = 100;//f0
		return c;
	}
	
	mat gobase(){
		mat c(n,n);
		FR(i,n-1)
			c.m[i][i+1]=1;
		FR(i,n)
			c.m[i][0]=1./n;

		return c;
	}

	double want(int _n,int t,int m){
		n = _n;
		mat k = (gobase()).pow(t)  * init();  //f0 = f1 = 1 , fn=fn-1 + fn-2
		if(m<t )
			return 100;
		double sum=0;
		FOR(i,m-t,n)
			sum += k.m[i][0];
		return sum;// 0th = f0
	}

}fm;

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	int time,go_t=0;if(need_time)scanf("%d",&time);

	int n,m,s;
	while(~scanf("%d%d%d",&n,&m,&s)){
		printf("%.1lf%%\n",fm.want(m,n,s));
		
		if(need_time && ++go_t==time)break;
	};
	return 0;
};
/*






*/
