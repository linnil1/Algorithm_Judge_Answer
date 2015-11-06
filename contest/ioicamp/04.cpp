#include<cstdio>
#include<algorithm>
//#include<ctype.h>
//#include<cmath>
#include<set>
#define lld long long int

lld mult(lld a,lld b,lld c)
{
	lld base=1;
	while(b)
	{
		if(b&1)
			base=base*a%c;
		b>>=1;
		a=a*a%c;
	}
	return base%c;
};

int main()
{
	int count;
	while(~scanf("%d",&count))
	while(count--){
		lld a,b,c;
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		//scanf("%lld%lld%lld",&a,&b,&c);
		printf("%I64d\n",mult(a,b,c));
	};
	return 0;
};
