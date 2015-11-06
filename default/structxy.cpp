
struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
	
	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
};



xy arr[n];
		for(int i=0;i<n;++i)
			scanf("%d%d",&arr[i].x,&arr[i].y);
