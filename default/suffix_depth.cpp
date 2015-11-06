int sa[M],da[M];
struct word
{
	int w;
	word *n;
	word(){	};
	word(int _w):w(_w),n(NULL){};
};

void sasort(char *ch,int n)
{	
	word *f[27],*b[27],*tf,*tb;
	FR(i,n)
		ch[i]=ch[i]-'a'+1,
		ch[n+i]=0;
		
	for(int i=0;i<=26;++i)
		f[i]=b[i]=NULL ;	
	tf = tb = new word(0);
	FOR(i,1,n)
	{	
		tb -> n = new word(i);
		tb = tb->n;
	};
	BFR(i,n)
	{
		//dispute;
		while( tf != NULL )
		{
			int now=ch[tf->w+i];
			if(f[now]==NULL)
				f[now]=b[now]= tf;
			else
			{
				b[now]->n = tf ;
				b[now] = b[now]->n ;
			}
			tf = tf->n ;
			b[now]->n = NULL;
		}
		//merge
		tf = tb = NULL ;
		for(int j=0;j<=26;++j)
		{
			if(f[j]!=NULL)
				if(tf == NULL)
				{
					tf = f[j];
					tb = b[j];
				}
				else
				{
					tb->n = f[j];
					tb = b[j];
				};
			f[j]=b[j]=NULL;
		}
	}
	//to suffix array
	int i=0;
	while(tf != NULL)
	{
		sa[i++] = tf->w ;
		tf = tf->n;
	}
	/*FR(i,n)
		PR(sa[i]);*/
}
void satoda(char*ch ,int n)
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
