#include<stdio.h>
#define lld long long int
int rand()
{
	static lld r=1234567;
	r=651+r*16769023%1073676287;
	return r;
};
int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;a=b;b=t;
	}
	return a;
}
int main()
{
	int i,j,k;
	int a,b;
	FILE *fin=fopen("qu.txt","w"),
		 *fout=fopen("ans.txt","w");
	while(~scanf("%d",&a))
	{
		while(a--)
		{
            i=rand();j=rand();
            while(!i)
                i=rand();
			while(!j)
			    j=rand();
		    fprintf(fin,"%d %d\n",i,j);
		    fprintf(fout,"%d\n",gcd(i,j));
		};
	};
	return 0;
};
/*









*/
