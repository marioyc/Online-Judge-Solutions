#include<iostream>

using namespace std;

int main(){

    int t,n;
    cin>>t;
    int a,b,c;
    
    for(int i=0;i<t;i++){
        cin>>n;
        a=n/25;
        n%=25;
        b=n/10;
        n%=10;
        c=n/5;
        n%=5;
        cout<<i+1<<" "<<a<<" QUARTER(S), "<<b<<" DIME(S), "<<c<<" NICKEL(S), "<<n<<" PENNY(S)"<<endl;        
    }

    return 0;
}
