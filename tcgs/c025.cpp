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
	char c[1000],d[1000];
	while(cin >> c>>d)
	{
		int com=0,sco=0,maxcom=0,cjp=0;
		for(int i=0;c[i];++i)
			if(c[i]=='-')
				continue;
			else if(c[i]==d[i]){
				++com;++cjp;
				sco += com*100;
				maxcom = max(maxcom,com);

			}
			else{
				com=0;
				cjp = max(cjp-3,0);
			}
		cout << sco << " " << maxcom << " " << cjp << endl;
		
	};
}
	return 0;
};
/*
*/
