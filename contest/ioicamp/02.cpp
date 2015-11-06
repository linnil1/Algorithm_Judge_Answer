#include<cstdio>
#include<algorithm>
//#include<ctype.h>
//#include<cmath>
#include<set>
#define lld long long int

int main()
{
	int count;
	while(~scanf("%d",&count))
	while(count--){
		lld a,b;
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",a+b);
	};
	return 0;
};
