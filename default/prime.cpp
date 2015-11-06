
struct prim{
	const static int MM=100000;
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
	
	int isprim(int &a){		
		//be careful at 0,1 
		int n = (int)sqrt(a);
		for(int i=0;i<ps && pr[i]<=n ;++i)
			if( a % pr[i] == 0)
				return pr[i];
		return a;
	}
	
}p;
