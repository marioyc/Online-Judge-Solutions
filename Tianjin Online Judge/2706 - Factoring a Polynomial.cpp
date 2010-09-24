#include<iostream>

using namespace std;

int main(){
    int n;
    
    cin>>n;
    if(n>=3) cout<<"NO"<<endl;
    else if (n<=1) cout<<"YES"<<endl;
    else{
        int coef[3];
        
        for(int i=0;i<3;i++) cin>>coef[i];
        
        if(coef[1]*coef[1]-4*coef[0]*coef[2]<0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}
