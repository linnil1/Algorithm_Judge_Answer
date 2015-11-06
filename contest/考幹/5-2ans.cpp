#include<stdio.h>
#include<string.h>
#define M 200 
int main()
{
	int i,j,k;
	char c[M],d[M]; 
	while(~scanf("%s%s",c,d))
	{
		int sum=0; 
		for(i=0,k=0;c[i];++sum)
		{ 
			for(int j=0;d[j]&&c[i];++j)
				if(c[i]==d[j])
					++i,++k;
			if(!k)
				break;
			else
				k=0; 
		}; 
		if(!c[i]) 
			printf("%d\n",sum);
		else
			puts("impossible"); 
	};
	return 0;
};
