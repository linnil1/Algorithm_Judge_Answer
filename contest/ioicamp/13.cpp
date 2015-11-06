#include<cstdio>
#include<cstring>

char map[210][210];
char c[110];

void next (int x,int y,int &nx,int &ny,char c)
{
	nx = x;
	ny = y;
	switch(c)
	{
		case 'U':--nx;break;
		case 'D':++nx;break;
		case 'L':--ny;break;
		case 'R':++ny;break;
	};
};

int vx[4]={0,0,-1,1},
	vy[4]={1,-1,0,0};

void toblock(int x,int y)
{
	for(int i=0;i<4;++i)
	{
		int tx = x + vx[i] ,
			ty = y + vy[i];
		if(map[tx][ty] == -1)
			map[tx][ty] = 0;
	};
};

int todo()
{	

	int x=105,y=105,nx,ny,i;
    for(i=0;c[i];++i)
    {    	
    	next (x,y ,nx,ny,c[i]);
		if(map[nx][ny] !=-1)
			return 0;
		else
		{
			map[nx][ny] = 1;
			toblock(x,y);
		};
		
		x=nx;
		y=ny;
	};
	return 1;
};


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(map,-1,sizeof(map));
        scanf("%s",c);
        
        
        
        if(todo())
        	puts("worshik<(_ _)>");
        else
        	puts("MADA0");
    			
    			
        	
    }
    return 0;
}
