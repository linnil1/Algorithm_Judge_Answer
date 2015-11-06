#include<cstdio>
#include<algorithm>


int main()
{
	int a,minus;
	while(~scanf("%d",&a))
	{
		int sum=a;
		minus=0;
		while(a>=3 )
		{			
			sum+=a/3;
			a=a/3+a%3;
			if(minus)
			{
				--a;
				minus=0;
			};
			if(a%3==2)
			{
				a+=1;
				minus=1;
			};
		};
		printf("%d\n",sum);
	};
	return 0;
};
