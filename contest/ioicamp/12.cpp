#include<cstdio>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b;
        int c[100100];
        
        scanf("%d%d",&a,&b);
        c[0]=0;
		        
        for(int i=1,be=-1,t;i<=a;++i)
        {
        	scanf("%d",&t);
        	c[i]=c[i-1];
        	if(t!=be)
        	{
        		be=t;
				c[i]++;        		
        	};
        };
        int ta,tb;
        while(b--)
        {
        	scanf("%d%d",&ta,&tb);
        	if(c[ta]==c[tb])
        		printf("Y");
        	else
        		printf("N");
        };
    	puts("");
        	
        
    }
}
