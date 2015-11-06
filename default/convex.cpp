struct xy{
	typedef int POI; // to change [double , ll , int]
	POI x,y;
	xy(){};
	xy(POI _x,POI _y):x(_x),y(_y){};
	friend std::istream& operator >> (std::istream &in, xy &a){
		in >> a.x >> a.y;
	}
	friend std::ostream& operator << (std::ostream &out, xy &a){
		out << a.x <<" "<< a.y<< endl;
	}
	xy operator + (const xy &b)const{
		return xy(x+b.x,y+b.y);
	}
	xy operator - (const xy &b)const{//ab = a-b
		return xy(x-b.x,y-b.y);
	}
	POI operator * (const xy &b)const{
		return x*b.x + y*b.y ;
	}
	POI operator / (const xy &b)const{
		return x*b.y - y*b.x;
	}
	bool operator < (const xy &b)const{
		return x!=b.x ? x<b.x : y <b.y;
	}
};

typedef std::vector<xy> VXY ; 
struct convexhull{
	
	
	void type(VXY &v){
		for(int i=0;i<v.size();++i)
			cout << v[i];
	}
	ll area(VXY &v){
		if(v.size()<=2)
			return 0;
		ll sum=0;
		for(int i=1;i<v.size();++i)
			sum += v[i-1]/v[i];
		sum += v[v.size()-1]/v[0];
		return std::abs(sum);
	}
	double area2(VXY &v){
		if(v.size()<=2)
			return 0;
		double sum=0;
		for(int i=1;i<v.size();++i)
			sum += v[i-1]/v[i];
		sum += v[v.size()-1]/v[0];
		return std::fabs(sum/2);
	}
	
	VXY convex(xy *arr,int n){	
		if(n<3)
			puts("ERROR");
		std::sort(arr,arr+n);
		//down
		VXY v;
		v.pb(arr[0]);
		v.pb(arr[1]);
		for(int i=2;i<n;++i){
			while( v.size()>=2 && 
			(v[v.size()-1] -v[v.size()-2] ) / ( arr[i]-v.back()) <= 0 )
				v.pop_back();
			v.pb(arr[i]);
		}
		//up
		v.pb(arr[n-2]);	
		int k = v.size();
		for(int i=n-3;i>=0;--i){
			while( v.size()>=k && 
			(v[v.size()-1] -v[v.size()-2] ) / ( arr[i]-v.back()) <= 0 )
				v.pop_back();
			v.pb(arr[i]);
		}
		return v;//the last one is the first one
	}
}con;
