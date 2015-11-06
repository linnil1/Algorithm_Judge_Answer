#include<bits/stdc++.h>
#define ll long long int

#define M 10000
int a,b;
int ma[200],
	mb[200];
	
struct disjointset
{
	int s[M],n,group;
	void init(int _n)
	{
		group = n = _n ;
		for(int i=0;i<=n;++i)
			s[i] = i ;
	};
	
	int find(int a)
	{
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b)
	{
		if(find(a)!=find(b))
		{
			s[find(a)] = find(b);
			--group;
			return 1;
		}
		else
			return 0;
	}	
	
}s;

int play()
{
	s.init(a+b);
	
	for(int i=0;i<a*b;++i)
		s.unin(i%a , a+i%b);	
		
	std::vector<int> v[210];
	
	for(int i=0;i<a;++i)
		v[s.find(i)].push_back(ma[i]);
	for(int i=0;i<b;++i)
		v[s.find(a+i)].push_back(mb[i]);
	
	
	for(int i=0;i<200;++i)
	{
		if(!v[i].size())
			continue;
		int ok=0;
		for(int j=0;j<v[i].size();++j)
			if(v[i][j])
				ok=1;
		if(!ok)
			return 0;
	}
	return 1;
	
}

int main()
{
	/*int T;
	scanf("%d",&T);
	while(T--)*/
	
	while(~scanf("%d%d",&a,&b))
	{
		//init
		
	
		for(int i=0;i<a;++i)
			ma[i] = 0;
		for(int i=0;i<b;++i)
			mb[i] = 0;
		
		//tohappy
		int n;
		scanf("%d",&n);
		while(n--)
		{
			int t;
			scanf("%d",&t);
			ma[t] = 1;
		}
		scanf("%d",&n);
		while(n--)
		{
			int t;
			scanf("%d",&t);
			mb[t] = 1;
		}
		
			
		printf("%s\n",play()?"Yes":"No");
	};
	return 0;
};
/*
*/
