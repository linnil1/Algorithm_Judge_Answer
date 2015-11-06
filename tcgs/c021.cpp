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

int need[3][3]={
	{1,3,5},
	{3,2,4},
	{3,3,3}
};

int main()
{
//	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int val[3];
	while(std::cin >>val[0]>>val[1]>>val[2])
	{
		char win='a';
		int min =0x7fffffff;
		for(int i=0;i<3;++i){

			int sum=0;
			for(int j=0;j<3;++j)
				sum += need[i][j]*val[j];
			if(sum < min)	
				win = 'A' + i ,
				min = sum ;
		}
		printf("%c %d\n",win,min);	
	};
}
	return 0;
};
/*
*/
