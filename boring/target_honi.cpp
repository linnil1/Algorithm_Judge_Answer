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

using std::cin;using std::cout;using std::string;
using std::sort;using std::endl;using std::swap;
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

int o[25],e[25],sum;


void honoi(int now,int a,int b,int c,int k=1){	
	if(now==-1)
		return ;
	if(o[now]==c ){
		honoi(now-1,b,a,c);
		return ;
	}
	else if(o[now]==b){
		honoi(now-1,b,c,a);
		++sum;
		printf("ring %d : %c -> %c\n",now+1,b-1+'a',c-1+'a');
		o[now]=c;
		honoi(now-1,a,b,c);
	}
	else{
		honoi(now-1,a,c,b);
		++sum;
		printf("ring %d : %c -> %c\n",now+1,a-1+'a',c-1+'a');		
		o[now]=c;
		if(k)
			honoi(now-1,b,a,c);
	}
}


int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	int n;
	while(cin >> n){
		FR(i,n)cin>>o[i];
		FR(i,n)cin>>e[i];
		sum=0;
		BFR(i,n)
			if(o[i]!=e[i])
				honoi(i,o[i],6-o[i]-e[i],e[i],0);
		/*BFR(i,n)
			if(o[i]!=e[i]){
				honoi(i,o[i],6-o[i]-e[i],e[i],0);
				++sum;
				printf("ring %d : %c -> %c\n",i+1,o[i]-1+'a',e[i]-1+'a');
			}*/
		printf("%d\n",sum);
	};
}
	return 0;
};
/*






*/
