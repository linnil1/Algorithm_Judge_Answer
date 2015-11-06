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

int sa[M],da[M];
struct word
{
	int w;
	word *n;
	word(){	};
	word(int _w):w(_w),n(NULL){};
};

void sasort(char *tch,int n)
{	
	char ch[2*n+3];
	FR(i,n)
		ch[i]=tch[i];
		
	word *f[10],*b[10],*tf,*tb;
	FR(i,n)
		ch[i]=ch[i]-'0',
		ch[n+i]=ch[i];
		
	for(int i=0;i<=10;++i)
		f[i]=b[i]=NULL ;	
	tf = tb = new word(0);
	FOR(i,1,n)
	{	
		tb -> n = new word(i);
		tb = tb->n;
	};
	BFR(i,n)
	{
		//dispute;
		while( tf != NULL )
		{
			int now=ch[tf->w+i];
			if(f[now]==NULL)
				f[now]=b[now]= tf;
			else
			{
				b[now]->n = tf ;
				b[now] = b[now]->n ;
			}
			tf = tf->n ;
			b[now]->n = NULL;
		}
		//merge
		tf = tb = NULL ;
		for(int j=0;j<=10;++j)
		{
			if(f[j]!=NULL)
				if(tf == NULL)
				{
					tf = f[j];
					tb = b[j];
				}
				else
				{
					tb->n = f[j];
					tb = b[j];
				};
			f[j]=b[j]=NULL;
		}
	}
	//to suffix array
	int i=0;
	sa[0] = tf->w ; 
	/*while(tf != NULL)
	{
		sa[i++] = tf->w ;
		tf = tf->n;
	}*/
	/*FR(i,n)
		PR(sa[i]);*/
}

char a[M],b[M];
int main(){
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ;for(int cases=1;cases<=times;++cases)
{	
	
	while(~scanf("%s%s",a,b)){
		int l = strlen(a);
		sasort(a,l);		
		char s[l+1],t[l+1];s[l]=t[l]='\0';
		int len=0;
		FOR(i,sa[0],l)
			s[len++] = a[i];
		FR(i,sa[0])
			s[len++] = a[i];
			
		sasort(b,l);len=0;
		FOR(i,sa[0],l)
			t[len++] = b[i];
		FR(i,sa[0])
			t[len++] = b[i];
		if(strcmp(s,t)==0){
			puts("same");
			continue;
		}
		
		
		FR(i,l/2)
			swap(b[i],b[l-1-i]);		
		sasort(b,l);len=0;
		FOR(i,sa[0],l)
			t[len++] = b[i];
		FR(i,sa[0])
			t[len++] = b[i];
		if(strcmp(s,t)==0)
			puts("same");
		else
			puts("difference");
		
		
		
	};
}
	return 0;
};
/*






*/
