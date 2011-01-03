#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    long long N,max;
    
    while(1){
        cin>>N;
        if(N<0) break;
        
        max=N*(N+1)/2+1;
        
        cout<<max<<endl;
    }

    return 0;
}
