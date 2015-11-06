//#include<bits/stdc++.h>
//#include<cctype>
//#include<cstdio>
#include<algorithm>
#define ll long long 
#define yesT
#define M 10000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

typedef int card[4][13];

int dig(char c)
{
	if(isdigit(c))
		return c-'2';
	switch(c)
	{
		case 'T': return 8; 
		case 'J': return 9; 
		case 'Q': return 10; 
		case 'K': return 11; 
		case 'A': return 12; 
		default : puts("error");
	}
}
int col(char c)
{
	switch(c)
	{
		case 'S': return 0; 
		case 'H': return 1; 
		case 'D': return 2; 
		case 'C': return 3; 
		default : puts("error");
	}
}
void init(card a)
{
	for(int i=0;i<4;++i)
		for(int j=0;j<13;++j)
			a[i][j]=0;
	char c[5];
	for(int i=0;i<5;++i)
	{
		scanf("%s",c);
		++a[col(c[1])][dig(c[0])];
	}
}

int todig(card a)
{	
	int sum=0;
	for(int j=12;j>=0;--j)
		for(int i=0;i<4;++i)
			if(a[i][j])
				sum=sum*20+j;
	return sum;
}


pii com(card a)
{
	/*for(int i=0;i<4;++i)
		for(int j=0;j<13;++j)*/
	//同花順
	for(int i=0;i<4;++i)
		for(int j=4;j<13;++j)
			if(a[i][j] && a[i][j-1] && a[i][j-2] && a[i][j-3] && a[i][j-4] )
				return mp( 0 , todig(a) );	
	for(int i=0;i<4;++i)
		if(a[i][12] && a[i][0] && a[i][1] && a[i][2] && a[i][3] )
		{
				a[i][3]=0;
				return mp( 0 , 20*20*20*20*3+todig(a) );	
		};
	//四條		
	for(int j=0;j<13;++j)
		if(a[0][j] && a[1][j] && a[2][j] && a[3][j] )
			return mp( -1 , j );
	//葫蘆
	for(int j=0,three=0,two=0,t;j<13;++j)
	{	
		if(a[0][j] + a[1][j] + a[2][j] + a[3][j] == 3)
			++three,t=j;
		else if(a[0][j] + a[1][j] + a[2][j] + a[3][j] == 2)
			++two;
		if(three && two)
			return mp( -2 , t );
	}
	//同花
	for(int i=0;i<4;++i)
	{
		int sum=0;
		for(int j=0;j<13;++j)
			sum+=a[i][j];
		if(sum==5)
			return mp( -3 , todig(a) );
	}
	//順子
	for(int j=0,t=0;j<13;++j)
	{
		if(a[0][j] + a[1][j] + a[2][j] + a[3][j]  )
			++t;
		else
			t=0;
		if(t==4 && j==3 && a[0][12] + a[1][12] + a[2][12] + a[3][12] )
		{
			a[0][3] = a[1][3] = a[2][3] = a[3][3] =0;
			return mp( -4 , 20*20*20*20*3+todig(a) );			
		}
		if(t==5)
			return mp( -4 , todig(a));		
	}
	//三條
	for(int j=0;j<13;++j)
		if(a[0][j] + a[1][j] + a[2][j] + a[3][j] == 3 )
			return mp( -5 , j );		
	//兩對
	for(int j=0,t=0,b;j<13;++j)
	{
		if(a[0][j] + a[1][j] + a[2][j] + a[3][j] == 2 )
		{
			if(!t)
				b=j;
			++t;			
		};
		if(t==2)
		{
			a[0][b] = a[1][b] = a[2][b] = a[3][b] =0;
			a[0][j] = a[1][j] = a[2][j] = a[3][j] =0;
			return 	mp (-6 , 20*20*j + 20*b + todig(a));
		}
	}
	//一對
	for(int j=0;j<13;++j)
		if(a[0][j] + a[1][j] + a[2][j] + a[3][j] == 2 )
		{
			a[0][j] = a[1][j] = a[2][j] = a[3][j] = 0 ;
			return 	mp (-7 , 20*20*20*20*j + todig(a));
		};
	//無對
	return mp(-8 , todig(a));
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		char c[5];
		card m,o;
		init(m);
		init(o);
		
		puts(com(m) > com(o)?"Win":"Lose");
		
	};
	return 0;
};
/*
*/
