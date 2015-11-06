
struct avl{
	avl *l,*r;
	int val,dep,ti;
	avl(){};
	avl(int _val):val(_val),dep(1),ti(1){l=r=NULL;};
	
	
};

int fdep(avl *t){return t ? t->dep : 0;}

void rot_L(avl * &t){
	avl *k = t -> r ;
	t -> r = k -> l ;
	k -> l = t ;
	t->dep = std::max(fdep(t->l),fdep(t->r) ) + 1 ;
	t = k ;	
	//cout << "L";
}
void rot_R(avl *&t){
	avl *k = t -> l ;
	t -> l = k -> r ;
	k -> r = t ;
	t->dep = std::max(fdep(t->l),fdep(t->r) ) + 1 ;
	t = k ;	
	//cout  << "R" ;
}	
void bal(avl *&t){
	if(!t)return ;
	if(fdep(t->l) >= fdep(t->r)+2 ){
		if( fdep(t->l->l) < fdep(t->l->r))
			rot_L(t->l);
		rot_R(t);
	}
	else if(fdep(t->l)+2 <= fdep(t->r) ){
		if( fdep(t->r->l) > fdep(t->r->r) )
			rot_R(t->r);
		rot_L(t);
	}
	//pull
	t->dep = std::max(fdep(t->l),fdep(t->r) ) + 1 ;
}	
void insert(avl * &t,int &val){
	if(!t) t= new avl(val);
	else if(val < t->val)
		insert(t->l , val);
	else if(val > t->val)
		insert(t->r , val);
	else
		t->ti++; 
	bal(t);
}

void midorder(avl *t){
	if(!t)return ;
	
	midorder(t->l);
	printf("%d %d\n",t->val,t->ti);		
	midorder(t->r);
}

