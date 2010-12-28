#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);    
    
    string s,name[10];
    int n,days,w[10];
    bool first = true;
    
    while(cin>>s){
        n = 0;
        
        while(true){
            cin>>s;
            if(s=="END") break;
            
            name[n] = s;
            cin>>days>>w[n];
            w[n] -= days;
            ++n;
        }
        
        for(int i = 0;i<n;++i){
            for(int j = i+1;j<n;++j){
                if(w[i]<w[j]){
                    swap(name[i],name[j]);
                    swap(w[i],w[j]);
                }
            }
        }
        
        if(!first) cout<<'\n';
        first = false;
        for(int i = 0;i<n;++i) cout<<name[i]<<'\n';
    }
    
    return 0;
}
