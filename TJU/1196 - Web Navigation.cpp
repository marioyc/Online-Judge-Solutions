#include <iostream>
#include <string>

using namespace std;

int main(){
    string urls[201],comm,s;
    urls[0] = "http://www.acm.org/";
    int b = 0,f = 0;
    
    ios::sync_with_stdio(false);
    
    while(true){
        cin>>comm;
        if(comm[0]=='Q') break;
        
        if(comm[0]=='V'){
            f = 0; ++b;
            cin>>urls[b];
            cout<<urls[b];
        }else if(comm[0]=='B'){
            if(b>0){
                --b; ++f;
                cout<<urls[b];
            }else cout<<"Ignored";
        }else{
            if(f>0){
                --f; ++b;
                cout<<urls[b];
            }else cout<<"Ignored";
        }
        
        cout<<'\n';
    }
    
    return 0;
}
