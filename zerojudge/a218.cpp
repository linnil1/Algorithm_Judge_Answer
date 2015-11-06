#include<iostream>
#include<algorithm>
using namespace std;

struct number
{
    int num,time; 
};

bool operator <(number a,number b)
{
    if(a.time != b.time )
        return a.time > b.time;
    else
        return a.num < b.num ;
}

int main()
{
    int n;
    while(cin>>n)
    {
        int k=10;
        number c[k];
        for(int i=0;i<k;++i)
            c[i].num=i,
            c[i].time=0;
        while(n--)
        {
            int a;
            cin >> a;
            ++c[a].time;
        }
        sort(c,c+k);
	
        for(int i=0;i<k && c[i].time;++i)
            cout << c[i].num << " ";
        cout << endl ;
	  
    }
    return 0;
}
