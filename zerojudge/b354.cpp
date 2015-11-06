#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 10010
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
using namespace std;

void zeropack(int* c,int val,int cost,int n)
{
	for(int i=n-val;i>=0;--i)
		if(c[i]!=INT_MAX && c[i]+cost < c[i+val])
			c[i+val] = c[i]+cost;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	cin>>T;
	while(T--)
	#else
	int money,na,nb;
	while(cin >> money >> na >> nb)
	#endif	
	{
		int a[M],b[M];
		for(int i=1;i<M;++i)
			a[i]=b[i]=INT_MAX;
		a[0]=b[0]=0;
		while(na--)
		{
			int cost,val;
			cin >> cost >> val;
			zeropack(a,val,cost,M-1);
		}
		while(nb--)
		{
			int cost,val;
			cin >> cost >> val;
			zeropack(b,val,cost,M-1);
		}
		int la,lb;
		cin >> la >> lb;
		if(a[la]==INT_MAX || b[lb]==INT_MAX)
			cout << "GG" << endl;
		else
		{
			int mina=a[la];
			for(++la;la<M;++la)
				if(a[la]<mina)
					mina = a[la];
			int minb=b[lb];
			for(++lb;lb<M;++lb)
				if(b[lb]<minb)
					minb = b[lb];
			if(mina +minb <=n)
				cout << mina + minb << endl ;
			else
				cout << "GG" << endl ;
		}
	};
	return 0;
};
/*
22 min
*/
