#include<stdio.h>
#include<string.h>
#include<algorithm>
struct ran{
	int num,val;
};

bool cmp(ran a,ran b){
	if(a.val!=b.val)
	    return a.val<b.val;
	else
	    return a.num<b.num;
};
bool rcmp(ran a,ran b){
	return a.val<b.val;
};
int main()
{
	int i,num,j,n;
	ran s[300],c[300];
	while(scanf("%d",&n)!=EOF&&n){
		
		for(i=0;i<n;i++){
			scanf("%d",&s[i].val);
			s[i].val=i;
		}
		for(i=0;i<n;i++){
			scanf("%d",&c[i].val);
			c[i].val=i;
		}
		std::sort(s,s+n,cmp);
		std::sort(c,c+n,cmp);
		
        int rank[n];
		bool use[n];
		memset(rank,0,sizeof(rank));
		memset(use,1,sizeof(use));
		
        for(i=n-1;i>=0;i--){
			
			num=std::lower_bound(s,s+n,c[i],rcmp)-s;
			if(num==0)
			    break;
			else{
			    while(rank[s[num].num]!=0)
			        num++;
				rank[s[num].num]=c[i].num+1;
				use[s[num].num]=0;
			};
		};
		for(i=j=0;i<n;i++){
		    if(rank[i]==0){
		        while(j<n&&!use[j])
					j++;
				printf("%d ",++j);
			}
			else
			    printf("%d ",rank[i]);
		};
		puts("");
		    
		
		
	}
	return 0;
}

