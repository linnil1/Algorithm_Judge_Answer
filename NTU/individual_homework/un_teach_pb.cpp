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

int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
	int times=INT_MAX;//scanf("%d",&times);
	int n;
	while(times-- && ~scanf("%d",&n)){		
		 
	};

	return 0;
};
/*
林祥瑞
算機率用浮點數這樣做不怕炸
而且有些值可以先建表加速
學弟可以想一下機率的公式
好比說
某A牌在100張的堆有10個
那兩次都抽到A牌的機率就會是
(10/100)^2
那抽到兩次一樣的牌
可以是兩次抽A、抽B…的總和
照對稱性質
兩次抽A和兩次抽B的機率要一樣大
所以算一次就好
至於兩次抽A的機率
可以用條件機率分case算
比如 P(共1個A) P(兩次抽A | 共1個A)
這部分的計算可以先透過建表列算式加速
繼續算到總共抽到min(N, M)個A情況下抽兩次A的機率
最後把機率總和起來就是解
加起來 還要乘一個n嗎 (對稱) ?
你說的是
P(兩次抽A1) + P(兩次抽A2) ... P(兩次抽An)  
 = P(兩次抽A1) * N
吧？
P(兩次抽A1) = P(1個A) * P(兩次抽A | 1個A) + P(2個A) * P(兩次抽A | 2個A) + ...


*/
