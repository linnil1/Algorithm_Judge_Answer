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
	int n;
	while(cin >> n)
	#endif	
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin >> arr[i];
		sort(arr,arr+n);
		int sum=1;
		for(int i=1;i<n;++i)
			if(arr[i]!=arr[i-1])
				++sum;
		cout << sum << endl;
		
	};
	return 0;
};
/*
*/
