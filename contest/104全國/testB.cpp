#include<cstdio>
#include<cstring>
struct big
{
	int arr[100],len;
};
big turn (char *ca)
{
	big a;
	a.len=strlen(ca);
	for(int i=0;i<a.len;++i)
		a.arr[i]=ca[a.len-1-i]-'0';
	return a;
};
big operator + (big a,big b)
{
	big c;
	int i=0,r=0;
	for(;i<a.len || i<b.len || r ; ++i)
	{
		int &t=c.arr[i];
		
		if(i>=a.len)a.arr[i]=0;
		if(i>=b.len)b.arr[i]=0;
		t=a.arr[i]+b.arr[i]+r;
		r=0;
		if(t>9)
		{
			r=t/10;
			t%=10;
		}		
	};
	c.len = i ;
	for(;c.len && !c.arr[c.len-1];--c.len);
	
	return c;
};

void out (big a)
{
	if(a.len==0)
		putchar('0');
	for(int i=a.len-1;i>=0;--i)
		printf("%d",a.arr[i]);
	puts("");
};
int main()
{
	char ca[100],cb[100];
	while(~scanf("%s%s",ca,cb))
	{
		big a=turn(ca),b=turn(cb);
		out(a+b);
	};
	return 0;
};
