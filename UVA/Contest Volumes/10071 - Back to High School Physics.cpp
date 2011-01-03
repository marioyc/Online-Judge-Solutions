#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int v,t;
    
    while(cin>>v>>t){
        if(t==0){
            cout<<0<<endl;
            continue;
        }
        
        cout<<2*v*t<<endl;
    }
}
