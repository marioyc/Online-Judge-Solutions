#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int a,b,c;
    
    cin>>a>>b>>c;
    
    if(a<=168) cout<<"CRASH "<<a<<endl;
    else if(b<=168) cout<<"CRASH "<<b<<endl;
    else if(c<=168) cout<<"CRASH "<<c<<endl;
    else cout<<"NO CRASH"<<endl;
        
    return 0;
}
