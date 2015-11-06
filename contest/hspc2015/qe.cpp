#include<bits/stdc++.h>
#define ll long long int
#define M 100100

struct {
	int s[M],n,group;
	void init(int _n){
		n =  group = _n;
		for(int i=0;i<=n;++i)
			s[i] = i ;
	}
	inline int find(int a){
		return s[a]==a ? a : (s[a]=find(s[a]));
	}
	int unin(int a,int b){
		if(find(a) == find(b))
			return 0;
		s[find(a)] = find(b);
		--group;
		
	}
	
	
}disj;

int main()
{
	int times;scanf("%d",&times);while(times--)
{
	int n,can,m;
	(~scanf("%d%d%d",&n,&can,&m));{
		disj.init(n);
		while(m--){
			int x,y,val;
			scanf("%d%d%d",&x,&y,&val);
			if(val <= can){
				disj.unin(x,y);
			}
		}
		printf("%s\n",disj.group==1 ? "Yes" : "No");		
	}
}
	return 0;
}


/*

7 5 8
1 2 5
1 3 2
2 4 7
4 5 1
5 3 3
6 7 5
2 3 6
5 2 8
7 5 8
1 2 5
1 3 2
2 4 7
4 5 1
5 3 3
6 7 5
2 3 6
5 6 4
 


*/
