#include<cstdio>
#include<algorithm>
#define lld long long int
lld find(lld a)
{
	++a;
	if(a<=1)
		return 0;
	else
		return a/2;		
};
lld count(lld a,lld b)
{
	return find(b-a+1);
};
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        lld a,b;
        scanf("%lld%lld",&a,&b);
        lld c[b];
        for(int i=0;i<b;++i)
        	scanf("%lld",c+i);
        std::sort(c,c+b);
        
        lld now=1,sum=0;
        for(int i=0;i<b;++i)
        {
        	sum += count(now,c[i]-2);
        	now = c[i] +2 ;
        };
        
        printf("%lld\n",sum + count(now,a));
    }
    return 0;
}
