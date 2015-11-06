#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100100
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	cin>>T;
	while(T--)
	#else
	int tx,ty;
	while(cin >> tx >> ty)
	#endif	
	{
		int now=30   ,len;
		ll sum=0;
		while(now!=0)
		{
			 --now;
			 len = 1<<now;
			 if(tx <= len)
			 	if(ty <=len)
			 		;
			 	else
			 		sum+=2*(1ll<<(now<<1)),ty-=len;
			else
				if(ty<=len)
					sum+=3*(1ll<<(now<<1)),tx-=len;
				else
					sum+=1*(1ll<<(now<<1)),tx-=len,ty-=len;
		}
		cout << sum+1 << endl;
	};
	return 0;
};
/*
50min
ÅÞ¿è°ÝÃD
 
*/
