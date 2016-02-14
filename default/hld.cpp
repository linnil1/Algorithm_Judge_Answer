const int MM = 35100;

//here you need you include a segment_tree

struct hlt{
	int val;
	int fa,dep;
	int top,ti;
};

struct heavy_ligt_decomposition{
	int n;
	hlt v[MM];
	std::vector<int> V[MM];

	void init(int _n){
		n = _n ;
		for(int i=0;i<n;++i)
			v[i].val=0,
			V[i] = std::vector<int>();	
	};

	void add(){
		int a,b;
		scanf("%d%d",&a,&b);
		V[a].pb(b);
	}

	// set max_son
	int time,mson[MM];
	void setmson(int i){
		if(i==-1)
			return ;
		for(int j=i; j==i || j!=-1 ;j=mson[j]){
			v[j].ti=time++;
			v[j].top = i;
		}
	}

	void decompose(){
		int st[MM],sto=0;
		v[0].dep=v[0].fa=0;
		st[sto++] = 0;
	
		// set dep & fa
		for(int j=0;j<sto;++j){
			int &now = st[j];
			for( int &i:V[now])
				if( i!= v[now].fa){
					v[i].fa = now;
					v[i].dep = v[now].dep+1;
					st[sto++] = i ;
				}
		}
	
		// set size, mson
		int size[MM],max[MM];
		time=0;
		for(int i=0;i<n;++i)
			size[i]= 1,
			mson[i]=-1,
			max[i] = 0;

		for(int j=sto-1;j>0;--j){
			int &now=st[j],&fa = v[now].fa;
			   size[fa]+= size[now];
			if( max[fa] < size[now]){
				max[fa] = size[now];
				setmson(mson[fa]);
				mson[fa] = now ;
			}
			else
				setmson(now);
		}
		setmson(0);

	}
	
	segment_tree segt;
	void gohld(int n,int m){
		init(n);
		for(int i=0;i<m;++i)
			add();
		decompose();
//		for(int i=0;i<n;++i)printf("%d:%d %d %d\n",i,mson[i],v[i].fa,v[i].top);
		
		for(int i=0;i<n;++i)
			segt.ori[v[i].ti] = v[i].val;
		segt.init(0,n-1);

	}

	int cal(int a,int b){
		int sum=0;
		while( v[a].top != v[b].top){
			if( v[a].dep < v[b].dep )
				std::swap(a,b);
			int t = v[a].top;
			// here
			sum += segt.ask(v[a].ti,v[t].ti);
			// done
			a = v[t].fa;
		}

		//here 
		sum +=  segt.ask(v[a].ti,v[b].ti);
		//done
		return sum;
	}

}hldtree;
