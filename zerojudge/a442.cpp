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

struct kmp{
	static const int MM = 100100;
	char ch[MM] ;int n;
	int v[MM];
	void IN(char *c){
		strcpy(ch,c);
		n = strlen(c);
		gokmp();	
	}
	void gokmp(){
		for(int i=1,now=v[0]=0;i<n;++i){
			while(now && ch[i]!=ch[now])
				now = v[now-1];
			if(ch[i]==ch[now])
				++now ;
			v[i] = now ; 
		}
	}
	int cmp(char *c){
		int now=0;
		for(int i=0;c[i];++i){
			while(now && c[i]!=ch[now])
				now = v[now-1];
			if(ch[now]==c[i])
				++now;
			if(now==n)
				//return i-n;
				return 1;
		}
		return 0;
	}
	
};

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	char a[M],b[M];
	while(~scanf("%s%s",a,b)){
		kmp k;
		k.IN(b);
		
		int la =strlen(a);
		a[la+la]='\0';
		FR(i,la)
			a[la+i] = a[i] ;
		
		if(k.cmp(a)){
			puts("same");
			continue;
		}
		
		FR(i,la/2)
			swap(a[i],a[la-1-i]); 
		FR(i,la)
			a[la+i] = a[i] ;
			
		if(k.cmp(a)){
			puts("same");
			continue;
		}
		else
			puts("difference");
		
	};
}
	return 0;
};
/*






*/
