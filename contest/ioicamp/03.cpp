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
		int a;
		scanf("%d",&a);
		if(a<=1000)
			printf("%d 0\n",a);
		else
			printf("%d 1000\n",a-1000);
	};
	return 0;
};
