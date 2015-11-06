#include<stdio.h>
#include<algorithm>
#define lld long long int
int rand()
{
	static lld r=1234567;
	r=59857+r*16769023%1073676287;
	return r-500000000;
};
#define number 1000 
int main()
{
	int i,j,k;
	int a,b;
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w");
	while(~scanf("%d",&b))
		while(b--){
		a=(rand()%number+number)%number;//1000 
		fprintf(fin,"%d\n",a);
		int c[a];
		for(i=0;i<a;++i)
		    fpritf(fin,"%d ",c[i]=rand());
        fprintf(fin,"\n");
        
		std::sort(c,c+a);
		for(i=0;i<a;++i)
		    fprintf(fout,"%d ",c[i]);
		fprintf(fout,"\n");
		
	};
	return 0;
};
/*









*/
