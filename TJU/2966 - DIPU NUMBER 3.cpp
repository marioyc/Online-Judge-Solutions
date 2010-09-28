#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    long long n;
    while(cin>>n){
        if(n<1000000000){
            if(n%10==(n/10)%10) cout<<n-1008990*((n/10000)%10-n%10)<<endl;
            else cout<<n+1008990*((n/10)%10-n%10)<<endl;
        }else{
            if(n%10==(n/10)%10) cout<<n-100998990*((n/100000)%10-n%10)<<endl;
            else cout<<n+100998990*((n/10)%10-n%10)<<endl;
        }
    }

    return 0;
}
