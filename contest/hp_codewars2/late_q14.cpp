#include<bits/stdc++.h>
#define ll long long 
//#define yesT
#define M 100000
#define MOD 1000000007
#define mp std::make_pair
#define pb push_back
#define pii std::pair<int,int>
#define qi std::queue<int>
#define vi std::vector<int>
#define string std::string

struct item
{
	string name;
	std::vector<string>	v;
	int time,depen;
	
};

std::map<string , int> m;
int now;
item arr[100000];
int make(string &a,std::vector<string> vs = std::vector<string>() )
{
	if( m.count(a) )
		return m[a];
		
	m[a]=now;
	arr[now].v = vs ;
	arr[now].name= a;
	arr[now].time= arr[now].depen = 0;
	return now++;			
}

void dfsinstall(string &a,int dep)
{
	int now = make(a);
	if(dep)
		arr[now].depen++;
	if(arr[now].time)
		return ;
	arr[now].time=1;
	
	for(string s:arr[now].v)
		dfsinstall(s,dep+1);
}
void dfsremove(string &a,int dep)
{
	int now = make(a);	
	if(dep)
		--arr[now].depen;
	
	if(arr[now].depen)
		return ;		
		
	if(arr[now].time)
		arr[now].time=0;
	else
		return ;
	for(string s:arr[now].v)
		dfsremove(s,dep+1);	
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
	
	m= std::map<string,int>();
	now=1;
	
	string a,b;
	while(std::cin>>a && a!="END")
	#endif	
	{		
		if(a=="DEPEND")
		{			
			string name;
			std::cin>>name;			
			std::getline(std::cin , b);			
			std::vector<string> vs;			
			//std::cout<<"!!"<<b<<"\n";					
			int i,s;
			for(i=0;i<b.size();++i)
				if(isalpha(b[i]))
					break;
			for(s=i;i<b.size()+1;++i)
				if(i==b.size( ) || !isalpha(b[i]))
				{
					if(s==i)
						{++s;continue;}
					string c = string(b.begin()+s,b.begin()+i) ;
					//std::cout<<":::::::"<<c<<"\n";					
					vs.pb( c );								
					s=i+1;
				}		
				
			make(name,vs);	
		}
		else if(a=="INSTALL")
		{
			std::cin>>b;	
			dfsinstall(b,0);			
		}
		else if(a=="REMOVE")
		{
			std::cin>>b;
			dfsremove(b,0);
		}
		else if(a=="LIST")
		{
			for(int i=0;i<now;++i)
				if(arr[i].time)
					std::cout<< arr[i].name<<"\n";	//the answer wrong?		
		}
		/*for(int i=1;i<now;++i)
			if(arr[i].time)
				std::cout<< "?"<<arr[i].name<<"\n";*/
	};
	return 0;
};
/*
DEPEND EMAIL TCPIP ETHERNET
DEPEND TCPIP ETHERNET
DEPEND DNS TCPIP ETHERNET
DEPEND BROWSER TCPIP HTTP
INSTALL ETHERNET
INSTALL EMAIL
INSTALL SNMP
REMOVE ETHERNET
INSTALL BROWSER
INSTALL DNS
REMOVE EMAIL
REMOVE ETHERNET
REMOVE DNS
REMOVE ETHERNET
INSTALL ETHERNET
REMOVE TCPIP
REMOVE BROWSER
REMOVE TCPIP
LIST
END

*/
