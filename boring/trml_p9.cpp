#include<cstdio>
void test(){
	for(int i=1;i<999;++i)
		for(int j=1;j<=i;++j){
			int sum = 2*i*(1+2*i)/2 -   i*(j+j+i-1)/2;
			if(sum==2015){
				printf("%d!!\n",i);
				return ;
			}
		}

			
}
int main(){
	int n;
	scanf("%d",&n);
	test();
	return 0;
}
