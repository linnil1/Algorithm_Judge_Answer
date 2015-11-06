
template <class T>
inline int IN(T &a)
{
	static char c,neg;
	while((c=getchar())<'-')
		if(c== EOF)
			return EOF;
			
	a = (neg= c=='-') ? 0 : c-'0' ;
	while((c=getchar())>='0')
		a = a*10+c-'0';
	a = neg?-a:a;
	return 1;
}

int digit[100],digs;
void dig(int a,int base = 10 )
{
	digs=0;
	while(a)
	{
		dig[digs++] = a % base ;
		a /= base ;
	}
	if(digs==0)
		printf("0");
	for(int i=digs-1;i>=0;--i)
		printf("%d ",dig[i]);
	puts("");
}

int toscat(int *arr,int &n){
	std::map<int,int> m;
	for(int i=0;i<n;++i)
		m[arr[i]];
	int len=1;
	for(auto &i : m )
		i.sd = len++;
	for(int i=0;i<n;++i)
		arr[i] = m[arr[i]];
	return len;
}

int pow(int a,int b)//a^b
{
	int sum=1;
	while(b)
	{
		if(b&1)
			sum *= a;
		b>>=1;
		a*=a;
	}
	return sum;
}
	
