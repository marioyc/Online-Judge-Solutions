#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    unsigned int a,b,c;
    
    while(cin>>a>>b){
        c=0;
        
        for(int i=0;i<32;i++)
            if((a&(1<<i))!=0 ^ (b&(1<<i))!=0) c|=(1<<i);
            
        cout<<c<<endl;
    }

    return 0;
}
