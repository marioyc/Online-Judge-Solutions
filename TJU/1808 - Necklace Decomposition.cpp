#include<iostream>
#include<string>

using namespace std;

bool necklace(string s){
    string x;
    int n=s.size();
    
    for(int i=1;i<n;i++){
        x=s.substr(i,n-i)+s.substr(0,i);
        if(x<s) return false;
    }
    
    return true;
}

int main(){    
    int T,N;
    string s,x;
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>s;
        N=s.size();
        
        for(int j=0;j!=N;){
            for(int k=N-j;;k--){
                x=s.substr(j,k);
                if(necklace(x)){
                    cout<<"("<<x<<")";
                    j=j+k;
                    break;
                }
            }
        }
        cout<<endl;
    }
    
    return 0;
}
