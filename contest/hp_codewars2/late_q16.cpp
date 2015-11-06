#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string


int todig(char *c)
{
	int sum=0;
	for(int i=0;c[i];++i)
		sum=sum*2 + c[i]-'0';
	return sum;
}

struct garyma
{
	int f,b;
}arr[12][5000];


void makegary()
{
	int use[5000];
	char c[15];
	
	for(int n=3;n<=10;++n)
	{	
		for(int i=1;i<(1<<n);++i)
			use[i]=1;
		for(int i=0;i<n;++i)
			c[i]='0';
		c[n]='\0';
		
		int f=0,b;
		int ok=1;
		while(ok)
		{
			//printf("%s\n",c);
			ok=0;
			for(int j=n-1;j>=0;--j)
			{
				c[j]= (!(c[j]-'0'))+'0';
				int num = todig(c);
				if(use[num])
				{
					use[num]=0;
					ok=1;
					
					arr[n][f].b = num ;
					arr[n][num].f = f ;
					f = num ;
										
					break;
				}
				c[j]= (!(c[j]-'0'))+'0';

			}
		}
	};
};

void tochar(int n,int a)
{
	char c[100];
	c[n]='\0';
	for(int i=n-1;i>=0;--i,a/=2)
		c[i] = a%2 + '0';
	printf("%s ",c);
}

int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	char c[1000];
	makegary();
	while(~scanf("%s",c))
	#endif	
	{		
		int len = strlen(c),
			num = todig(c);
			
		tochar(len,arr[len][num].f);
		tochar(len,num);
		tochar(len,arr[len][num].b);
		puts("");
		
		
	};
	return 0;
};
/*
*/
