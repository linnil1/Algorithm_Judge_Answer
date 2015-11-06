#include<bits/stdc++.h>
#define ll long long
#define M 100010
#define MOD 1000000007
#define FR(i,n) for(int i=0;i<n;++i)
#define FRE(i,n) for(int i=1;i<=n;++i)
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define BFR(i,n) for(int i=n-1;i>=0;--i)
#define ALL(a) a.begin(),a.end()
#define mp std::make_pair
#define ft first
#define sd second
#define pb push_back
#define PR(a) cout <<  a << " " ; cout<<endl;
#define VMP std::vector<MP>

using std::cin;
using std::cout;
using std::string;
using std::sort;
using std::endl;
#define MAX std::max
#define MIN std::min

#define QI std::queue<int>
#define VI std::vector<int>
#define ARR(arr,n) int arr[n+2];FR(i,n)
#define ARRE(arr,n) int arr[n+2];FRE(i,n)
#define MP std::pair<int,int>
//using namespace std;

ll ans[M];

struct seg {
	seg *l,*r;
	ll max;
	seg() {};
	seg(int m):max(m) {};
	void pull() {
		max = MAX(l->max , r->max);
	}

};

seg* build(int l,int r) { //l<= <=r
	if(l==r)
		return new seg(ans[l]);

	seg* now = new seg;
	int mid = (l+r)>>1;
	now->l = build(l  ,mid);
	now->r = build(mid+1,r);
	now->pull();
	return now;
}

void modi(seg* t,int l,int r,int &wh,ll &key) {
	if(l==r) {
		t->max = ans[wh]=key;
		return;
	}
	int mid = (l+r)>>1;
	if(wh<=mid)
		modi(t->l,l,mid,wh,key);
	else
		modi(t->r,mid+1,r,wh,key);
	t->pull();
}

ll findmax(seg* t,int l,int r,int &wh) {
	if(wh<=l)
		return 0;
	if(r<wh)
		return t->max;

	int mid=(l+r)>>1;
	return MAX( findmax(t->l,l,mid,wh) ,
	            findmax(t->r,mid+1,r,wh) );
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	//freopen("..\\in.txt","r",stdin);
//int times;cin >> times ; while(times--)
	{
		int n;
		while(cin >> n) {
			std::map<int,int> m ;
			ARR(arr,n)
			cin >> arr[i],
			    m[arr[i]]=0;

			int len=0;
			for(auto &i:m)
				i.sd=len++;
			/*for(auto i:m)
				cout << i.ft <<" "<< i.sd <<"\n";*/
			FR(i,len)
			ans[i]=0;
			seg* root = build(0,len-1);
			FR(i,n) {

				int now = m[arr[i]];
				ll max = findmax(root,0,len-1,now)+arr[i];
				//cout << now << " "<<max<<endl ;
				/*FR(j,len)
					cout << ans[j] << " ";
				cout << endl;*/
				if(max > ans[now])
					modi(root,0,len-1,now,max);
			}


			cout << root->max << endl;

		};
	}
	return 0;
};
/*
1:16
2:36
80min very slow
but learn the auto &i
and the segment
*/
