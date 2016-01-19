struct prim{
	const static int MM=1000100;
	int pr[MM/10],ps;
	char c[MM+1];
	void init(){
		ps=0;
		memset(c,1,sizeof(c));
		for(int i=2;i<=MM;++i){
			if(c[i])pr[ps++]=i;
			for(int j=0;j<ps && pr[j]*i<=MM ; ++j){
				c[ pr[j]*i ] = 0 ;
				if(i%pr[j]==0)
					break;
			};			
		}
	}
	
	ll isprim(ll &a){		
		//be careful at 0,1 
		int n = (int)sqrt(a);
		for(int i=0;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	
	typedef std::vector< std::pair<ll,int> > IVMP ;
	IVMP brek(ll a){// need to init
		IVMP v;
		ll k;
		while( (k=isprim(a)) > 1){
			int t=0;
			while(a%k==0)
				a/=k,++t;
			v.push_back( std::make_pair(k,t) );
		};
		return v;
	}
	
}p;
