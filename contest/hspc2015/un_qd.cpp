#include<bits/stdc++.h>
#define ll long long int
#define M 1000000
ll MOD =  1000000000000ll ;

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
			sum = (sum+a)%MOD;
	}
	if(sum<0)
		puts("wrong");
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
	/*MOD =10000000000ll;
	printf("%I64d",pow(78,8646916096ll));*/
	
	ll n;
	while(~scanf("%I64d",&n)){
		for(MOD=10;MOD<=10000;MOD*=10)
		for(int i=0;i<MOD;++i)
			if( pow(n,i) == i ){
			
				printf("%d \n",i);
				break;
			}
	}
	return 0;
}
