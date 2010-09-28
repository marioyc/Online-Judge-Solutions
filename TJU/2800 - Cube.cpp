#include <iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,n;
    cin>>t;
    
    while(cin>>n) cout<<n*n-n+1<<" "<<n*n+n-1<<endl;

    return 0;
}
