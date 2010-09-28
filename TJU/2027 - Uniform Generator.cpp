#include<iostream>
#include<iomanip>

using namespace std;

int mcd(int a, int b){
    if(a%b==0) return b;
    return mcd(b,a%b);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int step,mod;
    
    while(cin>>step>>mod){
        cout<<setw(10)<<step<<setw(10)<<mod<<"    ";
        
        if(mcd(step,mod)==1) cout<<"Good Choice\n\n";
        else cout<<"Bad Choice\n\n";
    }
    
    return 0;
}
