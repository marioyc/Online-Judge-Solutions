#include<iostream>

using namespace std;

int main(){
    long long n;
    int cont;
    
    while(cin>>n){
       if(n==1){
            cout<<"Stan wins."<<endl;
            continue;
        }
        
        cont=0;
        
        while(n>1){
            cont++;
            if(cont%2==1) n=(n+8)/9;
            else n=(n+1)/2;
        }
                
        if(cont%2==1) cout<<"Stan wins."<<endl;
        else cout<<"Ollie wins."<<endl;
    }
    
    return 0;
}
