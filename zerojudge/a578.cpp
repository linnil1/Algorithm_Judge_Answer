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


int main()
{
	/*for(int i='a';i<='z';++i)
		if(i!='w')
			printf("scanf(\"%%d\",&%c);",i);*/
	//std::ios::sync_with_stdio(false);cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,x,y,z ,A[M],B[M],C[M];
	while(~scanf("%d",&a))
	{
		scanf("%d",&b);scanf("%d",&c);scanf("%d",&d);scanf("%d",&e);scanf
("%d",&f);scanf("%d",&g);scanf("%d",&h);scanf("%d",&i);scanf("%d",&j);scanf("%d"
,&k);scanf("%d",&l);scanf("%d",&m);scanf("%d",&n);scanf("%d",&o);scanf("%d",&p);
scanf("%d",&q);scanf("%d",&r);scanf("%d",&s);scanf("%d",&t);scanf("%d",&u);scanf
("%d",&v);scanf("%d",&x);scanf("%d",&y);scanf("%d",&z);
		A[1]=x;// xyz
		B[1]=y;
		C[1]=z;
		for(int qq=2;qq<=n;++qq)
		{
			A[qq] = min ( A[qq-1]*f+g , C[qq-1]*d + e);
			if(qq>2)
				A[qq] = min (A[qq], B[qq-2]*a+ C[qq-1]*b+c);
			
			B[qq] = C[qq-1]*k + l ;
			if(qq>2)
				B[qq] = min (B[qq] , min(A[qq-2]*m+o , C[qq-2]*h + A[qq-1]*i+j) );
			
			C[qq] = B[qq-1]*s + t ;
			if(qq>2)
				C[qq] = min (C[qq] , C[qq-2]*u+v );
			if(qq>3)
				C[qq] = min (C[qq] , A[qq-3]*p+B[qq-1]*q+r );

		}
		printf("%d %d %d\n",A[n],B[n],C[n]);
	};
}
	return 0;
};
/*
40min very slow
you have to see clearly
*/
