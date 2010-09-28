#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int C,B,sum,mx;
    
    cin>>C>>B;
    
    int calories[21];
    
    for(int i=0;i<B;i++) cin>>calories[i];
    
    mx=0;
    
    for(int mask=1;mask<(1<<B);mask++){
        sum=0;
        
        for(int i=0;i<21;i++){
            if((mask & (1<<i))!=0) sum+=calories[i];
        }
        
        if(sum<=C) mx=max(mx,sum);
    }
    
    cout<<mx<<endl;
    
    return 0;
}
