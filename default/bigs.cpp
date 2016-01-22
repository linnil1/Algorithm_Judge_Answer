#include<bits/stdc++.h>
#define MM 1000000000 // every 9 digit in long long int 

class Big_pos{

#define ll long long 
#define pb push_back

private:
	std::vector<ll> v;

	void nozero(){// no head 0
		int len = v.size();
		for(;len>0&&v[len-1]==0;--len);
		v.resize(len);
	}

	int comp(Big_pos &a,Big_pos &b,int st=0){//compare from st position
		//if more digits
		if(a.size() < b.size()+st )
			return -1;
		if(a.size() > b.size()+st )
			return 1;
		// same digits comare from the top
		for(int i=0;i<b.size();++i)
			if(a.v[a.size()-1-i] < b.v[b.size()-1-i] )
				return -1;
			else if(a.v[a.size()-1-i] > b.v[b.size()-1-i] )
				return 1;
		return 0;
	}

	Big_pos minus(Big_pos a,Big_pos &b,int st=0){// a>=b
		if(comp(a,b,st) <0)
			puts("error");
		for(int i=0;i+st<a.size() ;++i){
		   ll y = i<b.size() ? b.v[i] : 0;
		   a.v[i+st]-=y;
			if(a.v[i+st]<0){
				a.v[i+st]+=MM;
				a.v[i+st+1]--;	
			}
		}
		a.nozero();
		return a;
	}

	Big_pos operator *(ll &a){
		Big_pos c;
		if(a)
			c.v.pb(a);
		return *this * c;
	}

	Big_pos div(Big_pos &a, Big_pos &b){ // tention: the value will be changed
		if(comp(a,b)<0)
			return Big_pos();//special for zero  it's quicker
		Big_pos c;
		c.v.resize(a.size()-b.size()+1);
		for(int i=a.size()-b.size();i>=0;--i){ // binary search 
			ll min=0,max=MM,mid;
			Big_pos tmp;
			while(min+1<max){
				mid = (min+max)>>1;
				tmp = b*mid;
				if( comp(a,tmp,i)<0)
					max = mid;
				else
					min = mid;
			}
			c.v[i]=min;
			tmp = b*min;
			a = minus(a,tmp,i);
//			std::cout << a << " " << b <<"\n";
		}
		a.nozero();
		c.nozero();
		return c;
	}

public:
	Big_pos(){
		v = std::vector<ll>();
	}

	Big_pos (std::string s){ // input a number 
		v = std::vector<ll>();
		for(int i=s.size()-1,now=MM;i>=0;--i,now*=10){
			if(now==MM){ // every MM a int
				now=1;
				v.pb(0);
			}
			v.back()+=now*(s[i]-'0');
		}
		nozero();
	}

	int size(){
		return v.size();
	}
	
/*	void print(){
		if(v.size()==0){
			printf("0");
			return ;
		}
		printf("%lld",v.back());
		for(int i=v.size()-2;i>=0;--i)
			printf("%08lld",v[i]);
	}
	
	bool IN(){
		std::string s;
		if(std::cin>>s){
			*this = Big_pos(s);
			return 1;
		}
		return 0;
	}
*/
	friend std::ostream& operator <<(std::ostream &out,Big_pos &a){
		if(a.size()==0){
			out<<"0";
			return out;
		}
		out << a.v.back();
		for(int i=a.size()-2;i>=0;--i){
			out.width(9);// every 9 digits
			out << std::setfill('0') << a.v[i] ;
		}
		return out;
	}

	friend std::istream& operator >>(std::istream &in,Big_pos &a){
		std::string s;
		in >> s;
		a = Big_pos(s);
		return in;
	}

		
	Big_pos operator + (Big_pos &b){
		int r=0;
		Big_pos c;
		for(int i=0;i<v.size()||i<b.size();++i){
			ll x = i<v.size() ? v[i] : 0,
			   y = i<b.size() ? b.v[i] : 0;
			c.v.pb(x+y+r);
			r=0;
			if(c.v.back()>=MM){
				r = 1;
				c.v.back()-=MM;
			}
		}
		if(r)
			c.v.pb(r);
		c.nozero();
		return c;
	}
				
	Big_pos operator * (Big_pos &b){
		Big_pos c;
		c.v.resize(v.size()+b.size()+2);
		for(int i=0;i<v.size();++i)
			for(int j=0;j<b.size();++j){
				auto r = c.v.begin()+(i+j) ;
			   	*r += v[i]*b.v[j];
				if(*r>=MM){
					*(r+1) += *r/MM;
					*r%=MM;
				}	
			}
		c.nozero();
		return c;
	}

//package
	Big_pos operator - (Big_pos &b){
		return minus(*this,b);
	}
	Big_pos operator / (Big_pos &b){
		Big_pos a = *this;
		return div(a,b);
	}
	Big_pos operator % (Big_pos &b){
		Big_pos a = *this;
		div(a,b);
		return a;
	}
	bool operator <(Big_pos &b){
		return comp(*this,b)<0;
	}

};

class Big:public Big_pos{

private : 
	char neg;

public:
	Big(char _n=0,Big_pos b=Big_pos()):neg(_n),Big_pos(b){};
	Big(std::string s){
		if(s[0]=='-')//be careful
			*this = Big(1,Big_pos(std::string(s.begin()+1,s.end()) ));
		else
			*this = Big(0,Big_pos(std::string(s.begin(),s.end()) ));
	}

	Big turn(){
		neg^=1;
		return *this;
	}


	Big operator + (Big b){
		if(neg ^ b.neg)
			return *this - b.turn() ;
		return Big(neg,Big_pos::operator + (b));
	}

	Big operator - (Big b){
		if( neg^b.neg )
			return *this + b.turn() ;
		if(Big_pos::operator < (b) )//beacuse minus must be a>=b
			return (b-*this).turn();
		return Big(neg,Big_pos::operator - (b) );
	}

	Big operator *(Big &b){
		return Big(neg^b.neg, Big_pos::operator*(b));
	}
	Big operator /(Big &b){
		return Big(neg^b.neg, Big_pos::operator/(b));
	}
	Big operator %(Big &b){
		return Big(neg^b.neg, Big_pos::operator%(b));
	}
	
	friend std::ostream& operator<< (std::ostream &out,Big b){
		if(b.neg && b.size())
			out <<'-';
		out << static_cast<Big_pos &>(b);
		return out;
	}

	friend std::istream& operator>> (std::istream &in,Big &b){
		std::string s;
		in >> s;
		b = Big(s);
		return in;
	}

};

template <class INT>
class Big_trans{
#define all_op(a) (a=='+' || a=='-' || a=='*' || a=='/' || a=='%')
#define pb push_back
private:
	std::string s;
	std::vector<std::string> v;

	bool to_my_way(){
		std::stack<int> st;//cal dig and ch
		st.push(0);
		int now=0;
		while(now<s.size()){
			if(s[now]=='-' && st.top()==0){// - on the head => -1*
				v.pb("-1");
				v.pb("*");
			}
			else if(isdigit(s[now])){
				if(st.top()++!=0)//add one
					return 0;//dig bug 
				int i;
				for(i=now;i<s.size() && isdigit(s[i]);++i);
				v.pb(s.substr(now,i-now));
				now = i-1;	
			}
			else if(all_op(s[now])){
				if(st.top()--!=1)
					return 0;// char bug
				v.pb(std::string(1,s[now]));
			}
			else if(s[now]=='('){
				if(st.top()!=0)
					return 0;//dig bug
				st.push(0);
				v.pb(std::string(1,s[now]));
			}
			else if(s[now]==')'){
				if(st.size()==1)
					return 0;//too more )
				if(st.top()==0)
					return 0;//dig bug
				st.pop();
				if(st.top()++!=0)
					return 0;//dig bug 
				v.pb(std::string(1,s[now]));
			}
			else if(s[now]!=' ' && s[now]!='\n')
				return 0;//strange char		
			++now;
		}
		if(st.size()!=1||st.top()!=1)//no enough )
			return 0;
		return 1;//everything good
	}

	int get_pri(std::string &s){//get priority
		switch(s[0]){
			case '+':case '-':		   return 6;break;
			case '*':case '/':case '%':return 5;break;
			case ')':case '(':		  return 17;break;
		}
	}

	void to_post(){
		std::stack<std::string> st;
		int now=0;
		for(std::string &i:v)
			if(i.size()==1 && (i[0]=='('||i[0]==')'||all_op(i[0])) ){
				while(st.size() && i!="(" && get_pri(st.top()) <= get_pri(i) ){
					if(st.top()=="("){//don't print (
						st.pop();
						break;
					}
					v[now++] = st.top();
					st.pop();
				}
				if(i!=")")//don't let ) in 
					st.push(i);
			}
			else// ( is at here 
				v[now++] = i ;

		while(st.size()){
			if(st.top()!="(")
				v[now++]=st.top();
			st.pop();
		}

		v.resize(now);
	}

	void test(){
		for(int i=0;i<v.size();++i)
			std::cout << v[i] << " ";
		std::cout << "!\n";
	}

public:
	Big_trans(std::string _s=""){
		v = std::vector<std::string>();
		s = _s;
	};
	
	friend std::istream& operator >>(std::istream& in,Big_trans &B){
		std::string s;
		std::getline(in,s);
		B = Big_trans(s);
		return in;
	}

	bool change(){
		if(!to_my_way())return 0;
//		test();
		to_post();
//		test();
		return 1;
	}

	INT cal(){
		std::stack<INT> s;
		for(std::string &i:v)
			if(i.size()==1 && all_op(i[0])){
				INT t = s.top();s.pop();
				switch(i[0]){
					case '+':s.top()=s.top()+t;break;
					case '-':s.top()=s.top()-t;break;
					case '*':s.top()=s.top()*t;break;
					case '/':s.top()=s.top()/t;break;
					case '%':s.top()=s.top()%t;break;
				}
			}
			else
				s.push(INT(i));//be aware
		return s.top();// it must be 0
	}

};


int main(){
	Big_trans<Big> B;
	while(std::cin>>B){
		if(!B.change())
			std::cout <<"error\n";
		else
			std::cout<<B.cal()<<"\n";
	}
	return 0;
}
