#include<stdio.h>
#define lld long long int
int rand(){
	static lld r=1234567;
	r=651+r*16769023%1073676287;
	return r;
};
int main()
{
	int i,j,k;
	int a,b;
	srand(time(NULL)); 
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w"); 
	while(~scanf("%d",&a))
	{
		while(a--)
		{
			b=rand();
			b+=2; 
			fpintf(fin,"%d\n",b); 
			int bemax=0x88888888,max=0x88888888; 
			for(i=0;i<b;++i) 
			{ 
				fprintf(fin,"%d ",j=r());
				if(j > bemax)
					bemax = j ;
				if(bemax > max)
					{int t=max;max=bemax;bemax=t;} 
			}; 
			fprintf(fin,"\n"); 
		    
		    fprintf(fout,"%d %d\n",bemax,max);
		};
	};
	return 0;
};
/*









*/
