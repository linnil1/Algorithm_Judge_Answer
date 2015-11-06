#include<bits/stdc++.h>
#define ll long long 
#define M 300
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

ll ha = 42737 , hm = 1442968193;

int val[M],len;
std::set<ll> s;
char bc[M];
ll b[M][M];

int basehash(){
	FR(i,len){
		b[i][i+1] = bc[i] ;
		FOR(j,i+1,len)
			b[i][j+1] = ( b[i][j]*ha + (ll)bc[j] )%hm ;
	}
}


void gohash(char *c){	
	s = std::set<ll>();
	for(int i=0;c[i];++i){
		ll sum=0;
		for(int j=i;c[j];++j){		
			sum =( sum*ha + (ll)c[j] )%hm;
			s.insert(sum);
		}
	}		
}

/*
ll pow(int t){
	ll sum=0,a=ha;
	while(t){
		if(t&1)
			sum = sum * a % hm;
		a = a*a%hm;
		t>>=1;
	}
	return sum;
}

int hnum(int a,int l){
	return (( bv[a+l] - bv[a]*pow(l)%hm )%hm + hm) %hm ; 
}*/
void strict(){
	FR(i,len){
		int &k = val[i];
		while(k && !s.count( b[i][i+k]  ) )
			--k;
	}
}



bool who(int a,int b,int l){
	FR(i,l)
		if(bc[a+i] < bc[b+i])
			return 0;
		else if(bc[a+i] > bc[b+i])
			return 1;
	return 0 ;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d",&n)&&n){
		scanf("%s",bc);
		len =strlen(bc);
		
		basehash();
		FR(i,len)		
			val[i] = len-i ; 	
		
		while(--n){
			char c[M];
			scanf("%s",c);
			gohash(c);
			strict();
			//show val
			/*FR(i,len)
				printf("%d ",val[i]);
			puts("");*/
		}
				
		
		
		int where=-1,max=0;
		FR(i,len)
			if(val[i] && val[i] >= max  )
				if(val[i]>max || who(where,i,max) ){				
					where = i;
					max = val[i];
				}
		if(where==-1)
			printf("IDENTITY LOST");
		else
			FR(i,max)
				printf("%c",bc[where+i]);
		puts("");
				
		
		
	};
}
	return 0;
};
/*






*/
