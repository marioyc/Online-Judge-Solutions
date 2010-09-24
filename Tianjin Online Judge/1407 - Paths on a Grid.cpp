#include<iostream>

using namespace std;

int main(){
    
    unsigned int n,m;
    unsigned int k;
    long long C;
    
    while(1){
        cin>>n>>m;
        
        if(n==0 && m==0) break;
        
        if(m>(m+n)/2) k=n;
        else k=m;
        
        C=1;
        
        for(int i=0;i<k;i++) C=C*(m+n-i)/(1+i);
        
        cout<<C<<endl;
    }
}
