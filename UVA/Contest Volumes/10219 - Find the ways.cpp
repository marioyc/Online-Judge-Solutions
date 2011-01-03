#include<iostream>
#include<cmath>

using namespace std;

double log10(double n){
    return log(n)/log(10);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    long long n,k;
    double ax;
    int dig;
    
    while(cin>>n>>k){
        ax=0;
        
        for(int i=0;i<k;i++)
            ax+=log10(n-i)-log10(i+1);
            
        dig=floor(ax)+1;
        
        cout<<dig<<endl;
    }
    
    return 0;
}
