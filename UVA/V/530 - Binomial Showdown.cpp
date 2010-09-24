#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,k;
    long long C;
    
    while(1){
        cin>>n>>k;
        
        if(n==0 && k==0) break;
        
        if(k>n/2) k=n-k;
        
        C=1;
        
        for(int i=0;i<k;i++) C=C*(n-i)/(1+i);
        
        cout<<C<<endl;
    }
    
    return 0;
}
