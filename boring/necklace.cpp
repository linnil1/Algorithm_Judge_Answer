#include<iostream>
#include<fstream>
using namespace std;
//#define fput 
#ifdef fput
	#define cout f
	fstream f ;
#endif
void diamond(int n,int space)
{
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<space;++j)
			cout << ' ';
		for(int j=0;j<n-i;++j)
			cout << ' ';
		for(int j=1;j<2*i;++j)
			cout << 'O';
		cout << '\n';
	}
	for(int i=n-1;i>0;--i)
	{
		for(int j=0;j<space;++j)
			cout << ' ';
		for(int j=0;j<n-i;++j)
			cout << ' ';
		for(int j=1;j<2*i;++j)
			cout << 'O';
		cout << '\n';
	}
}
void necklace(int n)
{
	for(int i=1;i<=n;++i)
		diamond(i,n-i);
	for(int i=n-1;i>0;--i)
		diamond(i,n-i);
};

void tri(int n,int r,int max)
{
	for(int i=1;i<=2*n-1;++i)
		cout << (abs(i-n)+abs(max-r) <=n-1 ? 'O':' ' );
}
void  row(int n)
{
	for(int i=1;i<=2*n-1;++i)
	{
		for(int j=1;j<=n;++j)
			tri(j,i,n);
		for(int j=n-1;j>=0;--j)
			tri(j,i,n);
		cout << endl;
	}
}


int main()
{
	int n;
#ifdef fput
	f.open("test.txt",fstream::out);
	cin >> n;
#else 			
	while(cin >> n)
#endif
	{
		//row(n);
		for(int i=1;i<n;++i)
			diamond(i,(n-1)*(n-1)+n-i);
		row(n);
		for(int i=n-1;i>=1;--i)
			diamond(i,(n-1)*(n-1)+n-i);
	}
#ifdef fput
	f.close();
	system("start test.txt");
#endif
}
