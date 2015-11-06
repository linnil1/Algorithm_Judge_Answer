#include<cstdio>
#include<algorithm>
#include<ctype.h>
struct peo
{
	int num;
	int s,p,c;
	int sum;
};
bool operator < (peo a,peo b)
{
	return a.sum>b.sum;
};
int main()
{
	int a,b,time;
	scanf("%d\n",&time);
	while(time--)
	{scanf("%d,%d\n",&a,&b);
	
		peo c[a];
		for(int i=0;i<a;++i)
		{
			double ts,tp,tc;
			scanf("%d,%lf,%lf,%lf\n",&c[i].num,&ts,&tp,&tc);
			c[i].s=(int)(ts*1000+0.4);
			c[i].p=(int)(tp*1000+0.4);
			c[i].c=(int)(tc*1000+0.4);
		};
		/*for(int i=0;i<a;++i)
			printf("%lf %lf %lf\n",c[i][0],c[i][1],c[i][2]);*/
		
		char ch[10000];
		int ps=0,pc=0,pp=0;
		scanf("%s",ch);
		for(int i=0;ch[i];++i)
			if(isalpha(ch[i]))
				switch(ch[i])
				{
					case 's':++ps;break;
					case 'p':++pp;break;
					case 'c':++pc;break;
				};
		for(int i=0;i<a;++i)
		{
			c[i].sum=c[i].s*ps+c[i].p*pp+c[i].c*pc;
		}
		std::sort(c,c+a);
		int sum=0,t=0;
		for(int i=0;i<9;++i)
			sum+=c[i].sum;
			
		/*t=0;
		for(int i=0;i<9;++i)
			t+=c[i].s;
		sum+=t*ps/9;
		t=0;
		for(int i=0;i<9;++i)
			t+=c[i].p;
		sum+=t*pp/9;
		t=0;
		for(int i=0;i<9;++i)
			t+=c[i].c;
		sum+=t*pc/9;*/
			
			
		printf("%.3lf\n",(double)sum/9000);
		int rank[100];
		for(int i=0;i<9;++i)
			rank[i]=c[i].num;
		std::sort(rank,rank+9);
		for(int i=0;i<8;++i)
			printf("%d,",rank[i]);
		printf("%d",rank[8]);
		if(time!=0)
			puts("");
		
			
	};
	//scanf("%*d");
	return 0;
};
/*
3
10,3
1,2000.000,5000.000,3000.000
2,4000.000,2000.000,2000.000
3,1000.000,5000.000,3000.000
4,3000.000,2000.000,3000.000
5,2000.000,1000.000,5000.000
6,1000.000,3000.000,1000.000
7,1000.000,5000.000,3000.000
8,5000.000,3000.000,5000.000
9,4000.000,4000.000,4000.000
10,5000.000,1000.000,2000.000
s,p,c
12,5
1,796.501,13.025,994.582
2,676.916,409.636,561.610
3,848.811,443.469,586.526
4,221.629,653.935,608.985
5,589.992,555.418,413.737
6,539.929,334.949,46.011
7,547.726,103.542,559.104
8,934.054,673.369,373.407
9,860.740,995.345,3.964
10,553.694,620.526,438.781
11,48.880,503.052,638.534
12,213.942,398.149,963.539
s,p,s,c,c
*/
