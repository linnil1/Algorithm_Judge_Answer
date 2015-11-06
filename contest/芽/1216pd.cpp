#include<cstdio>
#include<algorithm>
struct dice
{
	int m[6];
}c[100];

int findno(int *m)
{	
	int test[7];
	for(int i=1;i<7;++i)
		test[i]=0;
	test[m[0]]=test[m[1]]=test[m[4]]=test[m[5]]=1;
	int x;
	for(x=1;x<7;++x)
		if(!test[x])
			break;
	return x;
};
#define easy(a,b,c,d) {int t=m[a];m[a]=m[b];m[b]=m[c];m[c]=m[d];m[d]=t;}
void turn(dice &a,char od)
{
	int *m=a.m;
	switch(od)
	{
		case 'E':easy(2,0,3,4);break;
		case 'W':easy(4,3,0,2);break;
		case 'N':easy(5,0,1,4);break;
		case 'S':easy(4,1,0,5);break;
	};
};
int tryit(dice a)
{	
	int *m=a.m,k=0;
	for(int i=0;i<4&&!k;++i)
		if(m[0]==1)
			k=1;
		else
			turn(a,'N');
	for(int i=0;i<4&&!k;++i)
		if(m[0]==1)
			break;
		else
			turn(a,'E');
	
	k=0;
	for(int i=0;i<4&&!k;++i)
		if(m[1]==2)
			break;
		else
			easy(1,2,5,3);
	
	return m[2]==3;
			
	
};
void init(dice &temp)
{
	int *m=temp.m;
	scanf("%d%d",&m[0],&m[1]);
	m[5]=7-m[1];
	m[4]=7-m[0];
	
						
	int x=findno(m),y=7-x;
	m[2]=x;m[3]=y;
	if(tryit(temp))
		return ;
	else
		{m[2]=y;m[3]=x;}	
	
};



int main()
{
	int n;
	while(~scanf("%d%*d",&n))
	{
		for(int i=0;i<n;++i)
			init(c[i]);
			
		char order[150];
		scanf("%s",order);		
		for(int i=0;order[i];++i)
			for(int j=0;j<n;++j)
				turn(c[j],order[i]);
				
		for(int i=0;i<n;++i)
			printf("%d\n",c[i].m[0]);
		
			
	};
	return 0;
};
