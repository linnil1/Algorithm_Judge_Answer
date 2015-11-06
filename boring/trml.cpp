#include<cstdio>
#define MOD 11
int po(int a,int b){
	int sum =1 ;
	while(b){
		if(b&1)
			sum = sum * a  %MOD;
		a = a*a%MOD;
		b>>=1;
	}
	return sum ;
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",po(a,b));
	return 0;
}
