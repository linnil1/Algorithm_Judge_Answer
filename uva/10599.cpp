#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 10100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>


struct xy
{
	int x,y,max,time;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){max=time=0;};
	
	
	
	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
	bool big(xy &a){return x>=a.x && y>=a.y ;}
	void copy(xy &a){max=a.max;time=a.time;}
	void clear(){max=time=0;}
};

xy arr[M];
int vis[M];

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	count=T;
	while(T--)
	#else
	
	#endif
	int a,b,count=0;
	while(~scanf("%d%d",&a,&b)&&a!=-1)	
	{
		arr[0] = xy(0,0);
		++arr[0].time;
		int n=1;
		while(~scanf("%d%d",&arr[n].x,&arr[n].y) && arr[n].x)
			arr[n++].clear();
		arr[n++] = xy(150,150);
		
		std::sort(arr,arr+n);
		
		/*for(int i=0;i<n;++i)
			vis[i]=0;*/
			
		for(int i=0;i<n;++arr[i++].max)
			for(int j=0;j<i;++j)
			{
				if( !arr[i].big(arr[j]))
					continue;
				if(arr[j].max > arr[i].max)
					arr[i].copy(arr[j]);
				else if(arr[j].max == arr[i].max)
					arr[i].time+=arr[j].time;
				
			}
		//for(int i=0;i<n;++i)
		//	printf("%d %d %d %d\n",arr[i].x,arr[i].y,arr[i].max,arr[i].time);
					
		printf("CASE#%d: %d %d ",++count,arr[n-1].max-2,arr[n-1].time);		
		
		int stack[M],s=0;
		for(int i=n-2,now=n-1 ;i>=1;--i)
			if(arr[i].max+1 == arr[now].max && 
				arr[now].big(arr[i]))
				stack[s++] = now = i ;
		while(s--)
			printf("%d ",arr[stack[s]].x*b-b+arr[stack[s]].y);
		puts("");
		
		
		
	};
	return 0;
};
/*
*/
