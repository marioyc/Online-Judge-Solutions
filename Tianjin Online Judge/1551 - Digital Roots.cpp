#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string n;
    int ax;
    
    while(1){
        cin>>n;
        if(n=="0") break;
        
        ax=0;
        
        for(int i=0;i<n.size();i++) ax+=n[i]-'0';
        
        if(ax%9==0) cout<<9<<endl;
        else cout<<ax%9<<endl;
    }
    
    return 0;
}
