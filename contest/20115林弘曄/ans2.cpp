#include<cstdio>
#include<cstdlib>
#include<ctype.h>
#include<string>
#include<cstring>
#include<algorithm>
using std::string;
struct xy
{
	int me;
	char c[1000];
};
bool operator < (xy a,xy b)
{
	return a.me<b.me;
};
string com[11]={"�s","�@","�G","�T","�|","��","��","�C","�K","�E"},
		comp[4]={"�Q","��","�d","�U"};
	
int mult(int t)
{
	int sum=1;
	while(t--)
		sum*=10;
	return sum;
};
	
int todig(char *c)
{
	/*for(int i=0;i<strlen(c);i++)
		printf("%d ",c[i]);*/
	if(c[0]>='0' && c[0]<='9')
	{
		int t;		
		sscanf(c,"%d",&t);
		return t;
	}
	string m;
	int sum=0,now=0,use=0;
	int j;
	//�@�ʤG�ɤT 
	for(int i=0;i<strlen(c);i+=2)
	{		
         //�@ �� �G �� �T 
		m=string(c+i,c+i+2);
		//printf("%s\n",m.c_str()); 
		// //1 100 2 10 3 
		for(j=0;j<4;++j)
			if(m==comp[j])
				break;
		if(j!=4)
		{
			now*=mult(j+1);
			sum+=now;
			if(use==0 && j==0)
				sum+=mult(j+1);
			now=use=0;
		}
		
		else
		{
			use=1;
			for(j=0;j<10;++j)
				if(m==com[j])
					break;
			now=j;
		};
			
		
	}
	//100+20+3
	if(now!=0)
		sum+=now;
		
	return sum;	
	//123
	
};
int main()
{
    int a;
    while(~scanf("%d",&a))
    {
		xy arr[a];
		for(int i=0;i<a;++i)
		{
			scanf("%s",arr[i].c);
			
			arr[i].me=todig(arr[i].c);
			//printf("%d\n",arr[i].me);
		};
		std::stable_sort(arr,arr+a);
		for(int i=0;i<a;++i)
			printf("%s\n",arr[i].c);
	};
    return 0;
};
