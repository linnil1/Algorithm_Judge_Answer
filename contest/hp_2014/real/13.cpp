#include<stdio.h>
#include<string.h>

int main()
{
	char s[1000];
	gets(s);
	
	int i,len=strlen(s);
	int res[len+1];
	
	memset(res,0,sizeof(res));
	
	for(i=0;i<len;i++){
		if(s[i]==' ')s[i]=0;
		else{
			res[i]=26-(s[i]-'A'+1)+1;	
		}
		printf("%d\n",res[i]);
	}
	for(i=1;i<len;i++){
		//if(res[i-1]==0)res[i-1]=0;
		//else{
			if(res[i]>res[i-1])res[i]=26-(res[i]-res[i-1])+1;
			else if(res[i]<res[i-1])res[i]=res[i-1]-res[i];
			else res[i]=res[i-1];
		//}
	}
	for(i=0;i<len;i++){
		if(res[i])printf("%c\n",res[i]+'A'-1);
		else putchar(' ');
	}
	putchar('\n');
	return 0;
}

