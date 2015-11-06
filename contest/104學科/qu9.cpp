#include<cstdio>
#include<algorithm>


int main()
{
	int ax,ay,ax1,ax2,ay1,ay2,mbx1,mbx2,mby1,mby2,bx1,bx2,by1,by2;
	while(~scanf("%d%d%d%d%d%d",&ax,&ay,&mbx1,&mby1,&mbx2,&mby2))
	{
		ax1=ax-50;
		ax2=ax+50;
		ay1=ay-50;
		ay2=ay+50;
		
		bx1 = mbx1 < mbx2 ? mbx1 : mbx2;
		bx2 = mbx1 > mbx2 ? mbx1 : mbx2;
		by1 = mby1 < mby2 ? mby1 : mby2;
		by2 = mby1 > mby2 ? mby1 : mby2;
		
		
		
		if(ax1<bx1 && bx1 < ax2&& ay1 < by1 && by1 < ay2 &&
		   ax1<bx2 && bx2 < ax2&& ay1 < by2 && by2 < ay2 )
		   	puts("C");
		else if(bx1 > ax2 || bx2 < ax1 || 
				by1 > by2 || by2 < ay1)
			puts("A");
		else 
			puts("B");
	};
	return 0;
};
/*
170 180 70 80 100 110
70 80 10 70 100 110
70 80 
*/
