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
		int n,w;
		cin >> n >> w;
		int arr[n];
		for(int i=0;i<n;++i)
			cin >> arr[i];
		while(w--)
		{
			int k,x,y;
			cin >> k >> x;
			if(k==3)
			{
				cout << arr[x] << endl;
				continue;
			}
			cin >> y ;
			if( x>y)swap(x,y);
			if(k==1)
			{
				int max=INT_MIN;
				for(x;x<=y;++x)
					if(arr[x]>max)
						max = arr[x];
				cout << max << endl;
			}
				
			else
			{				
				int sum=0,num=y-x+1;
				for(x;x<=y;++x)
					sum+=arr[x];
				cout << sum/num << endl ;
			}
				
			
		}
		
		
	};	
	return 0;
};
/*
7min 
max cannot =  0
*/
