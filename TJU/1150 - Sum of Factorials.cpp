#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
    
    int sum,n;
    bool M[1000001];
    
    memset(M,false,sizeof(M));
    
    for(int mask=1;mask<(1<<10);mask++){
        sum=0;
        
        for(int j=0;j<10;j++)
            if((mask&(1<<j))!=0) sum+=fac[j];
            
        M[sum]=1;
        
    }
    
    while(1){
        cin>>n;
        
        if(n<0) break;
        
        if(M[n]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
