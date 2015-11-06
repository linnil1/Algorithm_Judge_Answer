#include<bits/stdc++.h>
#define ll long long 
#define M 1e5+10
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>


#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
using namespace std;

void nozero(VI &v)
{
	int now=v.size();
	while(now && !v[now-1])
		--now;
	v.resize(now);
}

VI rev(string& a)
{
	VI v;
	for(int i=a.size()-1,now=10000;i>=0;--i,now*=10)
	{		
		if(now==10000)
			v.pb(a[i]-'0'),
			now = 1;
		else
			v.back() += now*(a[i]-'0');	
	}
	nozero(v);
	return v;
}

VI operator + (VI &a,VI &b)
{
	VI c;
	for(int i=0,r=0;i<a.size() || i<b.size() || r;++i)
	{
		if(i<a.size()) r+=a[i];
		if(i<b.size()) r+=b[i];
		c.pb(r);
		r=0;
		if(c[i]>9999)
			r= c[i]/10000,
			c[i]%=10000;
	}
	return c;
}

VI mus(VI a,VI b,int span=0)
{
	for(int i=span,r=0;i<a.size() ;++i)
	{
		if(i-span<b.size()) a[i]-=b[i-span];
		if(a[i]<0)
			--a[i+1],
			a[i]+=10000;
	}
	nozero(a);
	return a;
}

VI operator - (VI &a,VI &b)//if a>=b
{
	return mus(a,b);
}
VI operator * (VI &a,VI &b)
{
	VI c;
	c.resize(a.size()+b.size()+2);
	for(int i=0;i<a.size();++i)
	{	
		for(int j=0;j<b.size();++j)
		{
			int now = i+j;
			c[now]+=a[i]*b[j];
			if(c[now]>9999)
				c[now+1]+= c[now]/10000,
				c[now]%=10000;
		};
	};
	nozero(c);
	return c;		
}

VI operator * (VI a,int &b)//b<10000
{
	a.resize(a.size()+1);
	int r=0;
	for(int i=0;i<a.size();++i)
	{	
		a[i]=a[i]*b+r;
		r=0;
		if(a[i]>9999)
		{
			r=a[i]/10000;
			a[i]%=10000;
		}
	};
	if(r)
		a.pb(r);
	nozero(a);
	return a;		
}


int comp(VI &a,VI b,int c) // a b+c
{
	if(a.size()>b.size()+c)
		return 1;
	else if(a.size()<b.size()+c)
		return -1;
	for(int i=0;i<b.size();++i)
		if(a[a.size()-1-i] > b[b.size()-1-i])
			return 1;
		else if(a[a.size()-1-i] < b[b.size()-1-i])
			return -1;
	return 0;
}	

VI div(VI &a,VI &b)//a/b
{
	VI c;
	if(comp(a,b,0)<0)
		return c;
	c.resize(a.size()-b.size()+1);
	
	for(int i=a.size()-b.size();i>=0;--i)
	{
		int mn = 0 ,mx = 10000;
		while(mn+1<mx)
		{
			int mid = (mn+mx)/2;
			if( comp(a,b*mid,i)>=0 )
				mn = mid;
			else 
				mx = mid;			
		}
		c[i]=mn;
		a = mus( a,b*mn,i);
	}
	nozero(c);
	return c;	
};
VI operator /(VI a,VI &b)
{
	return div(a,b);
}	
VI operator %(VI a,VI &b)
{
	div(a,b);
	return a;
}	

void pr(VI a){
	if(!a.size()){
		printf("0\n");
		return ;
	}
	printf("%d",a.back());
	for(int i=a.size()-2;i>=0;--i)
		printf("%04d",a[i]);
	puts("");
}

std::ostream& operator << (std::ostream & out,const VI &a)
{
	/*out.fill();
	out.width(0);	*/
	if(!a.size())	
	{
		out << "0\n";
		return out;
	}
	//out << a.size() <<"!";
		
	out << a.back(); 	
	
	for(int i=a.size()-2;i>=0;--i)
	{
		out.fill('0');
		out.width(4);
		out << a[i];
	}
	out  << endl;
	return out;
}


int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
{	
	string sa,sb;
	while(cin >> sa >>sb)
	{		
		VI  a=rev(sa),
			b=rev(sb);
		cout << a%b;
	};
}
	return 0;
};
/*
*/
