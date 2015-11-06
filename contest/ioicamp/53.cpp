#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#define M 200100
#define lld long long int 
char a[M],
	 b[M];
	 
lld ha[M],
	hb[M];

int lena,lenb;
#define hn 21013
#define hm 10000000007
void gohash( lld *h,char *c)
{
	h[0] = rand();
	for(int i=0 ; c[i] ; ++i)
		h[i+1] = ( h[i] * hn + c[i] ) % hm ;
}

int find(int i)
{
	int l = 0 , r = lenb+1 , mid;
	while(l+1 < r)
	{
		mid = (l+r)/2;
		
		if( (hb[mid]-hb[0]) % hm  ==  (ha[mid+i]-ha[i] ) % hm )
			l = mid ;
		else
			r = mid ;
	}
	return r ;
	
}
	
int main(){
	srand(time(NULL));
    int T;
    scanf("%d",&T);
    while(T--)
	{
		int k;
		scanf("%d%s%s",&k,a,b);
		
		lena = strlen(a);
		lenb = strlen(b);
		
		gohash( ha, a);		
		gohash( hb, b);
		
		std::vector<int> v;
		for(int i=0,j=0;i<lena-lenb;++i)
		{
			
			int  now = 0 , nowk = k ;
			while(nowk && now < lenb)
				now = find(now)  ,
				-- nowk ,
				printf("%d ",now);
			if( nowk >=0 && now >= lenb)
				v.push_back(i);		
		}
		printf("%d ",v.size());
		for(int i: v)
			printf("%d ",i);
		puts("");
		
		
				
	}
    return 0;
}
