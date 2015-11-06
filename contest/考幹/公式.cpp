#include<stdio.h>
#include<string.h>
#include<math.h>
/*#include<string>
#include<iostream>
#include<sstream>
//#include<map>
using std::cin;
using std::cout;
using std::string;
using std::getline;*/
#define lld long long int
#define map std::map<string,string>
#define k 6
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		double ar[k];
  		for(int i=0;i<k;++i)
  		    scanf("%lf",ar+i);
		for(int i=0;i<k;++i)
		    for(int j=k-1;j>i;--j)
		        ar[j]-=ar[j-1];
		/*for(int i=0;i<k;++i)
		    printf("%lf ",ar[i]);
		puts("");*/
		/*double &c=ar[0],&b=ar[1],&a=ar[2],&d=ar[3];
		for(int n=1;n<=6;++n)
		{
			double  thr=d*n*n*n/6,
					two=(-d+2*a-3*d)*n*n/4,
					one=(11*d-9*a+6*b)*n/6,
					zer=a-b-d+c;
			printf("%lf ",one+zer+two+thr);
		};*/
		double &c=ar[1],&b=ar[2],&a=ar[3],&d=ar[4];
		//for(int n=1;n<=7;++n)
		{
			double  thr=d*(n-1)*(n-1)*n*n/24,
					two=(-d+2*a-3*d)*n*(n-1)*(2*n-1)/24,
					one=(11*d-9*a+6*b)*n*(n-1)/12,
					zer=(a-b-d+c)*(n-1);
			printf("%lf ",one+zer+two+thr+ar[0]);
		};
		printf("\n");
	}
	return 0;
};
