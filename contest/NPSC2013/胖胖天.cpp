#include<stdio.h>

/*
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#include<math.h>
*/
#include<algorithm>
#include<set>
/*
#include<iostream>

#include<string>
#include<vector>

using namespace std;
*/
#define times --time||~scanf("%d",&time)
int main()
{
    int q,w,e,r,t,a,time=1;
    std::set<int> max;
    while(times)
    {
        scanf("%d",&a);
        int c[a],mons=0;
        for(q=0;q<a;++q)
            scanf("%d",&c[q]);
        std::sort(c,c+a);
        max.clear();
        for(q=0;q<a;++q)
        {

            if(!max.count(c[q]))
                max.insert(c[q]);
            else if(!max.count(c[q]*2))
                max.insert(c[q]*2);
        };
        printf("%d\n",max.size());
    }
    return 0;
};
/*
*/
