#include<bits/stdc++.h>
#define ll long long int

#define M 10000
int pr[10]={2,3,5,7,11,13},prs=6;

int isprime(int a)
{
	for(int i=0;i<prs;++i)
		if(a%pr[i]==0)
			return pr[i];
	
	puts("error");
}
int main()
{
	/*int T;
	scanf("%d",&T);
	while(T--)*/
	int n;
	while(~scanf("%d",&n))
	{
		char c[20];
		scanf("%s",c);
	
		int m[20];
		for(int i=2;i<=15;++i)
			m[i] = 0 ;
		
		for(int i=0;i<n;++i)
			for(int j=2;j<=c[i]-'0';++j)
				++ m[j] ;
				
		//prime		
			
		std::queue<int> s ;
		for(int i=15;i>=2;--i)
		{
			if(m[i]==0)
				continue;
			int t=i;
			if(isprime(t)!=i)
				while(t!=1)
				{
					int e = isprime(t);
					m[e] += m[i] ;
					t/=e;
					//puts("zc");
				}
			else
			{
				for(int j=2;j<i;++j)
					m[j]-=m[i];
					
				while(m[i]--)
					s.push(i);	
				//puts("er");
			}
		}	
		while(s.size())
		{
			printf("%d",s.front());
			s.pop();
		}
		puts("");
	};
	return 0;
};
/*
*/
