#include<stdio.h>
#include<queue>
int s[300],all[300],c[300],n;
bool bfs(int a,int arm){
	int tep;
	std::queue<int> que;
	que.push(a);
	bool yesno=1;
	while(!que.empty()){
		a=que.front();
		//printf("%d ",a);
		if(arm==a){
		    yesno=0;break;
		};
		if(s[a]!=0)
			if(a-s[a]>=1){
				tep=a-s[a];
				que.push(tep);
			}
			else if(a+s[a]<=n){
				tep=a+s[a];
				que.push(tep);
			}
		tep=a;
		while(tep-->1)
		    if(tep+s[tep]==a)
		        que.push(tep);
		while(tep++<n)
		    if(tep-s[tep]==a)
		        que.push(tep);
		que.pop();
	};
	return yesno;
};
int main()
{
	int i,yesno;
	while(scanf("%d",&n)!=EOF&&n){
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);
        for(i=yesno=1;i<=n&&yesno;i++)
			if(i!=c[i])
			    if(bfs(i,c[i]))
			        yesno=0;
		if(yesno)
			puts("Okay, let me try.") ;
		else 
			puts("Oh no, I need pizza!") ;
		
		
	}
	return 0;
}

