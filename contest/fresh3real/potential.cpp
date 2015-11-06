#ifndef EVAL
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int Answer(int N,int P,int *H,int *L,int *R,int *V);

int main()
{
	const int maxN = 1000000;
	const int maxP = 1000000;
	int *H = new int[maxN];
	int *L = new int[maxP];
	int *R = new int[maxP];
	int *V = new int[maxP];
	int N,P;
	while( cin>>N>>P )
	{
		for(int i=0;i<N;++i)
			cin>>H[i];
		for(int i=0;i<P;++i)
			cin>>L[i]>>R[i]>>V[i];
		cout<<Answer(N,P,H,L,R,V)<<endl;
	}
}
#endif
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*================================================================*/
/*Write Your Program Here*/
/*Notice: You should include header for youself*/

int Answer(int N,int P,int *H,int *L,int *R,int *V)
{
	int ans = H[0] ;
	ans = 4;
	return ans;
}