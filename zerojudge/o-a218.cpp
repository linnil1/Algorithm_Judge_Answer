#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int a[10]={0},c[10]={0};
		int co=0;
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			a[k]++;	
			c[k]++;			
		}
	    sort(c,c+10);
	    
		int b=-1;
		for(int h=9;h>=0 && c[h]!=0;h--){
			for(int q=0;q<10;q++){
	 			if(c[h]==a[q]){
	    			cout<<q<<" ";	 	
					a[q]=0;		
		 		}	  
			}
				  
		}
		cout<<endl;	
	}
	
}
