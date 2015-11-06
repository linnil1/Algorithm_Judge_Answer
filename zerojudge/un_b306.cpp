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
#define MANN(a,b,c) MIN(MIN(a,b),c)


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

char m[55][55];
char map[55][55];


void todoor(int n)
{
	memset(map,'.',sizeof(map));
	int end = 3*n-2;
	FR(i,3*n)
		map[i][end]='\0';
	
	FR(i,n)
		map[0][i]		=map[n/2][i]		=map[n-1][i]=
		map[0][end-i-1]	=map[n/2][end-i-1]	=map[n-1][end-i-1]='x';
	FR(i,2*n-2)
		map[i][0]=map[i][end-1]='x';
	FR(i,n)
		map[i][n-1]=map[i][end-n]='x';
	/*FR(i,2*n-2)
		cout << map[i] << endl;*/
	
}

bool go(int x,int y,int n)
{
	int r = 2*n-2, c= 3*n-2;
	x=x-r+1 ; y=y-c+1;
	if(x<0 || y<0)
		return 0;
	todoor(n);
	FR(i,r)
		FR(j,c)
			if(map[i][j]!=m[x+i][y+j])
				return 0;
	return 1;
}

bool goinv(int x,int y,int n)
{
	int r = 2*n-2, c= 3*n-2;
	x=x-r+1 ; y=y-c+1;
	if(x<0 || y<0)
		return 0;
	todoor(n);
	FR(i,r)
		FR(j,c)
			if(map[r-1-i][j]!=m[x+i][y+j])
				return 0;
	return 1;
}

bool goturnl(int x,int y,int n)
{
	int r = 2*n-2, c= 3*n-2;
	y=y-r+1 ; x=x-c+1;
	if(x<0 || y<0)
		return 0;
	todoor(n);
	FR(i,r)
		FR(j,c)
			if(map[i][j]!=m[x+j][y+i])
				return 0;
	return 1;
}

bool goturnr(int x,int y,int n)
{
	int r = 2*n-2, c= 3*n-2;
	y=y-r+1 ; x=x-c+1;
	if(x<0 || y<0)
		return 0;
	todoor(n);
	FR(i,r)
		FR(j,c)
			if(map[i][j]!=m[x+j][y+r-1-i])
				return 0;
	return 1;
}

void find(int a,int b)
{
	int max=0,all=0;
	FOR(i,7,a)
		FOR(j,12,b)
			if(m[i][j]=='x')
			{
				for(int q=5;q<=17;q+=2)
					if(go(i,j,q) || goinv(i,j,q) || goturnl(i,j,q) || goturnr(i,j,q))
					{
						if(max < q)
							max = q;
						++all;
					}
			}
	if(all==0)
		cout << "0\n";
	else
		cout << all << " " << max << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	int len=0;
	//while(cin >> len)todoor(len);
	while(cin >> m[len++]);
	
	find(len,50);
}
	return 0;
};
/*
xxxxx...xxxxxxxxxx...xxxxx.
x...x...x...xx...x...x...x.
xxxxx...xxxxxxxxxx...xxxxx.
x...x...x...xx...x...x...x.
xxxxx...xxxxxxxxxx...xxxxx.
x...........xx...........x.
x...........xx...........x.
x...........xx...........x.
xxxxx...xxxxxxxxxx...xxxxx.
x...x...x...xx...x...x...x.
xxxxx...xxxxxxxxxx...xxxxx.
x...x...x...xx...x...x...x.
xxxxx...xxxxxxxxxx...xxxxx.
x...........xx...........x.
x...........xx...........x.
x...........xx...........x.
xxxxxxx.....xxxxxxx........
x.....x.....x.....x........
x.....x.....x.....x........
xxxxxxx.....xxxxxxx........
x.....x.....x.....x........
x.....x.....x.....x........
xxxxxxx.....xxxxxxx........
x.................x........
x.................x........
x.................x........
x.................x........
x.................x........

*/
