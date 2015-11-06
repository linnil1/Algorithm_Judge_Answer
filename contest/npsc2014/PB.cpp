#include<cstdio>
int inv(int b,int p)
{
	//printf("%d %d\n",b,p);
	return b==1 ? 1 : inv(p%b,p)*(p-p/b)%p;
};
int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;
		a=b;b=t;
	};
	return a;
};
int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
};
int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
		printf("%d\n",inv(b%a,a));
	while(~scanf("%d",&a))
	{
		//printf("%d\n",lcm(a,b));
		int m[a],r[a];
		for(int i=0;i<a;++i)
			scanf("%d%d",&m[i],&r[i]);
		for(int i=a-2;i>=0;--i)
		{			
			printf("%d\n",inv(m[i+1],m[i]));
			r[i]=inv(m[i+1]%m[i],m[i])*m[i+1]*r[i]+inv(m[i]%m[i+1],m[i+1])*m[i]*r[i+1];
			m[i]=lcm(m[i],m[i+1]);
		};
		printf("%d\n",r[0]);
			
	};
	return 0;
};
/*
2
3 2
5 3

*/
