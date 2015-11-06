
struct kmp{
	static const int MM = 100100;
	char ch[MM] ;int n;
	int v[MM];
	void IN(char *c){
		strcpy(ch,c);
		n = strlen(c);
		gokmp();	
	}
	void gokmp(){
		for(int i=1,now=v[0]=0;i<n;++i){
			while(now && ch[i]!=ch[now])
				now = v[now-1];
			if(ch[i]==ch[now])
				++now ;
			v[i] = now ; 
		}
	}
	int cmp(char *c){
		int now=0;
		for(int i=0;c[i];++i){
			while(now && c[i]!=ch[now])
				now = v[now-1];
			if(ch[now]==c[i])
				++now;
			if(now==n)
				return i-n+1;
		}
		return 0;
	}
	
};
