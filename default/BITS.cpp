#define lowbit(a) (a&-a)
struct bits{
	const int MM = 1000000;
	ll arr[MM];
	int n;//1<= <=n
	void init(int _n){
		n=1;
		while(_n){
			n<<=1;
			_n>>=1;
		}
		for(int i=1;i<=n;++i)
			arr[i]=0;
	}
	ll ask(int i){//a<= <=b
		if(i<1)
			return 0;
		ll sum=0;
		while(i){
			sum += arr[i];
			i ^= lowbit(i);			
		}
		return sum;
	}
	ll gsum(int a,int b){
		return ask(b)-ask(a-1);
	}
	
	void modi(int i,int &v){
		while(i<=n){
			arr[i]+= v ;
			i += lowbit(i);
		}
	}
	
}bit;
