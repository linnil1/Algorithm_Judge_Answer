#include<bits/stdc++.h>
#define lld long long int 


int ch[25][25],n,m;
int n1,m1,c1[25][25];



void pr()
{
	puts("qwe");
	for(int i=0;i<n1;++i,puts(""))
		for(int j=0;j<m1;++j)
			printf("%d ",c1[i][j]);	
	puts("zxc");
};


void turn()
{
	int m2 = n1,
		n2 = m1;
	int c2[25][25];
	for(int i=0;i<n1;++i)
		for(int j=0;j<m1;++j)
			c2[j][n1-1-i] = c1[i][j];
			
	for(int i=0;i<n2;++i)
		for(int j=0;j<m2;++j)
			c1[i][j] = c2[i][j];
	n1=n2;
	m1=m2;
};
void mirror()
{
	int c2[25][25];
	for(int i=0;i<n1;++i)
		for(int j=0;j<m1;++j)
			c2[i][j] = c1[n1-1-i][j] ;
	for(int i=0;i<n1;++i)
		for(int j=0;j<m1;++j)
			c1[i][j] = c2[i][j];
};

void sq()
{
	char ok = 1 ; 
	while(ok)
	{
		for(int i=0;i<m1 && ok;++i)
			if(c1[n1-1][i])
				ok =0 ;
		if(ok)
			--n1;
	};
};

void sqeeze()
{
	sq();
	turn();	
	sq();
	turn();	
	sq();
	turn();	
	sq();
	turn();		
	
	
};


struct disjointset
{
	int s[500],n,group;
	void init(int _n)
	{
		group = n = _n ;
		for(int i=0;i<=n;++i)
			s[i] = i ;
	};
	
	int find(int a)
	{
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b)
	{
		if(find(a)!=find(b))
		{
			s[find(a)] = find(b);
			--group;
			return 1;
		}
		else
			return 0;
	}	
	
}s;
#define M 987654361
lld topow(lld a,int b)
{
	lld sum=1;
	while(b)
	{
		if(b&1)
			sum=sum*a % M;
		a = a*a % M ;
		b>>=1;
	}
	return sum ;			
		
};
int k,num,times;
lld find()
{
	//pr();
	turn();
	if(n!=n1)
		return 0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(ch[i][j] && !c1[i][j])
				return 0;
			else if(!ch[i][j] && c1[i][j])
				return 0;
	
	s.init(num);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(ch[i][j] && c1[i][j])
				s.unin( ch[i][j] , c1[i][j] ) ;
	++times;
	
	
	//printf("%d %d\n",k,s.group);
	return topow(k,s.group);
};
/*

6
5 6 5
......
......
..##..
......
......
2 2 3
##
.#
3 3 4
###
.#.
.#.
3 2 2
.#
##
##
3 3 3
###
#.#
###
3 2 5
.#
##
#.

*/
lld inv(lld a,lld p){return a==1 ? 1 : inv(p%a,p)*(p-p/a) % M; }

int main(){
    int T;
    scanf("%d",&T);
    while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		char c[25][25];
		for(int i=0;i<n;++i)
			scanf("%s",c[i]);
		
		//to ch
		num=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(c[i][j]=='.')
					ch[i][j]=0;
				else
					ch[i][j]= ++num;
		
		//to c1
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				c1[i][j] = ch[i][j];
		n1=n;m1=m;	
		
		sqeeze();
		//to ch
		for(int i=0;i<n1;++i)
			for(int j=0;j<m1;++j)
				ch[i][j] = c1[i][j];
		n=n1;m=m1;	
		
		
		times=0;
		
		lld sum=0;
		sum= (find() + sum) % M;
		sum= (find() + sum) % M;
		sum= (find() + sum) % M;
		sum= (find() + sum) % M;
		
		mirror();
		
		sum= (find() + sum) % M;
		sum= (find() + sum) % M;
		sum= (find() + sum) % M;
		sum= (find() + sum) % M;
		
		//printf("%I64d\n",sum);
		
		printf("%lld\n",sum *inv(times,M ) % M);
		
	}
    return 0;
}
