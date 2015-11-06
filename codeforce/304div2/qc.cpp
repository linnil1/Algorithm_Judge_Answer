#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string


string tostr(int *a,int len)
{
	string c;
	for(int i=0;i<len;++i)
		c.push_back(a[i]+'0');
	return c;
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
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int a[15],alen,
			b[15],blen;
		scanf("%d",&alen);
		for(int i=0;i<alen;++i)
			scanf("%d",a+i);
		scanf("%d",&blen);
		for(int i=0;i<blen;++i)
			scanf("%d",b+i);
			
		
		std::set<std::pair<string,string> > s;
		int step=0;
		while(1)
		{
			std::pair<string,string> now = std::make_pair( tostr(a,alen) , tostr(b,blen) );
			
			if(s.count(now))
				{step=0;break;}			
			s.insert(now);
			
			if(alen==0 || blen==0)
				break;
			int pka = a[0],pkb = b[0];
			if(pka > pkb)
				{a[alen++]=pkb;a[alen++]=pka;};
			if(pka < pkb)
				{b[blen++]=pka;b[blen++]=pkb;};
			for(int i=1;i<alen;++i)
				a[i-1]=a[i];
			for(int i=1;i<blen;++i)
				b[i-1]=b[i];
			--alen;--blen;			
			
			++step;		
		}
		if(step==0)
			puts("-1");
		else
			printf("%d %d\n",step,alen==0?2:1);
		
	};
	return 0;
};
/*
*/
