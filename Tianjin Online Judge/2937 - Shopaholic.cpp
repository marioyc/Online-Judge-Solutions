#include<iostream>

using namespace std;

int main(){
    
    int n,t;
    int prices[20000];
    int discount;
    
    cin>>t;
    
    for(int caso=0;caso<t;caso++){
        cin>>n;
        
        for(int i=0;i<n;i++) cin>>prices[i];
        
        sort(prices,prices+n);
        
        discount=0;
        
        for(int i=n-3;i>=0;i-=3) discount+=prices[i];
        
        cout<<discount<<endl;
    }
    
    return 0;
}
