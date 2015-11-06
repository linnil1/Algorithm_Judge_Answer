#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 200100

#define hm 263167
#define MOD 1000000007


char ca[M],cb[M];
int   lena, lenb;
struct hasing
{
	lld  ha[M],hb[M],hh[M];
	void init()
	{
		hh[0]=1;
		for(int i=1;i<=M;++i)
			hh[i] = hh[i-1] * hm % MOD;
	}
	void toget(char *c,lld *h,int &len)
	{
		h[0]=rand();
		for(len=0;c[len];++len)
			h[len+1] = (h[len]*hm + c[len] )%MOD;
	}
	
	#define m(a) ((a)%MOD+MOD)%MOD
	bool check(int a,int b )//a<b
	{
		if( m(hb[b]-hb[a]*hh[b-a]) == 
			m(ha[b]-ha[a]*hh[b-a])    )
			return 1;
		return 0;
	}
}h;

int main()
{
	//freopen("in.txt","r",stdin);
	h.init();
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
			
		scanf("%s%s",ca,cb);		
		h.toget(ca,h.ha,lena);	
		h.toget(cb,h.hb,lenb);
		
		
	};
	return 0;
};
/*
*/
