//the // is the ´`Àô 
struct sa_da {
	static const int MM = 30100; 
	
	char ch[MM];int n ;
	void IN(char *c,int need_da=0){		
		strcpy(ch,c);
		n = strlen(ch);		
		for(int i=3*n;i>=0;--i)//
			r[i]=0;//
		gosa();
		if(need_da)
			goda();
	}	
	
	int sa[MM],da[MM];	
	int r[MM],gap;
	bool sacmp(int a,int b){
		if( r[a] != r[b] )
			return  r[a] < r[b] ;
		return r[a+gap] < r[b+gap] ;
		//return r[(a+gap)%n] < r[(b+gap)%n] ;
	}
	
	void gosa()
	{				
		for(int i=0;i<n;++i){	
			r[i]=ch[i];
			sa[i] = i ;
		}
		for(gap=1;;gap<<=1){
			std::sort(sa,sa+n,[=](int a,int b){return this->sacmp(a,b);});
			int ma[n] ;
			for(int i=0;i<n;++i)
				ma[i] = r[sa[i]]*MM + (sa[i]+gap<n ? r[sa[i]+gap] : 0 );
			//  ma[i] = r[sa[i]]*MM +  r[(sa[i]+gap)%n];
			if(gap >=n)
				break;
			for(int i=1,rank=r[sa[0]]=1;i<n;++i)
				if( ma[i-1] == ma[i] )
					r[sa[i]] = rank;
				else
					r[sa[i]] = ++rank ;		
			/*for(int i=0;i<n;++i)
				printf("%d %d\n",sa[i],r[i]);
			puts("");		*/
		}				
	}
	void goda()
	{		
		int r[M];
		FR(i,n)
			r[sa[i]]=i;
		FR(i,n)
			if(r[i]==0)
				da[0]=0;
			else 
			{
				int len = i==0 ? 0 : MAX(0,da[r[i-1]]-1);
				while(ch[i+len]==ch[sa[r[i]-1]+len])
					++len ;
				da[r[i]] = len ;
			}
	}
}sada;

