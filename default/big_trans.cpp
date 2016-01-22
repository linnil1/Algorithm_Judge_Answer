
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
	bool in(){
		v = std::vector<std::string>();
		if(std::getline(std::cin,s))
			return 1;
		else
			return 0;
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
				s.push( INT(i) );
				//s.push( atoi(i.c_str()) );//be aware
		return s.top();// it must be 0
	}

};

/*
int main(){
	Big_trans<long long > I;
	while(I.in()){
		if(!I.change())
			std::cout <<"error\n";
		else
			std::cout<<I.cal()<<"\n";
	}
	return 0;
}
	
*/
