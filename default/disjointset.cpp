struct disjointset
{
	static const int MM=10100;
	int s[MM],n,group;
	
	void init(int _n){
		group = n = _n ;
		for(int i=0;i<=n;++i)
			s[i] = i ;
	};	
	inline int find(int a){
		return s[a]==a ? a : ( s[a] = find(s[a]) );
	}
	int unin(int a,int b){
		if(find(a)!=find(b)){
			s[find(a)] = find(b);
			--group;
			return 1;
		}
		else
			return 0;
	}	
	
}disj;


struct xy{
	int s,t,v;
	bool operator < (const xy &a)const{
		return v <a.v;
	}
};




