#include<stdio.h>
#include<string.h>
//A2 D1 D2 D3 C1 B2 B1 B1 C4 C2
int main()
{
	char s[1000];
	gets(s);
	int i,len=strlen(s),ans=0,ex[11]={};
	
	for(i=0;i<len;i++){
		if(s[i]=='A'){
			if(s[i+1]=='1'){ans+=18;++ex[0];}
			else {ans+=25;++ex[1];}
		}
		else if(s[i]=='B'){
			if(s[i+1]=='1'){ans+=25;++ex[2];}
			else {ans+=30;++ex[3];}
		}
		else if(s[i]=='C'){
			if(s[i+1]=='1'){ans+=28;++ex[4];}
			else if(s[i+1]=='2'){ans+=30;++ex[5];}
			else if(s[i+1]=='3'){ans+=35;++ex[6];}
			else {ans+=25;++ex[7];}
		}
		else if(s[i]=='D'){
			if(s[i+1]=='1'){ans+=15;++ex[8];}
			else if(s[i+1]=='2'){ans+=20;++ex[9];}
			else {ans+=30;++ex[10];}
		}
	}
	
	int a=ex[4]+ex[5]+ex[6]+ex[7];
	if(a&&ex[5])ans-=(ex[5]>a?a:ex[5])*5;
	if(ex[3]&&ex[10])ans-=(ex[3]>ex[10]?ex[10]:ex[3])*11;
	printf("%d\n",ans);
	return 0;
}

