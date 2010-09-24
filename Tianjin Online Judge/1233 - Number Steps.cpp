#include <iostream>

using namespace std;

int main(){

    int x,y,N;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>x>>y;
        
        if(x==y){
            if(x%2==0) cout<<2*x<<endl;
            else cout<<2*x-1<<endl;
        }else if(x-y==2){
            if(x%2==0) cout<<2*x-2<<endl;
            else cout<<2*x-3<<endl;
        }else cout<<"No Number"<<endl;
    }

    return 0;
}
