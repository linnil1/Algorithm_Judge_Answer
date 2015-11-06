#include<bits/stdc++.h>
#define ll long long 
#define M 100100
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

int n;
int cal(int a,int ba){
	if(ba)
		return a==0 ? 1 : a ;
	return a<=1 ? a : a-1 ; 			
}

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 
	ll nine[20] ;
	nine[0]=1;
	for(int i=1;i<20;++i)
		nine[i] = nine[i-1]*9;
	
	ll one[20];
	one[0]=one[1]=1;
	for(int i=2;i<20;++i){
		one[i]=0;
		for(int j=0;j<i-1;++j)
			one[i] += one[j] * nine[i-j-1] ;		
	}
	
	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	char c[25];
	while(times-- && ~scanf("%s",c)){	
		for(n=0;c[n];++n)
			c[n]-='0';
		
		ll sum=0;
		//without 1
		FR(i,n){
			sum += cal(c[i],i==n-1) * nine[n-i-1] ;
			if(c[i]==1)
				break;
		}
		printf("sum: %lld\n",sum);	
		//must has 1 on i pos
		FR(i,n){
			if(c[i]==0)//cant
				continue;
			if(c[i]>1){ // either 0 or 1 will not full
				ll f=0;
				FR(j,i){
					f += cal(c[i],j==i-1) * nine[i-j-1] ;
					if(c[i]==1)
						break;
				};				
				if(f==0)f=1;
				
				sum += f*( one[n-i] );				
				continue;
			}	
				
			ll now=0;ll all=1;//is it full ?
			FR(j,i){
				now += cal(c[i],0) * nine[i-j] ;
				if(c[i]==1){
					all=0;break;
				}
			};
			sum += now*(one[n-i]);
			if(now==0)now=1;
			
			if(all==0){//it is not full
				
				continue;
			}			
			/*it is full*/
			all=0;
			int app=i ; 
			FOR(j,i+1,n)
				if( j-app <=1 )
					if(c[j]>=1){
						all +=  one[n-j+1];
						break;
					}
					else;
				else if(c[j]==1)
					all+= one[n-j+1] ,
					app = j ;
				else if(c[i]!=0){
				
					all+= one[n-j+1] + one[n-j];
					break;
				}
			if(all==0)
				all=1;
			printf("%d!%d!\n",now,all);			
			printf("sum: %lld\n",sum);		
			sum+=now*all;
			printf("sum: %lld\n",sum);
			
		}
		printf("%lld\n",sum);
		
		
		
		
	};

	return 0;
};
/*






*/
