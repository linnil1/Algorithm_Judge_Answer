#include<stdio.h>
#include<string.h>
/*
#include<ctype.h>

#include<time.h>
#include<math.h>
#include<stdlib.h>
*/
#include<iostream>
/*
#include<queue>
#include<algorithm>
#include<map>
#include<string>


#include<cstdlib>
using namespace std;
*/
#define times --time||~scanf("%d",&time)
using namespace std;
string cha[14]=
{"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN",
"ELEVEN","TWELVE","THIRTEEN"};
string ob[5];
int object[5];
void peo(int num)
{
	int i;
    for(i=0;i<3;++i)cin>>ob[4];
    
	cin>>ob[4]>>ob[num];
	for(i=0;i<14;++i)
		if(ob[4]==cha[i])
		    object[num]=i;
};
int main()
{
	int i,j,k,time=1;
	int a,b;
	for(i=0;i<4;++i)
		peo(i);
		
    for(i=0;i<2;++i)cin>>ob[4];
    cin>>ob[4];
    
    ob[4].erase(ob[4].end()-1);
    //cout<<ob[4]<<"sdf\n";
    for(i=1;i<4;++i)
        object[i]*=object[i-1];
	for(i=0;i<4;++i)
	    if(ob[4]==ob[i])
			cout<<object[i]<<" "<<ob[i]<<endl;
	/*while(~scanf("%d",&a))
	{
	};
	scanf("%*d");*/
	return 0;
};
/*

*/
