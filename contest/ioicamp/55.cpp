#include<bits/stdc++.h>
#define M 1000000
#define lld long long int 
struct house
{
	int x,y;
};

inline double way(double a,double b)
{
	return a*a+b*b;
};

int n;
house h[1100];

inline double cal(double x,double y)
{
	double sum =0;
	for(int i=0;i<n;++i)
		sum += hypot( x - h[i].x , y - h[i].y); 
	return sum;
};

std::tuple<double,double> go()
{
	double r=10000, x=0,y=0, now = cal(x,y);
	for(int i=0;i<1000;++i)
	{ 
		double base = 6.28/10,
				the = rand();
		for(int j=0;j<10;++j)
		{
			the += base ;
			double tx = x + r*cos(the),
			 	   ty = y + r*sin(the),
				   t  = cal(tx,ty);
			if(t < now)
			{
				now = t;
				x = tx ;
				y = ty ;
			}
		};
		r *= 0.98;
		//printf("%lf ",r);
	} 
	//printf("%lf??\n",r);
	return std::make_tuple(x,y);
};

int main(){
	srand(time(NULL));
	//freopen("abc.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
	{
		scanf("%d",&n);
		//printf("n=%d\n",n);
		for(int i=0;i<n;++i)
			scanf("%d%d",&h[i].x,&h[i].y);
		std::tuple<double,double> t = go();
		
		//printf("%lf %lf!!\n",std::get<0>(t),std::get<1>(t));
			
		printf("%lf\n",cal(std::get<0>(t),std::get<1>(t)) * 2);
	}
    return 0;
}

/*
3
3
-1 0
0 1
1 0
4
-1 0
0 1
0 -1
1 0
12
-3 1
-2 0
-1 -1
-3 -1
-2 0
-1 1
1 1
1 0
1 -1
2 -1
2 1
3 0
*/
