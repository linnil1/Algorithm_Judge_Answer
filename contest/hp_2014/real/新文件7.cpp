#include<stdio.h>
bool a[100][100],b[100][100];
int main()
{
	int x,y;
	char c[10000];
	scanf("%d %d %s",&y,&x,c);
	for(int i=0;i<x;++i)
		for(int j=0;j<y;++j)
			a[i][j]=(c[i*y+j]=='1');
	for(int i=0;i<x;++i)
		for(int j=0;j<y;++j)
		{
			int sum=0;
			for(int k=-1;k<=1;++k)
				for(int l=-1;l<=1;++l)
					if(i+k>=0&&i+k<x && j+l>=0&&j+l<y)
						sum+=a[i+k][j+l];
			if(a[i][j])
				if(sum<=2)
					b[i][j]=0;
				else if(sum==3 || sum==4)
					b[i][j]=1;
				else
					b[i][j]=0;
			else if(sum==3)
				b[i][j]=1;
			else
				b[i][j]=0;
		};

	
	return 0;
}

