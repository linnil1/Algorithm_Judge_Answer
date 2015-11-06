#include<bits/stdc++.h>
#define M 1000100 
int mer_c[M],mer_d[M];
void mergesort(int *arr,int l,int r){ //l <= < r
	if(l+1>=r)
		return ;
	
	int mid = (l+r)>>1; // (l+r)/2
	mergesort(arr,l,mid);
	mergesort(arr,mid,r);	
	
	//copy
	int a=0,b=0;
	for(int i=l;i<mid;++i)
		mer_c[a++] = arr[i];
	for(int i=mid;i<r;++i)
		mer_d[b++] = arr[i];
	//merge
	for(int i=0,j=0;i<a;++i){
		while(j<b && mer_d[j] <= mer_c[i] )
			arr[l++] = mer_d[j++];
		arr[l++] = mer_c[i];
	}		
}

void quicksort(int *arr,int l,int r){
	
	if(l+1>=r)
		return ;	
	int f=l,b=r-1;	
	std::swap(arr[rand()%(r-l)+l],arr[b]);
	int &key = arr[b];
	while(f<b){
		while(f<b && arr[f]< key)
			++f;
		while(f<b && arr[b]>=key)
			--b;
		if(f<b)
			std::swap(arr[f],arr[b]);				
	}
	std::swap(key,arr[f]);	
	
	quicksort(arr,l,f);
	quicksort(arr,f+1,r);	
}
void bobblesort(int *arr,int n){
	for(int i=0;i<n;++i)
		for(int j=n-1;j>i;--j)//擠出最小排前面 
			if(arr[j-1] > arr[j])
				std::swap(arr[j-1],arr[j]);
}
void insertsort(int *arr,int n){
	for(int i=1;i<n;++i){
		int j,now=arr[i];
		for(j=i;j>0 && arr[j-1]>now;--j)
			arr[j] = arr[j-1];
		arr[j] = now ;
	}
}
void selectsort(int *arr,int n){
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(arr[j] < arr[i])
				std::swap(arr[i],arr[j]);
}

struct que{
	que *next;
	int val;
}tarr[M];
struct queue{
	que *f,*b;int size;
	void clear(){
		f=b=NULL;
		size=0;
	}
	
	void add(que *k){
		if(!size)
			f = b = k;
		else
			b->next = k ,
			b = k ;
		k->next = NULL ;
		++size;
	}
	void add(queue &q){
		if(!size)
			f = q.f;
		else
			b->next = q.f;
		if(q.size)	
			b = q.b;
		size+= q.size;
	}
	que* out(){
		que *t = f;
		if(size)
			f = f->next,
			--size;
		return t;
	}
};
void msd(long long  dig,queue &q){
	dig/=10;
	if(dig==0)
		return ;
	//go to bucket
	queue but[10];
	for(int i=0;i<10;++i)
		but[i].clear();
	for(que *k = q.out();k;k=q.out())
		but[k->val/dig%10].add(k);
	
	//recursive
	for(int i=0;i<10;++i)
		if(but[i].size)
			msd(dig,but[i]);
			
	//combine
	q.clear();
	for(int i=0;i<10;++i)
		q.add(but[i]);	
}
void radixsort_MSD(int *arr,int n){
	//put into tmp
	queue tmp ;
	tmp.clear();
	for(int i=0;i<n;++i){
		tarr[i].val = arr[i];		
		tmp.add( tarr+i );
	}
	//get most	
	long long int dig=1;
	for(int i=0;i<n;++i)		
		while(arr[i]>=dig)
			dig*=10;
	msd(dig,tmp);
	//combine to arr
	for(int i=0;i<n;++i)
		arr[i] = tmp.out()->val ;
	
}
void radixsort_LSD(int *arr,int n){
	//put into tmp
	queue tmp ;
	tmp.clear();
	for(int i=0;i<n;++i){
		tarr[i].val = arr[i];
		tmp.add( tarr+i );
	}	
	queue but[10];
	int mask=1;
	do{
		//put into bucket
		for(int i=0;i<10;++i)
			but[i].clear();
		for(que *t = tmp.out();t;t = tmp.out())			
			but[t->val/mask%10].add(t);				
		mask*=10;
		
		//put into tmp
		tmp.clear();
		for(int i=0;i<10;++i)
			tmp.add(but[i]);
	}while(but[0].size<n);
	
	for(int i=0;i<n;++i)
		arr[i] = but[0].out()->val;
}
#define fat(a) ((a+1)/2-1)
#define lef(a) (2*(a)+1)
#define rig(a) (2*(a)+2)
void heapsort_take(int *arr,int n){
	for(int i=n-1;i>0;--i){
		std::swap(arr[i],arr[0]);//put the biggest to rightest
		//沈下
		int j=0;
		while(lef(j)<i){
			int b = lef(j);	
			if(rig(j)<i && arr[b] < arr[rig(j)])
				b = rig(j);
			if(arr[j] < arr[b]){
				std::swap(arr[j],arr[b]);
				j = b ;
			}
			else
				break;			
		} 		
	}
}
void heapsort_one(int *arr,int n){//one by one
	for(int i=1;i<n;++i){
		int j = i ;
		while(j && arr[j] > arr[fat(j)]){
			//浮上 
			std::swap(arr[j],arr[fat(j)]);
			j = fat(j);
		}
	}
	heapsort_take(arr,n);
}

void heapsort_dfs(int *arr,int now,int &n){
	if(now>=n)
		return ;
	heapsort_dfs(arr,lef(now),n);
	heapsort_dfs(arr,rig(now),n);
	
	//沈下去 
	int j = now ;
	while(lef(j)<n){
		int b = lef(j);	
		if(rig(j)<n && arr[b] < arr[rig(j)])
			b = rig(j);
		if(arr[j] < arr[b]){
			std::swap(arr[j],arr[b]);
			j = b ;
		}
		else
			return ;		
	} 
}
void heapsort_all(int *arr,int n){//recursieve
	heapsort_dfs(arr,0,n);
	heapsort_take(arr,n);
}


void shellsort(int *arr,int n){
//4^k + 3*2^(k-1) + 1
	int gap[100],g=1;
	gap[0]=1;
	for(int a=4,b=1;gap[g-1]<n;++g,a<<=2,b<<=1)
		gap[g] = a + 3*b + 1 ;
	g-=2;
	//for each gap
	for(g;g>=0;--g){
		int& k = gap[g];
		//i use insertion sort
		for(int i=k,j;i<n;++i){
			int now = arr[i];
			for(j=i;j>=k && arr[j-k] > now;j-=k)
				arr[j] = arr[j-k];
			arr[j] = now ;					
		}			
	}	
}

struct tree{
	tree *l,*r;
	int t,v;
	int lon;//this is for avl
	tree(int _v):l(NULL),r(NULL),t(1),v(_v),lon(1){};
};
void tree_insert(tree *&t,int &val){
	if(!t)
		t = new tree(val);
	else if(t->v == val)
		t->t++;
	else if(t->v < val )
		tree_insert(t->r,val);
	else
		tree_insert(t->l,val);
}
void tree_inorder(tree *t,int *&arr){
	if(!t)
		return ;
	tree_inorder(t->l ,arr);
	while(t->t--)
		*(arr++) = t->v;
	tree_inorder(t->r ,arr);
	delete t ;
}
void binarytree_random(int *arr,int n){
	tree *root=NULL;
	while(n){
		std::swap(arr[rand()%n],arr[n-1]);
		tree_insert(root,arr[n-1]);
		--n;	
	}
	int *tmp = arr ;
	tree_inorder(root,tmp);
}
/*
inline int avl_lon (tree *t){
	return t ? t->lon : 0 ;
}*/
#define avl_lon(t) (t ? t->lon : 0 )
inline int avl_lonsync(tree *t){
	return t->lon = std::max(avl_lon(t->l),avl_lon(t->r)) + 1 ;
}
inline void avl_l(tree *&t){
	tree *r = t->r ;
	t->r = r->l ;
	r->l = t ;
	t = r ;
	avl_lonsync(t->l);
	avl_lonsync(t);
}
inline void avl_r(tree *&t){
	tree *l = t->l ;
	t->l = l->r ;
	l->r = t ;
	t = l ;
	avl_lonsync(t->r);
	avl_lonsync(t);
}
inline void avl_balance(tree *&t){
	if( avl_lon(t->l) >= avl_lon(t->r)+2){
		if( avl_lon(t->l->l) < avl_lon(t->l->r))
			avl_l(t->l);
		avl_r(t);
	}
	if( avl_lon(t->l)+2  <= avl_lon(t->r)){
		if( avl_lon(t->r->l) > avl_lon(t->r->r))
			avl_r(t->r);
		avl_l(t);
	}

}
void avl_insert(tree *&t,int &val){
	if(!t)
		t = new tree(val);
	else if(t->v == val)
		t->t++;
	else if(t->v < val )
		tree_insert(t->r,val);
	else
		tree_insert(t->l,val);
	avl_balance(t);
}
void avltree(int *arr,int n){
	tree *root = NULL ;
	for(int i=0;i<n;++i)
		avl_insert(root,arr[i]);
	int *tmp = arr ;
	tree_inorder(root,tmp);
}
// 為什麼 avl 跑的比較慢呢？ 因為他常數比較大
// 所以用之前的random 去跑就可以了阿
// 是阿 但是要記得那是沒有順序的時候才方便用


int arr[M];//放外面比較不容易開太大報掉 
int main(){
	srand(123);//for random 
	int n;
	//freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		//input
		for(int i=0;i<n;++i)
			scanf("%d",arr+i);
		//various sorting algorithm
		
			//mergesort(arr,0,n);
			avltree(arr,n);		
		
		//output
		for(int i=0;i<n;++i)
			printf("%d ",arr[i]);
		puts("");		
	}
}

