#include<bits/stdc++.h>
#define ll long long 
#define yesT
#define M 10000
bool find(char *c)
{
	std::stack<char> s;
	for(int i=0;c[i];++i)
		switch(c[i])
		{
			case '(':s.push('(');break;
			case '[':s.push('[');break;
			case ')':
				if(!s.size() || s.top()!='(')
					return 0;
				s.pop();break;
			case ']':
				if(!s.size() || s.top()!='[')
					return 0;
				s.pop();break;
		}
	
	return s.size()==0;	
}
int main()
{
	//freopen("in.txt","r",stdin);
	#ifdef yesT
	char c[1000];
		
	int T;
	scanf("%d",&T);
	gets(c);
	while(T--)
	#else
	int n;
	while(~scanf("%d",&n))
	#endif	
	{		
		gets(c);
		if(find(c))
			puts("Yes");
		else
			puts("No");
	};
	return 0;
};
/*
*/
