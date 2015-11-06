#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 10000

ll check;
void  exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;y=0;check=a;
		return ;
	}
	exgcd(b,a%b,y,x);
	y-=x*(a/b);		
}


ll findinv(ll a,ll p)
{
	ll x,y;
	exgcd( a , p , x , y );
	
	if(check!=1)
		return 0;
	return (x+p)%p ;
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int a,p;
	while(~scanf("%d%d",&a,&p))
	#endif	
	{
		ll t = findinv(a%p,p);
		if(t)
			printf("%lld\n",t);
		else
			puts("No Inverse");
	};
	return 0;
};
/*
*/
