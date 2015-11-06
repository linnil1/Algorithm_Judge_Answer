#include<stdio.h>
struct t
{
	int x,y;
}spa[100];
int row[9],col[9],use[3][3],now,yes;
char c[10][10];
void dfs(int come)
{
	if(yes)
		return ;
	if(come<0)
	{
		yes=1;
		return ;
	}
	int &x=spa[come].x,
		&y=spa[come].y;
	for(int i=0;i<9&&!yes;++i)
		if((row[x]&(1<<i))&&(col[y]&(1<<i))&&(use[x/3][y/3]&(1<<i)))
		{
			(row[x]^=(1<<i));
			(col[y]^=(1<<i));
			(use[x/3][y/3]^=(1<<i));
			c[x][y]='1'+i;
			dfs(come-1);
			(row[x]^=(1<<i));
			(col[y]^=(1<<i));
			(use[x/3][y/3]^=(1<<i));
		}
	
};
int main()
{
	
	int i,j,k,l;
	yes=0;
	for(i=0;i<9;++i)
		scanf("%s",c[i]);
		/*make*/
	for(i=0;i<9;++i)
	{
		row[i]=0777;
		for(j=0;j<9;++j)
			if(c[i][j]!='-')
				row[i]^=(1<<(c[i][j]-'1'));
		//printf("%o\n",row[i]);
	}
	for(i=0;i<9;++i)
	{
		col[i]=0777;
		for(j=0;j<9;++j)
			if(c[j][i]!='-')
				col[i]^=(1<<(c[j][i]-'1'));
	}
	for(i=0;i<3;++i)
		for(j=0;j<3;++j)
		{
			use[i][j]=0777;
			for(k=0;k<3;++k)
				for(l=0;l<3;++l)
					if(c[i*3+k][j*3+l]!='-')
						use[i][j]^=(1<<(c[i*3+k][j*3+l]-'1'));
		};
	now=0;
	for(i=0;i<9;++i)
		for(j=0;j<9;++j)
			if(c[i][j]=='-')
			{
				spa[now].x=i;
				spa[now].y=j;
				++now;
			}
	dfs(now-1);
	for(i=0;i<9;++i)
		printf("%s\n",c[i]);
		
	return 0;
}
/*
---26-7-1
68--7--9-
19---45--
82-1---4-
--46-29--
-5---3-28
--93---74
-4--5--36
7-3-18---
*/
