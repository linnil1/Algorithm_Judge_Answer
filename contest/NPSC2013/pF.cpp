#include<stdio.h>
int gcd(int a,int b){
	while(b!=0){
		int t=a%b;a=b;b=t;
	}
	return a;	
}
int main(){
	int a,b,n,i,k=1;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		scanf("%d",&a);
		for(i=1;i<n;i++){
			scanf("%d",&b);
			if(a!=1)
				a=gcd(b,a);
		}
		printf("%d\n",a);			
	}
	return 0;
}
