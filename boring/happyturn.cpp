
struct pic
{
	int a,b;
	char map[M][M];
	pic(){};
	pic(int _a,int _b):a(_a),b(_b){}
	
	pic scan()
	{
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;++i)
			scanf("%s",map[i]);
		return *this ;
	}
	
	pic turn()
	{
		pic now(b,a);
		for(int i=0;i<a;++i)
			for(int j=0;j<b;++j)
				now.map[j][a-1-i] = map[i][j] ;
		return *this = now ;
	}
	
	pic turn(int a)
	{
		while(a--)
			this->turn();
		return *this;
	}
	
	pic mirror()
	{
		pic now(a,b);
		for(int i=0;i<a;++i)
			for(int j=0;j<b;++j)
				now.map[i][b-1-j] = map[i][j] ;
		return *this = now ;
	}
	
	void pr()
	{
		for(int i=0;i<a;++i,puts(""))
			for(int j=0;j<b;++j)
				printf("%c ",map[i][j]);
	}
};


/*

3 6
..**..
**...*
...**.
*/
