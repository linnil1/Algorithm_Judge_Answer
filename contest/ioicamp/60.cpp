#include<bits/stdc++.h>
#define lld long long int

#define M 10000

struct xy
{
	double x,y;
};

#define pp(a,b) ((a)*(a) + (b)*(b))
double find(xy *p,int m)
{
	double x1=(p[1].x+p[0].x)/2,
		   y1=(p[1].y+p[0].y)/2,
		   vx1=(p[1].y-p[0].y),
		   vy1=-(p[1].x-p[0].x);
	double x2=(p[2].x+p[0].x)/2,
		   y2=(p[2].y+p[0].y)/2,
		   vx2=(p[2].y-p[0].y),
		   vy2=-(p[2].x-p[0].x);
		
	double w = (x1*vy1-y1*vx1 - x2*vy1 + y2*vx1) / ( vx2*vy1 - vx1*vy2);
	
	//printf("%lf!!\n", vx2*vy1 - vx1*vy2);
	
	return pp( p[0].x - (x2 + w*vx2) , p[0].y - (y2+w*vy2) );
}

double area(int n,double r)
{
	return r*sin((double)6.283185307179586476925286766559 / n) 
			* n /2 ;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
	
		xy p[m];
		for(int i=0;i<m;++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		
		if(m==2 && n==3)
			printf("%lf\n",pp( p[1].x-p[0].x ,p[1].y-p[0].y)*sqrt(3)/4);
		else if(m<=2)
			puts("-1");
		else
			printf("%lf\n",area(n,find(p,m)));
	};
	return 0;
};
/*
*/
