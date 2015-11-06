#include<cstdio>
#include<algorithm>
#include<stack>
char c[3000000];
int stack[3000000];
int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
        scanf("%s",c);
        int s=0;
        for(int i=0;c[i];++i)
        {
        	stack[s++]=c[i];
        	while(s>=2 && stack[s-1]==stack[s-2])
        		s-=2;
        };
        if(s==0)
        	puts("Yes");
        else
        	puts("No");
        
    }
    return 0;
}
