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
using namespace std;



int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		int min=0x7fffffff,max=-1;
		while(n--){
			int x;
			cin >> x;
			if(x>max)
				max=x;
			if(x<min)
				min=x;
		}
		cout << max - min << endl;	
	};
}
	return 0;
};
/*
*/
