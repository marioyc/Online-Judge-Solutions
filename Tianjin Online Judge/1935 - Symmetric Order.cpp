#include<string>
#include<iostream>

using namespace std;

int n;

string s;

void imp(int a){
    if(a==n){
        cin>>s;
        cout<<s<<endl;
        return;
    }
    
    string s2;
    
    if(a==n-1){
        cin>>s;
        cout<<s<<endl;
        cin>>s;
        cout<<s<<endl;
        return;
    }
        
    cin>>s>>s2;
    cout<<s<<endl;
    
    imp(a+2);
    
    cout<<s2<<endl;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int i=1;
    while(1){
        cin>>n;
        if(n==0) break;
        
        cout<<"SET "<<i<<endl;
        
        imp(1);
        i++;
    }
}
