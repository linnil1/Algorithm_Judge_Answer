#include<cstdio>
#include<cstring>
#define lld long long int
lld c[17][17];int len;
int chan(char n)
{
	if(n>='0' && n<='9')
		return n-'1';
	else
		return n-'A'+9;
};
void tozero(char *ch )
{
	memset(c,0,sizeof(c));
	
	for(int i=0;ch[i];++i)
		if(ch[i]!='?')
		{
			int num=chan(ch[i]);
			for(int x=-1;x<=1;++x)
				for(int y=-1;y<=1;++y)
				{
					int tx=i+x,
						ty=num+y;
					if(tx>=0 && tx<len && ty >=0 && ty < len)
						c[tx][ty]=-1;
				}
		}
};
lld sum(int a)
{
	lld allsum=0;
	for(int i=0;i<len;++i)
		if(c[a][i]!=-1)
			allsum+=c[a][i];
	return allsum;
};
int count(int a)
{
	for(int i=0;i<len;++i)
		if(c[a][i]!=-1)
		{
			lld allsum=0;
			for(int j=0;j<len;++j)
				if(c[a-1][j]!=-1 && (j<i-1 || j>i+1))
					allsum += c[a-1][j];
			c[a][i]=allsum;
		};
};		
int newone(int a)
{
	for(int i=0;i<len;++i)
		if(c[a][i]!=-1)
			c[a][i]=1;
};
bool invalid(char *ch)
{
	for(int i=0;i<len;++i)
		if(ch[i]!='?' && chan(ch[i]) >= len)
			return 1;
	for(int i=1;i<len;++i)
		if(ch[i]!='?'&& ch[i-1]!='?')
		{
			int t1=chan(ch[i-1]),
				t2=chan(ch[i]);
			if((t1-t2>0?t1-t2:t2-t1)<=1)
				return 1;
		};
	return 0;
	
};
int main()
{
	char ch[100];
	
	while(~scanf("%s",ch))
	{
		len=strlen(ch);
		if(invalid(ch))
			{puts("0");continue;}
		
		tozero(ch);
		
		lld allsum=1;
		int two=0;
		for(int i=0;i<len;++i)
			if(ch[i]!='?') 
				if(two)
					allsum*=sum(i-1),two=0;
				else;
			else if(two==0)
				newone(i),two=1;
			else 
				count(i);
		if(two)
			allsum*=sum(len-1);
			
			
		printf("%lld\n",allsum);
	};
	return 0;
	
};
