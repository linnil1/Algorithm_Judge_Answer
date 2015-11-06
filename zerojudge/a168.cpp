#include<bits/stdc++.h>
#define ll long long 
#define M 20010
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
using std::cin;using std::cout;using std::endl;
using std::string;using std::sort;using std::swap;
#define MAX std::max
#define MAXX(a,b,c) MAX(MAX(a,b),c)
#define MIN std::min
#define MINN(a,b,c) MIN(MIN(a,b),c)

#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

struct sa_da {
	static const int MM = 30100; 
	
	char ch[MM];int n ;
	void IN(char *c){		
		strcpy(ch,c);
		n = strlen(ch);		
		for(int i=3*n;i>=0;--i)
			r[i]=0;
	}	
	
	int sa[MM],da[MM];	
	int r[MM],gap;
	bool sacmp(int a,int b){
		if( r[a] != r[b] )
			return  r[a] < r[b] ;
		return r[a+gap] < r[b+gap] ;
	}
	
	void gosa()
	{				
		for(int i=0;i<n;++i){	
			r[i]=ch[i];
			sa[i] = i ;
		}
		for(gap=1;;gap<<=1){
			std::sort(sa,sa+n,[=](int a,int b){return this->sacmp(a,b);});
			int ma[n] ;
			for(int i=0;i<n;++i)
				ma[i] = r[sa[i]]*MM + (sa[i]+gap<n ? r[sa[i]+gap] : 0 );
			
			if(gap >=n)
				break;
			for(int i=1,rank=r[sa[0]]=1;i<n;++i)
				if( ma[i-1] == ma[i] )
					r[sa[i]] = rank;
				else
					r[sa[i]] = ++rank ;		
			/*for(int i=0;i<n;++i)
				printf("%d %d\n",sa[i],r[i]);
			puts("");		*/
		}				
	}
	void goda()
	{		
		int r[M];
		FR(i,n)
			r[sa[i]]=i;
		FR(i,n)
			if(r[i]==0)
				da[0]=0;
			else 
			{
				int len = i==0 ? 0 : MAX(0,da[r[i-1]]-1);
				while(ch[i+len]==ch[sa[r[i]-1]+len])
					++len ;
				da[r[i]] = len ;
			}
	}
}sada;


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	char c[M];
	(~scanf("%s",c));{
		sada.IN(c);
		sada.gosa();
		sada.goda();
		
		int max=0;
		FR(i,sada.n)
			max = MAX(max,sada.da[i]);
		
		printf("%d\n",max);
		
	};
}
	return 0;
};
/*






*/
