#include<bits/stdc++.h>
#define ll long long int
int c[4]={1,2,3,4};
int main()
{
	char s[10000];
	while(~scanf("%s",s)){
		ll p=1,t=0;
		for(int i=0;s[i];++i)
			p*=c[s[i]-'A'],
			++t;
		int arr[t];
		for(int i=0;i<t;++i)
			arr[i]=0;
		int len=0;
		while(p){
			arr[len++]=p%10;
			p/=10;
		}
		printf("0.");
		for(int i=t-1;i>=0;--i)
			printf("%d",arr[i]);
		puts("");	
	}
	return 0;
}
