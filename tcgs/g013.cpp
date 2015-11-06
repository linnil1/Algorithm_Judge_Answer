//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<ctype.h>
#include<string>
#include<algorithm>

#define ll long long 
#define yesT
#define M 10000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>

using std::string;

string order[12]={"hat","earring","sword","bow","bastinado",
"targe","glove","clothes","cape","pant","skirt","shoe"};
int strord[12]={0,0,1,1,1,1,1,2,2,3,3,4};
string color[8]={"W","P","B","R","Y","G","K","U"};

struct art
{
	string name,com;
	int order,color,lev;
	
	bool operator<(const art &a)const
	{
		/*return std::tie(order,color,lev,name) < 
			std::tie(a.order,a.color,a.lev,a.name);*/
		if(strord[order] != strord[a.order])
			return strord[order] < strord[a.order];
		
		if(order !=a.order)
			return order < a.order;	
		if(color != a.color)
			return color < a.color;	
		if(color==7 && lev != a.lev)
			return lev<a.lev;
			
		
		return com<a.com;
			
	}
};
int find(string *a,int size,string &b)
{
	for(int i=0;i<size;++i)
		if(a[i]==b)
			return i;
}

void pr(string &a)
{
	//std::cout<< a<< "\n";
	for(int i=0,t=0;i<a.size()&&t<2;++i)
		if(isupper(a[i]))
			printf("%c",a[i]),++t;
}

string turn(string a)
{
	for(int i=0;i<a.size();++i)
		a[i] = (tolower(a[i])-'a')*2+ (!!islower(a[i]));
	return a;	
}

int main()
{
	//freopen("in.txt","r",stdin);
	/*string a,b;
	while(std::cin>>a>>b)
		printf("%d\n",turn(a)<turn(b));*/
	#ifdef yesT
	int T;
	scanf("%d",&T);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{
		int n;
		scanf("%d",&n);
		if(n==0)
		{
			puts("--------");
			continue;
		}
			
		art arr[n];
		for(int i=0;i<n;++i)
		{
			string b,c;
			std::cin>>arr[i].name>>b>>c>>arr[i].lev;
			
			arr[i].order = find(order,13,b);
			arr[i].color = find(color,8,c);
			arr[i].com = turn (arr[i].name);			
			
		}
		
		std::sort(arr,arr+n);
		int wh=4;
		for(int i=0,now=-1;i<n;++i)
		{
			if(strord[arr[i].order] !=now )
			{
				now = strord[arr[i].order] ;
				while(wh++ <4)
					printf("__");
				if(i)
					puts("");
				wh=0;				
			}
			if(wh++==4)
			{
				wh=1;
				puts("");
			}
			pr(arr[i].name);
		}
		while(wh++ <4)
			printf("__");
		puts("\n--------");
		
	};
	return 0;
};
/*

*/
