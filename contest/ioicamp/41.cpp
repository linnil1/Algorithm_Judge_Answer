#include<bits/stdc++.h>
#define lld long long int

#define M 3
#define MOD 1000000007
struct mat
{
	lld m[M][M];
	int r,c;
	
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
					c.m[i][j] = ( c.m[i][j] + a.m[i][k]*b.m[k][j]%MOD ) %MOD;
		return c;
	}
	
};
inline mat pow(mat b,int time)
{
	if(b.c != b.r)
		puts("error");
	
	mat now(b.c,b.r);	
		
	for(int i=0;i<b.r;++i)
		now.m[i][i] = 1 ;
	
	while(time)
	{
		if(time&1)
			now = now * b ;
		b = b*b;
		time>>=1;
	}
	return now;	
}

mat init()
{
	mat c(M,1);
	c.m[0][0] = 4;
	c.m[1][0] = 15;
	c.m[2][0] = 56;
	return c;
}
mat gobase()
{
	mat c(M,M);
	c.m[0][1] = c.m[1][2] = 1;
	c.m[2][1] = -1;
	c.m[2][2] = 4;
	return c;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		
		mat t = pow(gobase(),n-2)  * init() ;
		
			
		printf("%lld\n",(t.m[0][0]+MOD)%MOD);
	};
	return 0;
};
/*
*/
