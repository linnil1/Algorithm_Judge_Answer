#include<bits/stdc++.h>
#define pair std::pair<int,int> 
#define mk(a,b) std::make_pair(a,b)

void plus(std::deque<pair> &q, pair p)
{			
	while(q.size() && q.back().first <= p.first)
	{
		if(q.back().first == p.first)
		{
			q.back() = p ;
			q.pop_back();
		}
		else
			q.pop_back();
	}
	q.push_back(p);	
};


int main(){
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	int a,b;
    	scanf("%d%d",&a,&b);
    	int sum[2*a+2],c[a];
    	sum[0]=0;
		for(int i=0;i<a;++i)
		{
			scanf("%d",c+i);
			sum[i+1] = sum[i] + c[i];
		};
		for(int i=0;i<a;++i)
			sum[i+a+1] = sum[i+a] + c[i];
			
		/*for(int i=0;i<2*a+1;++i)
			printf("%d ",sum[i]);	
		puts("");	*/
		
		
		std::deque< pair > q ;
		for(int i=1;i<=b;++i)
		{
			plus (q, mk(sum[i],i) );
		};
		int max=-2147483648;
		for(int i=0;i<=a;++i)
		{
			max = std::max(q.front().first - sum[i]  ,max);		
			//printf("%d\n",max);
			
			if( q.front().second <= i+1  )
				q.pop_front();
			
			plus(q , mk( sum[i+b+1] , i+b+1 ) );
		};
		printf("%d\n",max);
    }
    return 0;
}
