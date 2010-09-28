#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int f0,f1,f2;
    int A,B;
    
    while(cin>>f0>>f1>>f2){
        A=(f2-2*f1+f0)/2;
        B=(-f2+4*f1-3*f0)/2;
              
        cout<<A*9+B*3+f0<<" "<<A*16+B*4+f0<<" "<<A*25+B*5+f0<<endl;
    }
    
    return 0;
}
