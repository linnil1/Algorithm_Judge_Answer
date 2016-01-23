struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};

	bool in(){
		return ~scanf("%d%d",&x,&y);
	}

	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
};

#define MM 11000;
std::vector<xy> v[MM];

int bfs(int s,int e)
{
	int dis[MM];
	int use[MM];
	for(int i=0;i<MM;++i)
		dis[i]=INT_MAX,	
		use[i]=1;
	dis[s]=0;
	use[s]=0;
	
	QI q;
	q.push(s);
	while(q.size())
	{
		int now = q.front(); q.pop();
		use[now]=1;
		if(now==e)
			continue;
		for(xy& i:v[now])
			if(dis[now]+i.y+1 < dis[i.x])
			{
				dis[i.x] = dis[now]+i.y+1;
				if(use[i.x]){
					q.push(i.x);
					use[i.x]=0;
				}
			}		
	}
	return dis[e];
}


struct xy
{
	int x,y;
	xy(){};
	xy(int _x,int _y):x(_x),y(_y){};

	bool in(){
		return ~scnaf("%d%d",&x,&y);
	}

	bool operator < (const xy &b)const
	{
		if(x!=b.x)
			return x<b.x;
		else
			return y<b.y;
	}
};

std::vector<xy> v[11000];

int dfs(int s,int e,int n)
{
	int dis[n];
	ARR(dis,n)
		dis[i]=INT_MAX;	
	dis[s]=0;
	
	QI q;
	q.push(s);
	while(q.size())
	{
		int now = q.front();
		q.pop();
		for(xy& i:v[now])
			if(dis[now]+i.y < dis[i.x])
			{
				dis[i.x] = dis[now]+i.y;
				q.push(i.x);
			}		
	}
	return dis[e];
	
}
