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
    
    int step,mod,m;
    
    while(cin>>step>>mod){
        m=mcd(step,mod);
        
        cout<<setw(10)<<step<<setw(10)<<mod<<"    ";
        if(m==1) cout<<"Good Choice"<<endl;
        else cout<<"Bad Choice"<<endl;
        cout<<endl;
    }
    
    return 0;
}
