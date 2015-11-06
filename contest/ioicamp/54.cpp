#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 200100

#define hm 263167
#define MOD 1000000007

lld  ha[M],hb[M],hh[M];
char ca[M],cb[M];
int   lena, lenb;

void init(char *c,lld *h,int &len)
{
	h[0]=rand();
	for(len=0;c[len];++len)
		h[len+1] = (h[len]*hm + c[len] )%MOD;
}

#define m(a) ((a)%MOD+MOD)%MOD
int fail(int low,int i)
{
	int l=low,r=lenb+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if( m(hb[  mid]-hb[  low]*hh[mid-low]) == 
		    m(ha[i+mid]-ha[i+low]*hh[mid-low]) )
			l=mid;
		else
			r=mid;
	}
	return r;
}

bool find(int i,int k )
{
	int now=fail(0,i);
		
	while(k && now<=lenb)
	{
		--k;
		//printf("%d?",now);
		now = fail(now,i);
		
	}
	//printf("%d!!\n",now);
	
	if(now == lenb+1)
		return 1;
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	hh[0]=1;
	for(int i=1;i<=M;++i)
		hh[i] = hh[i-1] * hm % MOD;
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int k;
		scanf("%d%s%s",&k,ca,cb);
		
		init(ca,ha,lena);	
		init(cb,hb,lenb);
		
		std::vector<int> v;
		for(int i=0;i<=lena-lenb;++i)
			if(find(i,k))
				v.push_back(i);
				
		printf("%d",v.size());
		for(int i:v)
			printf(" %d",i);
		puts("");
	};
	return 0;
};
/*
*/
