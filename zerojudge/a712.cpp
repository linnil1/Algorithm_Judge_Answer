#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;


string gonum(string &a)
{
	int now=0;
	FR(i,a.size())
		if(isdigit(a[i]))
			a[now++]=a[i];
		else if(isalpha(a[i]))
			a[now++]=(a[i]-'A'-(a[i]>='Q'))/3+'2';
	a.resize(now);
	//cout << a << "!!\n";
	return a;
}

void stand(string a)
{
	FR(i,a.size())
	{
		if(i==3)
			cout<<'-';
		cout << a[i];
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int n;
	while(cin >> n)
	{
		map<string,int >m ;
		FR(i,n)
		{
			string c;
			cin >>c;
			m[gonum(c)]++;
		}
		int time=0;
		for(auto i:m)
			if(i.sd>1)
				stand(i.ft),
				cout << " " << i.sd << endl,
				++time;
		if(time==0)
			cout << "No duplicates. \n";
	};
}
	return 0;
};
/*
17min ok
*/
