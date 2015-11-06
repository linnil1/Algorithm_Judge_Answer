#include<bits/stdc++.h>
#define lld long long int
#define yesT
#define M 10000
double x[4],y[4];

inline double cal(double &x1,double &x2,double &y1,double &y2)
{
	double sum=0;
	for(int i=0;i<4;++i)
		sum += std::min( hypot( x1-x[i] , y1-y[i] ) , 
						 hypot( x2-x[i] , y2-y[i] ));
	return sum+hypot(x1-x2 , y1-y2);
}

inline void chan(double &r,double &min,double &x,double &y,double &x2,double &y2)
{
	double	rad = rand(),
			tx = x + r*cos(rad),
			ty = y + r*sin(rad),
			tnow = cal(tx,x2,ty,y2);
		
		if(tnow < min)
		{
			min = tnow;
			x = tx; 
			y = ty;
		}
}

void sim(double x1,double x2,double y1,double y2)
{
	double min = cal(x1,x2,y1,y2);
	double r = 10000;
	
	for(int i=0;i<100000;++i)
	{
		chan(r,min,x1,y1,x2,y2);
		chan(r,min,x2,y2,x1,y1);
		r*=0.9998;
	}
	/*printf("%lf!!\n",r);
	
	printf("%lf,%lf\n %lf,%lf\n",x1,y1,x2,y2);*/
	
	printf("%lf\n",2*cal(x1,x2,y1,y2));
}

int main()
{
	srand(time(NULL));
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		for(int i=0;i<4;++i)
			scanf("%lf%lf",x+i,y+i);
		
		sim(0,0,0,0);
		
	};
	return 0;
};
/*
*/
