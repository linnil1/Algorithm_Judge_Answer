//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

#define ll long long 
//#define yesT
#define M 10000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>


struct xy
{
	int x,y;
	char w;
	xy(){};
	xy(int _x, int _y):x(_x),y(_y){};
	bool operator < (const xy &b)const
	{
		if(x != b.x)
			return x<b.x;
		else
			return w=='p';
	}
};

xy food[400],
	todo[10010],
	see[1100];
int foods,n,k;

xy next(xy& a,char c)
{
	switch(c)
	{
		case 'r':return xy(a.x+1 , a.y);break;
		case 'l':return xy(a.x-1 , a.y);break;
		case 'u':return xy(a.x , a.y+1);break;
		case 'd':return xy(a.x , a.y-1);break;
		default : puts("error");
	}
}
bool ok(char c,char way)
{
	switch(c)
	{
		case 'r':return way!='l';break;
		case 'l':return way!='r';break;
		case 'u':return way!='d';break;
		case 'd':return way!='u';break;
		default : puts("error");
	}
}

bool touch(xy &a,std::deque<xy> &q )
{
	for(int i=0;i<q.size();++i)
		if(a.x == q[i].x && a.y == q[i].y)
			return 1;
	return 0;
		
}

void gomove()
{
	int nowf=0,nown=0,nowk=0,sum=0;
	std::deque<xy> q;
	for(int i=0;i<5;++i)
		q.push_back( xy(5-i , 10) );
	char way = 'r';
	int now=0;
	while(1)
	{	
		int eat=0;
		if(nowf<foods && q.front().x == food[nowf].x && 
						 q.front().y == food[nowf].y)
			nowf++,sum+=10,eat=1;
		while(nowk<k && now == see[nowk].x )
			printf("%d %d (%d,%d) (%d,%d)\n",
				q.size(),sum,q.front().x,q.front().y,q.back().x,q.back().y),
				++nowk;		
			
		if(eat)	
			q.push_back(q.back());
				
		//printf("%c\n",way);
		
		if(nown<n && now == todo[nown].x )
		{		
			if( ok(todo[nown].w ,way))
				way =todo[nown].w;
			++nown;
		};
		xy t = next ( q.front() , way );
		++now;		
		if(t.x<1 || t.x>40 || t.y>20 || t.y<1 || touch(t,q))
		{
			if(eat)
				q.pop_back();
			break;
		}
		q.push_front(t);	
		q.pop_back();
		
	}	
	printf("%d %d %d\n",now,q.size(),sum);
}

int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	while(~scanf("%d%d%d",&foods,&n,&k)&&foods)
	#endif	
	{
		for(int i=0;i<foods;++i)
			scanf("%d%d",&food[i].x,&food[i].y);
		
			
		for(int i=0;i<n;++i)
		{
			char ch[10];
			scanf("%s%d",ch,&todo[i].x);
			todo[i].w = ch[0];
		}
		for(int i=0;i<k;++i)
		{
			scanf("%d",&see[i].x);
			see[i].w = 'p';
		}
		gomove();
		
	};
	return 0;
};
/*
*/
