
#define M 10010

struct package
{
	int pack[M],n;
	void init(int _n)
	{
		n = _n;
		for(int i=0;i<=n;++i)
			pack[i]=0;
	}
	void zero(int cost,int val)
	{
		for(int i=n-cost;i>=0;--i)
			if(pack[i+cost] < pack[i]+val )
				pack[i+cost] = pack[i]+val;
	}
	void mult(int cost,int val)
	{
		for(int i=cost;i<=n;++i)
			if(pack[i] < pack[i-cost]+val)
				pack[i] = pack[i-cost]+val;
	}
	void lim(int cost,int val,int t)
	{
		int now=1;
		while(t>=now)
		{
			zero(cost*now,val*now);
			t-=now;
			now<<=1;
		}
		if(t)
			zero(cost*t,val*t);
	}
	int out()
	{
		return pack[n];
	}
	
}pack;
