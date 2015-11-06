//#include<bits/stdc++.h>
#include<algorithm>
#define ll long long 
//#define yesT
#define M 10000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

struct xy
{
	double x,y;
};

int sum,ti;
int n;

bool touch(double a,double b,double c)
{
	//printf("%lf %lf %lf %d \n",a*a,b*b,c,a*a+b*b <= c);
	return a*a+b*b <= c+0.002;
}

void find(xy *arr,xy *sto)
{
	double 	&xa=sto[0].x,&ya=sto[0].y,
			&xb=sto[1].x,&yb=sto[1].y,
			&xc=sto[2].x,&yc=sto[2].y;
	double 	x1 = (xa+xb)/2,
			y1 = (ya+yb)/2,
			x2 = (xb+xc)/2,
			y2 = (yb+yc)/2,
			vx1 =  (yb-ya),
			vy1 = -(xb-xa),
			vx2 =  (yc-yb),
			vy2 = -(xc-xb);
	
	double w = (x1*vy1-vx1*y1-x2*vy1+y2*vx1)/(vx2*vy1-vy2*vx1),
			x = x2 + vx2*w,
			y = y2 + vy2*w;
	
	
	double r = (xa-x)* (xa-x)+(ya-y)* (ya-y);
	
	for(int i=0;i<n;++i)
		if(touch(x-arr[i].x,y-arr[i].y,r))
			++sum;
	//printf("%d\n",sum);
	++ti;
}

void dfs(xy *arr,xy *sto,int now,int time)
{
	if(time==3)
	{
		find(arr,sto);
		return ;
	}
	if(now<0)
		return ;
	for(now;now>=0;--now)
	{
		sto[time]=arr[now];
		dfs(arr,sto,now-1,time+1);
	};
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	while(~scanf("%d",&n))
	#endif	
	{
		xy arr[n],sto[3];
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&arr[i].x,&arr[i].y);
		sum=ti=0;
		dfs(arr,sto,n-1,0);
		//printf("%d %d\n",sum,ti);
		printf("%.6lf\n",(double)sum/ti);
	};
	return 0;
};
/*
*/
