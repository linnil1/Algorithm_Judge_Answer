#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string

struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
};
xy operator -(xy a,xy b)
{
	return xy(a.x-b.x,a.y-b.y);
}
int cross (xy a,xy b)
{
	return a.x*b.y - a.y*b.x;
}

int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	char c[1000];
	while(gets(c))
	#endif	
	{
		//in
		int arr[8],now=0;
		int sum=-1;
		for(int i=0;c[i];++i)
			if(isdigit(c[i]))
			{
				if(sum==-1)
					sum = c[i]-'0';
				else
					sum = sum*10+c[i]-'0';				
			}
			else if(sum!=-1)
			{
				arr[now++]=sum;
				sum=-1;					
			}
		
		xy p[4];
		for(int i=0;i<4;++i)
			p[i]= xy(arr[2*i],arr[2*i+1]);		
		
		// area =0
		if( cross(p[2]-p[0], p[1]-p[0]) == 0 )
		{
			puts("Triangle doesn't exist.");
			continue;
		}
		
		// to counter-clockwise
		if( cross(p[1]-p[0], p[2]-p[0]) <0 )
			std::swap(p[2],p[1]);
		//point is at the left of all the edge
		if( cross(p[1]-p[0],p[3]-p[0]) >0 && cross(p[2]-p[1],p[3]-p[1]) >0 && cross(p[0]-p[2],p[3]-p[2])>0  )
			puts("Point is within the Triangle.");
		else
			puts("Point is NOT within the Triangle");
	};
	return 0;
};
/*
*/
