#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,b,cont;
    
    while(cin>>n){        
        b=1; cont=1;
        
        do{
            b=b*10+1;
            b%=n;
            cont++;
        }while(b!=0);
        
        cout<<cont<<endl;
    }
    
    return 0;
}
