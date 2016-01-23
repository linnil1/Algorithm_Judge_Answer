#define matM 2
struct mat
{
	ll m[matM][matM];
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
					c.m[i][j] = ( c.m[i][j] + a.m[i][k]*b.m[k][j]%MOD ) %MOD;
		return c;
	}

	mat pow(int time){
		if(c != r)
			puts("error");
		
		mat now(c,c),b = *this;	
		for(int i=0;i<c;++i)
			now.m[i][i] = 1 ;
		
		while(time){
			if(time&1)
				now = now * b ;
			b = b*b;
			time>>=1;
		}
		return now;	
	}	

};

struct fastmat
{	
	mat init(){
		mat c(matM,1);
		c.m[0][0] = 1;//f0
		c.m[1][0] = 1;//f1
		return c;
	}

	mat gobase(){
		mat c(matM,matM);
		c.m[1][1] = c.m[0][1] = c.m[1][0]= 1;
		return c;
	}
	
	ll want(int n){
		mat t = pow(gobase(),n)  * init();  //f0 = f1 = 1 , fn=fn-1 + fn-2
		return t.m[0][0];// 0th = f0
	}
	
}fm;
