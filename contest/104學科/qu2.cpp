#include<cstdio>
#include<algorithm>


int main()
{
	long long int a;
	while(~scanf("%I64d",&a))
	{
		if(a==0)
			break;
		long long int sum=a;
		while(sum>9)
		{
			a=sum;
			sum=0;
			while(a)
			{
				sum+=a%10;
				a/=10;
				
			};
		}
		printf("%I64d\n",sum);
	};
	return 0;
};
