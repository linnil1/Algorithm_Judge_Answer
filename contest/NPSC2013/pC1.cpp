#include<cstdio>
#include<cstdlib>
#include<set>
#include<ctype.h>
#include<algorithm>
std::set<int> fo;
int c[100100],a,sum;
int dfs(int now,int time){
	if(time>sum){
		sum=time;
	}
	if(now==a)
		return 0;
	if(sum!=a){
	
	if(!fo.count(c[now]*2)){
		fo.insert(c[now]*2);
		dfs(now+1,time+1);
		fo.erase(c[now]*2);
	};
	if(!fo.count(c[now])){
		fo.insert(c[now]);
		dfs(now+1,time+1);
		fo.erase(c[now]);
	};
	if(!fo.count(0)){
		fo.insert(0);
		dfs(now+1,time);
		fo.erase(0);
	};
}
}
int main(){
	int q,n;
	scanf("%d",&n);
	while(n--){
	scanf("%d",&a);
		fo.clear();
		sum=0;
		for(q=0;q<a;q++)
			scanf("%d",&c[q]);
		dfs(0,0);	
		printf("%d\n",sum);	
		//puts("");				
	}
	return 0;
}
/*
3
3
1 2 3
4
1 1 1 1
5
1 1 2 3 5
*/
