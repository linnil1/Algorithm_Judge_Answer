#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lld long long int
int main()
{
	int i,j,k;
	int a,b;
	srand(time(NULL));
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w");
	while(~scanf("%d",&a))
	{
		int t=0; 
		while(a--)
		{			
			int x1,x2,y1,y2,x3,y3; 
		    fprintf(fin,"%d %d ",x1=rand(),y1=rand());
		    fprintf(fin,"%d %d\n",x2=rand()+x1,y2=rand()+y1);
		    
		    fprintf(fin,"%d %d\n",x3=rand(),y3=rand());
		    
		    if(x1 <= x3 && x3 <= x2 &&
		   		y1 <= y3 && y3 <= y2 )
				fprintf(fout,"Yes\n"); 
			else
				fprintf(fout,"No\n"); 
		};
	};
	return 0;
};
/*









*/
