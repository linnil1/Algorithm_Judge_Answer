
struct trie {
	trie *c[128];//33~127  //32 = ' ' 
	int has;
	trie() {
		for(int i=33;i<128;++i)
			c[i] = NULL ;
		has=0;
	}
};
struct {
	trie *root ;
	void init(){
		root = new trie();
	}
	void in(char *c) {
		trie *now = root;
		for(int i=0;c[i];++i){
			char &k = c[i]; 
			if(now->c[k] == NULL )
				now->c[k] = new trie() ;
			now =   now-> c[k] ;			
		}
		now->has = 1;
	}
	
	void out(){
		std::stack< std::pair<trie* , int> > s ;
		printf("[ ]");
		s.push( mp(root,32) );	
		int no=0;	
		while(s.size()){
			auto &now = s.top() ;
			int st = now.sd++;
			if(st!=32)
				delete now.ft->c[st];
			for(int &i=now.sd;i<128;++i)
				if(now.ft->c[i]){
					
					if(st !=32)
						FR(j,s.size())
							printf("   ");				
					printf("[%c]",i);
					s.push( mp(now.ft->c[i],32) );
					no=0;
					break;
				}
			
			if(now.sd==128){
				s.pop();
				if(!no++)
					puts("");
			}
		}		
	}

} mytrie;

