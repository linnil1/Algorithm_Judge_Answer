#include<bits/stdc++.h>
#define ll long long int
#define M 1000000
ll MOD ;

ll mul(ll a,ll b){
	int arr[70],len=0;
	while(b){
		arr[len++]=b&1;
		b>>=1;
	}
	ll sum=0;
	for(int i=len-1;i>=0;--i){
		sum = sum*2 %MOD;
		if(arr[i])
			sum = (sum+ a)%MOD;
	}
	return sum;
}


ll pow(ll a,ll t){
	ll sum=1;
	while(t){
		if(t&1)
			sum = mul(sum,a);
		a = mul(a,a);
		t>>=1;
	}
	return sum;
}


int main()
{
	/*int a,b;
	MOD = 110000;
	while(~scanf("%d%d",&a,&b)){
		printf("%I64d\n",mul(a,b));
	}*/
	int n;
	while(~scanf("%d",&n) && n){
		ll m=1,now=0;
		for(int i=0;i<12;++i,m*=10){
			MOD = m*10;
			for(int j=1;j<=9;++j){				
				ll t = m*j + now ;
				if( pow(n,t) == t){
					now=t;
					//printf("%d ",j);
					break;
				}  
			}
			if( now< m/10)
			for(int j=1;j<=9;++j){				
				ll t = m*j + 6*m/10 + now ;
				if( pow(n,t) == t){
					now=t;
					//printf("%d ",j);
					break;
				}  
			}
			if( now< m && m>=10 && now/(m/10)==3)
			for(int j=1;j<=9;++j){				
				ll t = m*j + 4*m/10 + now ;
				if( pow(n,t) == t){
					now=t;
					//printf("%d ",j);
					break;
				}  
			}
			if( now< m&& m>=10 && now/(m/10)==7)
			for(int j=1;j<=9;++j){				
				ll t = m*j -4*m/10 + now ;
				if( pow(n,t) == t){
					now=t;
					//printf("%d ",j);
					break;
				}  
			}
		}
		printf("%lld\n",now);
	}
	return 0;
}
