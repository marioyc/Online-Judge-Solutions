#include<iostream>

using namespace std;

int n,a,b;

int main(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        
        if(b>a ) cout<<"impossible"<<endl;
        else if((a%2)!=(b%2)) cout<<"impossible"<<endl;
        else cout<<(a+b)/2<<" "<<(a-b)/2<<endl;
    }
    return 0;
}
