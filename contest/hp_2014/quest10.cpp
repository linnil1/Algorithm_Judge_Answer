#include<stdio.h>

/*
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
*/
#include<vector>
#include<string>
#include<iostream>
/*

#include<algorithm>
#include<map>


#include<cstdlib>

*/
using namespace std;
#define times --time||~scanf("%d",&time)
int main()
{
	int i,j,k,time=1;
	int a,b;
	string doth,name,name1;
	vector<string>c;
	while(cin>>doth&&doth!="SHOW"&&cin>>name)
	{
		if(doth == "ADD")
			c.push_back(name);
		else if(doth == "INSERT")
		{
			cin>>name1;
			for(i=0;i<c.size();++i)
			    if(c[i]==name1)
			    {
			        c.insert(c.begin()+i,name);
			        break;
				};
		}
		else if(doth == "REMOVE")
		{
			for(i=0;i<c.size();++i)
			    if(c[i]==name)
			    {
			        c.erase(c.begin()+i);
			        break;
				};
		};
	};

	for(i=0;i<c.size();++i)
		cout<<c[i]<<" ";
	puts("");
	//scanf("%*d");
	return 0;
};
/*

*/
