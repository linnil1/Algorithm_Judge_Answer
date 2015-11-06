#include<bits/stdc++.h>
#define lld long long int
struct man
{
	int fa,l;
	lld sum;
	std::multiset<int> *s;
};

man ma[100100];
int money ;
void merge(int f,int i)
{
	if(ma[f].s->size() > ma[i].s->size())
		for(auto j : (*ma[i].s))
			ma[f].s->insert(j);
	else
	{
		for(auto j : *ma[f].s)
			ma[i].s->insert(j);
		ma[f].s = ma[i].s;	
	}
	
	ma[f].sum += ma[i].sum ;
	
};
lld solve(int n)
{
	lld max = 0 ;
	for(int i=n;i>=1;--i)
	{
		while( ma[i].s->size() && ma[i].sum > money )
		{
			ma[i].sum -= *( ma[i].s -> rbegin() );
			ma[i].s -> erase ( ma[i].s->find(* ma[i].s -> rbegin()) );
		};

		//printf("%d %d %d\n",i , num , ma[i].l);

		max = std::max( max , (lld)ma[i].s->size() * ma[i].l );

		if(ma[i].fa >=1)
		{
			
			merge(ma[i].fa , i);
			//delete ma[i].s;
		}
	};
	return max;

};

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int n,p;
		scanf("%d%d",&n,&money);

		for(int i=1;i<=n;++i)
		{
			ma[i].s = new std::multiset<int>() ;
			scanf("%d%d%d",&ma[i].fa, &p ,&ma[i].l );
			ma[i].s->insert(p);
			ma[i].sum = p ;
			//ma[i].t = merge ( ma[i].t , new treap(p) ) ;
		};

		printf("%lld\n",solve(n));


	}
    return 0;
}

