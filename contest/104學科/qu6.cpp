#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define lld long long int
int putdigit(lld a)
{
	int lon=0;
	while(a)
	{
		++lon;
		a/=10;
	};
	return lon;
};
lld putmask(int dig)
{
	lld mask=1;
	while(dig--)
		mask*=10;
	return mask;
};
int dig;
lld mult(lld a)
{
	lld sum=0,t=a;
	
	lld mask=putmask(dig);
	int time=0;
	while(t)
	{
		sum+=(t%10)*(a%putmask(dig-time)*putmask(time))%mask;
		sum%=mask;
		//printf("%I64d \n",sum);
		//printf("%I64d\n",sum);
		t/=10;
		++time;
	};
	//printf("%I64d",sum);
	return sum;
	//0081787109376
	/*lld c[1000],cc=0;
	while(a)
	{
		c[cc++]=a%10;
		a/=10;
	};
	lld l[1000],ll=0;
	for(int i=0;i<1000;++i)
		l[i]=0;
	lld more=0;
	for(int i=0;i<cc;++i)
	{
		more=0;
		for(int j=0;j<cc;++j)
		{
			if(i+j>=cc)
				break;
			l[i]=c[i]*c[i]+more;
			if(l[i]>9)
			{
				more=l[i]/10;
				l[i]%=10;
			}
		};
	};
	lld sum=0;
	for(int i=cc-1;i>=0;--i)	
		sum=sum*10+l[i];
	return sum;*/
	
};
int main()
{
	lld a;
	char c[100];
	while(~scanf("%s",c))
	{
		dig=strlen(c);a=0;
		for(int i=0;i<dig;++i)
			a=a*10+c[i]-'0';
		//printf("%s %I64d %d",c,a,dig);
		if(a==1 ||a==0)
		{
			printf("Not an automorphic number.\n");
			continue;
		};			
			
		lld b=mult(a);
		if(b==a)
			printf("Automorphic number of %d-digit.\n",dig);
		else
			printf("Not an automorphic number.\n");
		
	};
	return 0;
};
