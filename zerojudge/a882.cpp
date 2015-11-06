#include<bits/stdc++.h>
#define ll long long 
#define yesT
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
	#endif	
	{
		
		string s;
		cin >> s;
		int sum=0;
		for(int i=0;i<s.size();++i)
			if(s[i]=='X')
				sum+=2;
			else if(s[i]=='H')
				sum++;
		cout << sum << endl ;
	};
	return 0;
};
/*
5min
*/
