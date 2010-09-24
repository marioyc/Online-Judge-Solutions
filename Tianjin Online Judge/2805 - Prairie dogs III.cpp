#include<iostream>
#include<string>

using namespace std;

int pot3[]={1,3,9,27,81,243,729,2187,6561,19683};

void f(int n){
    if(n==0){
        cout<<'@';
        return;
    }
    
    f(n-1);
    string s(pot3[n-1],' ');
    cout<<s;
    f(n-1);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    
    while(cin>>n){
        f(n);
        cout<<endl;
    }
    
    return 0;
}
