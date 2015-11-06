#include<bits/stdc++.h>
#define M 1000000007
#define lld long long int
#define gom(a) ((a)%M+M)%M
struct mat
{
	lld m[2][2],r,c;
	mat(lld a=0,lld b=0,lld q=0,lld w=0 )
	{
		r=c=2;
		m[0][0]=a;m[0][1]=b;
		m[1][0]=q;m[1][1]=w;
	}
	friend mat operator * (mat a,mat b)
	{
		mat c;
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k)
					c.m[i][j] =  gom(c.m[i][j] + gom( a.m[i][k] * b.m[k][j] ) );
		return c;			
	};
};

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y,n;
		scanf("%d%d%d",&x,&y,&n);
		
		mat mult(0,1,1,1) , base(1,0,0,1);  
		while(n)
		{
			if(n&1)
				base = base * mult ;
			mult = mult * mult	;
			n>>=1;					
		};
		
		mat ans( x, 0, y, 0) ;
		ans =  base * ans;
		printf("%I64d\n" , ans.m[0][0] );
		
	};
	return 0;
};
