#include<cstdio>
int main()
{
	int x,y;
	int start=0,a;
	char c[100];
	while(scanf("%s",c))
	{
		
		if(c[0] == 'B')
			start=1;
		else if(start)
			switch(c[0])
			{
				case 'X':scanf("%d",&a);x=a;;break;
				case 'Y':scanf("%d",&a);y=a;;break;
				case 'U':scanf("%d",&a);y+=a;;break;
				case 'D':scanf("%d",&a);y-=a;;break;
				case 'R':scanf("%d",&a);x+=a;;break;
				case 'L':scanf("%d",&a);x-=a;;break;
				case 'E':start=-1;break;
			};
		//printf("%d %d\n",x,y);//break;
		//printf("%d\n",start);
		if(start == -1)
		{
			printf("%d\n%d\n",x,y);
			break;
		};
	};
	return 0;
};
