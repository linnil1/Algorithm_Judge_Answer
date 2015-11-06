#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 10000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

//char word[6] = {'q','r','b','n','p','k'};

int find(char c)
{
	switch(c)
	{
		case 'q':return 9;
		case 'r':return 5;
		case 'b':return 3;
		case 'n':return 3;
		case 'p':return 1;
		case 'k':return 0;
		default : return 0;
	}
}


int main()
{
	//std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	//while(~scanf("%d",&n))
	#endif	
	{
		int w=0,b=0;
		for(int i=0;i<8;++i)
		{
			char ch[10];
			scanf("%s",ch);
			for(int i=0;ch[i];++i)
				if(isupper(ch[i]))
					w+=find(tolower(ch[i]));
				else
					b+=find(tolower(ch[i]));			
		}
		if(w>b)
			puts("White");
		else if(b>w)
			puts("Black");
		else
			puts("Draw");
	};
	return 0;
};
/*
*/
