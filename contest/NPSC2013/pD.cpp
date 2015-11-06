#include<cstdio>
#include<cstdlib>
#include<map>
#include<ctype.h>
#include<algorithm>
std::map<long long,long long> fo;

int main(){
	long long a,b,i,j,k,q,w,e,n,foods;
	long long sum;
	char c[100000];
	scanf("%lld",&n);
	while(n--){
		long long food[2048];
		scanf("%lld%lld",&a,&b);
		fo.clear();
		w=0;
		fgets(c,100000,stdin);
		for(i=0;i<a;i++){
			fgets(c,100000,stdin);			
			for(j=5;c[j]!='$';j++);
			fo[atol(c+4)]=atol(c+j+1);
			//printf("%d %d\n",atoi(c+4),fo[atoi(c+4)]);		
		};
		//item
		foods=0;
		for(i=0;i<b;i++){
			fgets(c,100000,stdin);
			sum=0;
			for(j=5;c[j]!='$';j++);			
			q=atol(c+4);
			w=atol(c+j+1);
			for(;c[j]!=':';j++);
			for(j++;c[j]!='\0';j=k){
				k=j+1;
				if(c[j]==' '){
					for(k=j;!isdigit(c[k]);k++);
					e=atoi(c+k);
					for(k+=4;!isdigit(c[k]);k++);
					if(fo.count(atol(c+k)))
						sum+=e*fo[atol(c+k)];
					else
						sum=100000000;
				};
			};
			if(w>sum)
				food[foods++]=q;
						
		};
		//food
		std::sort(food,food+foods);	
		if(foods==0)	
			puts("no such recipe.");
		else{
			printf("food%lld",food[0]);
			for(i=1;i<foods;i++)
				printf("/food%lld",food[i]);
		}
		if(foods!=0)puts("");				
	}
	return 0;
}
/*
3
3 5
item1001 $20
item1002 $10
item1003 $25
food9001 $50 : 1 item1001 2 item1002
food9002 $100 : 4 item1003
food7001 $101 : 2 item1001 1 item1002 2 item1003
food10002 $77 : 1 item1001
food10004 $50 : 1 item1001 2 item1002
1 2
item1 $1
food1 $99999999 : 1 item1 1 item2
food2 $99999999 : 99 item1
3 1
item99999 $99999997
item99998 $99999998
item99997 $99999999
food514 $99999999 : 99 item9999
*/
