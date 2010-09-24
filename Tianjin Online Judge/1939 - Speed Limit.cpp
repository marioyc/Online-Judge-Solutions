#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,s,t,ax,tot;
    
    while(cin>>n){
        if(n==-1) break;
        
        ax=0;tot=0;
        
        for(int i=0;i<n;i++){
            cin>>s>>t;
            
            tot+=s*(t-ax);
            ax=t;
        }
        cout<<tot<<" miles"<<endl;
    }
}
