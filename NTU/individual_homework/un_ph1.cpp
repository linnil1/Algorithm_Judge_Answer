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

int ha = 1483 , hm = 28657;
struct chash{
	char c[300];
	int v[300];
};
int hash(chash &h){
	h.v[0]=0;
	for(int i=0;h.c[i];++i)
		h.v[i+1] =( h.v[i]*ha + h.c[i] )%hm ;
}


chash base;
int val[300],len;

int pow(int t){
	int sum=0,a=ha;
	while(t){
		if(t&1)
			sum = sum * a % hm;
		a = a*a%hm;
	}
	return sum;
}

int ghash(chash &h,int a,int l){
	return (( h.v[a+l]*pow(l)%hm - h.v[a] )%hm + hm) %hm ; 
}

void com(int now , chash &c , int& k){
	for(int i=0;c.c[i];++i)
		if(base.c[now] == c.c[i] )
			while(k && ghash(base,now,k)==ghash(c,i,k))
				--k;
			
}

bool whob(int a,int b,int l){
	FR(i,l)
		if(base.c[a+i] < base.c[b+i])
			return 0;
		else if(base.c[a+i] > base.c[b+i])
			return 1;
	return 1 ;
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(~scanf("%d%s",&n,base.c)){		
		hash(base);
		len = strlen(base.c);
		for(int i=0;i<len;++i)
			val[i] = len-i;
			
		while(--n){
			chash t;
			scanf("%s",t.c);
			hash(t);
			FR(i,len)
				if(val[i]){
					com(i,t,val[i]);
				}			
		}
		int max=0,where=-1;
		FR(i,len)
			if(val[i] && val[i] >= max  )
				if(val[i]!=max || whb(where,i,max) ){				
					where = i;
					max = val[i];
				}
		if(where==-1)
			printf("IDENTITY LOST");
		else
			FR(max)
				printf("%c",base.c[where+i]);
		puts("");
				
		
		
	};
}
	return 0;
};
/*






*/
