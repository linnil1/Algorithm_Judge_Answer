#include<cstdio>
#include<cstdlib>
#include<set>
#include<ctype.h>
#include<algorithm>
struct fo{
	int num,use;
}c[100100],tep;
bool cmp(fo a,fo b){
	return  a.num<b.num;
}
int sum,a;
int find(int now,int re){
	//printf("%d ",now);
	tep=c[now];
	tep.num*=2;
	fo *up=std::upper_bound(c,c+a,tep,cmp),
		*dn=std::lower_bound(c,c+a,tep,cmp);
	if(up==dn){		
		if(now+1<a&&!re&&c[now+1].num==c[now].num)
			sum++;
		sum++;
		return 0;
	}
	if(up!=dn){
		sum++;
		find(dn-c,re);
	}
	for(;dn!=up;dn++){
		dn->use=0;		
	};
}
				
int main(){
	int q,w,e,r,t,n;
	scanf("%d",&n);
	while(n--){
	scanf("%d",&a);
		sum=0;
		for(q=0;q<a;q++){
			scanf("%d",&c[q].num);
			c[q].use=1;
		};
		std::sort(c,c+a,cmp);
		for(q=0;q<a;q++)
			if(c[q].use){
				fo *up=std::upper_bound(c,c+a,c[q],cmp),
					*dn=std::lower_bound(c,c+a,c[q],cmp);
				if(q+1<a&&c[q+1].num==c[q].num){				
					find(q,1);
					sum++;
				}
				else
					find(q,0);
				
				for(;dn!=up;dn++){
					dn->use=0;		
				};			
			}
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
