
struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};

	bool in(){
		return ~scanf("%d%d",&x,&y);
	}

	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
};
