#include<cstdio>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<bitset>

#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define pb push_back
//using namespace std;


int main()
{
//	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(std::cin >>n)
	{
		int x,y,max=0,num;
		for(int i=1;i<=n;++i){
			int tx,ty;
			scanf("%d%d",&tx,&ty);
			int sum = tx*tx + ty*ty ;
			if(max < sum ){
				x = tx ;
				y = ty ;
				max = sum ;
				num = i ;
			}
		}
		printf("%d %d\n",num,max);
	};
}
	return 0;
};
/*
*/
