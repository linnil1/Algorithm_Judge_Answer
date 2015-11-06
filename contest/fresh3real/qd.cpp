#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_pair
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


#ifndef EVAL
int Answer(int N,int P,int *H,int *L,int *R,int *V);
int main()
{
	const int maxN = 1000000;
	const int maxP = 1000000;
	int *H = new int[maxN];
	int *L = new int[maxP];
	int *R = new int[maxP];
	int *V = new int[maxP];
	int N,P;
	while( cin>>N>>P )
	{
		for(int i=0;i<N;++i)
			cin>>H[i];
		for(int i=0;i<P;++i)
			cin>>L[i]>>R[i]>>V[i];
		cout<<Answer(N,P,H,L,R,V)<<endl;
	}
}
#endif
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*Write Your Program Here*/
/*Notice: You should include header for youself*/

struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};
	
	bool operator < (const xy &b)const
	{
		return x<b.x;
	}
};

int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
	ARR(arr,N)
		arr[i]=0;
	FR(i,P)
	{
		arr[ L[i]-1 ] +=  V[i];
		arr[ R[i]   ] += -V[i]; 
	}
	int sum=0,ma=INT_MIN ,mi= INT_MAX;
	FR(i,N)
	{
		sum += arr[i];
		H[i]+=sum;
		if(H[i]>ma)
			ma=H[i];
		if(H[i]<mi)
			mi=H[i];
		//cout << H[i] << " ";
	}
	
	return ma-mi;
}
/*
24min slow
the right bounded problem
11min debug 
don't use the nlogn sort 
*/
