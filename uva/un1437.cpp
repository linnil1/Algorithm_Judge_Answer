#include<cstdio>
#include<algorithm>
#include<cstring>
#define inf 2147483647
char 
	 b[150];
int dp[27][150][150];
int len ;

int todp(int c,int s,int e,char *ch)
{
	//printf("%c %d %d \n",c,s,e);
	if(s == e)
		return 0;
	if(s+1 == e)
		return ch[s]!=b[s];
	if(dp[c][s][e] != inf)
		return dp[c][s][e];
	
	if(ch[s] == b[s])
		return dp[c][s][e]=todp(c ,s+1 ,e ,ch);
	else if(ch[e-1] == b[e-1])
		return dp[c][s][e]=todp(c ,s ,e-1 ,ch);
		
	int now=inf;
	char tch[len];
	for(int i=0;i<len;++i)
		tch[i] = ch[i];
		
	for(int i=s;i<e;++i)
		tch[i] = b[s];
	now = std::min( now , todp(b[s]-'a'+1,s+1,e,tch)+1 );
	for(int i=s;i<e;++i)
		tch[i] = b[e-1];
	now = std::min( now , todp(b[e-1]-'a'+1,s,e-1,tch)+1 );
	
	now = std::min( now , todp(c,s+1,e,ch)+1 );
	now = std::min( now , todp(c,s,e-1,ch)+1 );
	
	return dp[c][s][e] = now;
};
int main()
{
	char a[150];
	while(~scanf("%s%s",a,b))
	{
		len=strlen(a);
		for(int k=0;k<27;++k)
		for(int i=0;i<=len;++i)
			for(int j=0;j<=len;++j)
				dp[k][i][j] = inf;
		printf("%d\n",todp(0,0,len,a));
		
	};
	return 0;
};
/*
zzzzzfzzzzz 
abcdefedcba 
abababababab 
cdcdcdcdcdcd
*/
