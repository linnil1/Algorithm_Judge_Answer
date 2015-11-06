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
		int c=1;
		while(n>=3){
			if(n%3==0)	
				n/=3;
			else if(n%3==1)
				n = 2*n+1;
			else
				n = 2*n-1;
			++c;
		}
		printf("%d\n",c);
	};
}
	return 0;
};
/*
*/
