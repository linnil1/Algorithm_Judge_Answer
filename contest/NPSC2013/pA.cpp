#include<stdio.h>
#include<math.h>
long long int sum,num;
int c[6];
int dfs(int get,int now,int all){
	if(all==3){
		if(get==sum)
			num++;
		return 0;
	}
	int q,w;
	for(q=now+1;q<6;q++)
		dfs(get*c[q],q,all+1);
}
int main(){
	int a,b,n,i,k=1;
	scanf("%d",&k);
	while(k--){
		sum=1;
		num=0;
		for(i=0;i<6;i++){
			scanf("%d",&c[i]);
			sum*=c[i];
		}
		double s=sqrt(sum);
		if(s==(int)s){
			sum=(int)s;
			dfs(1,-1,0);
		}
		printf("%lld\n",num/2);
	}
	return 0;
}
