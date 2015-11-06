#include<bits/stdc++.h>
#define ll long long 
#define M 100010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define FORE(i,a,n) for(int i=a;i<=n;++i)
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

char brain[250];
int ptr=0;
VI v;

struct trie
{
	trie *w[200];
	int val;
	trie():val(0){ FR(i,200)w[i]=NULL;}
}*root;

void init()
{
	string words[9]={
"(>OwO)>u~(/OwO)/nya~",
"(>OwO)>u~!(/OwO)/nya~!",
"(>OwO)>u~!!(/OwO)/nya~!!",
"(>OwO)>u~!!!(/OwO)/nya~!!!",
"CHAOS CHAOS!",
"I WANNA CHAOS!",
"Let's\\(OwO)/nya~",
" ",
"\n"};
	/*FR(i,9)
	{	
		FR(j,words[i].size())
			cout << words[i][j] <<" ";
		cout << endl;
	};*/
	root = new trie();
	FR(i,9)
	{
		trie *now = root;	
		FR(j,words[i].size())
		{
			if(now->w[words[i][j]] == NULL)
				now->w[words[i][j]] = new trie();
			now = now->w[words[i][j]];
		}
		now->val = i+1;
	}	
	FR(i,250)
		brain[i]=0;
	ptr=0;
	v = VI();
}

/*void doing()
{
	std::stack<int> s;
	std::stack<int> act;
	act.push(1);
	int more=0;
	FR(i,v.size())
		if(act.top()==1 || (more==0 && v[i]==6))
		switch(v[i])
		{
			case 1:++ptr;break;
			case 2:++brain[ptr];break;
			case 3:--ptr;break;
			case 4:--brain[ptr];break;
			case 5:
				s.push(i);
				if(brain[ptr]==0)
					if(act.top()==1)
						act.push(0);
				else
					act.push(1);
				break;
			case 6:
				if(act.top()==0)
				{
					act.pop();
					s.pop();
				}
				else
				{
					i = s.top();
					act.top()=2;
				}	
				break;	
			case 7:putchar(brain[ptr]);break;
			case 8:break;
			case 9:break;
			
		}
		else if(more)
		{
			if(v[i]==5)
				++more;
			else
		}
}*/
int doing(int &now,int act)
{
	if(act==0)
	{
		int more=1;
		for(now;now<v.size();++now)
		{
		
			if(v[now]==5)
				++more;
			else if(v[now]==6)
				--more;
			if(more==0)
				return 0;
		};				
		return 0;
	}
	for(now;now<v.size();++now)
		switch(v[now])
		{
			case 1:++ptr;break;
			case 2:++brain[ptr];break;
			case 3:--ptr;break;
			case 4:--brain[ptr];break;
			case 5:
				{
				int store =	++now;
				while( doing(now,brain[ptr]) )
					now = store;
				}
				break;
			case 6:	
				return 1;
			case 7:putchar(brain[ptr]);break;
			case 8:break;
			case 9:break;			
		}
}


int main()
{
	//std::ios::sync_with_stdio(false);std::cin.tie(0); 

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	

	init();
	trie *now =root;
	char c;
	while((c=getchar())>0  )
	{
		/*if(now ==NULL)
			puts("ERROR");*/
		if(now->w[c])
			now = now->w[c];
		/*putchar(c);
		cout <<(int)c <<" ";*/
		
		if(now->val)
		{
			if(now->val<=7)
				v.pb(now->val);
			now = root;
			//cout << "OK\n";
		}
	};
	int i=0;
	doing(i,1);
}
	return 0;
};
/*
debug for the EOF
because the if sentence can solve that
something strange happened



*/
