#include<cstdio>
#include<set>
#include<cstring>
#define lld long long int
struct mat
{
	lld f[2][2];
	mat(){memset(f,0,sizeof(f));}
};
#define P 1000000000
mat operator *(mat a,mat b)
{
	mat c;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[k][j]%P)%P;
	return c;
};
int con[200],cons=0;
int input(char *ch)
{
	int len=strlen(ch);
	for(int i=0;i<len;++i)
		ch[i]-='0';
		
	for(int i=0,m=len/2;i<m;++i)
	{
		char t=ch[i];ch[i]=ch[len-1-i];ch[len-1-i]=t;
	};
	
	cons=0;
	for(;len && !ch[len-1];--len);
	while(len)
	{
		con[cons++]=ch[0]%2;
		for(int i=len-1;i>=0;--i)
		{
			if(ch[i]%2 && i)
				ch[i-1]+=10;
			ch[i]/=2;
		};			
		for(;len && !ch[len-1];--len);	
	};
	return cons;
};
lld mult()
{
	mat a,b;
	b.f[0][0]=0;
	b.f[0][1]=b.f[1][1]=b.f[1][0]=1;
	
	a.f[0][0]=a.f[1][1]=1;
	a.f[0][1]=a.f[1][0]=0;
	for(int i=0;i<cons;++i,b=b*b)
		if(con[i])
			a=a*b;
	return a.f[0][1];
	//printf("%I64d\n",(a.f[0][0]+a.f[0][1])%P);
	
		
};
int main()
{
	int a=0,b=1,c,k,time;
	char ch[105];
	while(~scanf("%d",&time))
		while(time--)
	{
		scanf("%s",ch);
		input(ch);
		/*for(int i=cons-1;i>=0;--i)
			printf("%d",con[i]);*/
			
			
		printf("%09lld\n",mult());
	};
	return 0;
};
