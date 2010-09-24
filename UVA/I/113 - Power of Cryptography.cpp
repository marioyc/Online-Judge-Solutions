#include<iostream>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    double p,k;
    int ans;
    
    while(cin>>n>>p){
        k=exp(log(p)/n);
        
        ans=round(k);
        
        cout<<ans<<endl;
    }

    return 0;
}
