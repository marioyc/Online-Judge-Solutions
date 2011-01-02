#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);    
    
    long long n,m,a;
    cin>>n>>m>>a;
    
    cout<<((n+a-1)/a)*((m+a-1)/a)<<endl;
    
    return 0;
}
