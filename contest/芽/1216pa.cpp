#include<cstdio>
#include<algorithm>
int x11,x12,y11,y12,x21,x22,y21,y22;

int area(int x,int y)
{
	if(x==0 && y==0)
		return 3;
	else if( x==0 || y==0)
		return 2;
	else
		return 1;
};
int find()
{
	int x1=std::max(x11,x21),
		x2=std::min(x12,x22),
		y1=std::max(y11,y21),
		y2=std::min(y12,y22);
	return area(x2-x1,y2-y1);
};
int main()
{
	int n;
	while(~scanf("%d",&n))
	while(n--)
	{
		scanf("%d%d%d%d",&x11,&y11,&x12,&y12);
		scanf("%d%d%d%d",&x21,&y21,&x22,&y22);
		
		if(x11 > x22 || x12 < x21 || y11 > y22 || y12 < y21)
			puts("4");
		else
			printf("%d\n",find());
			
	};
	return 0;
};
