#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);    
    
    int n,ans;
    
    while(1){
        cin>>n;
        if(n==0) break;
    
        ans=1;
    
        for(int i=0;i<n%928;i++) ans=(ans*(n%2006))%2006;
        
        cout<<ans<<endl;
    }
    
    return 0;
}
