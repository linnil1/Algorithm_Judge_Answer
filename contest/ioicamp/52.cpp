#include<bits/stdc++.h>
#define M 1000000
#define lld long long int 

struct tree
{
	int val,min,vis;
	std::vector<int> v;
};
tree t[1100];
int dfs(int f)
{
	if(t[f].v.size() == 0)
		return t[f].min = t[f].val ;
	for(auto i : t[f].v )
		if(t[i].vis)
		{
			t[i].vis = 0;
			t[f].min = std::min ( t[f].min , dfs(i) );
		}
		else
			t[f].min = std::min ( t[f].min , t[i].min );
			
	
	t[f].min += t[f].val ;
	
	return t[f].min ;
};
int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1,k,a;i<=n;++i)
		{
			t[i].vis = 1 ;
			t[i].min = 10001000 ;
			t[i].v = std::vector<int>();
			scanf("%d%d",&t[i].val , &k);
			while(k--)
			{
				scanf("%d",&a);
				t[i].v.push_back(a);
			};				
		};
		
		t[n]. vis = 0;
		printf("%d\n",dfs(n));
	}
    return 0;
}
