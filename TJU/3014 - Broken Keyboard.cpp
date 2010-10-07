#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    int m,L,cont[256];
    string s;
    
    while(true){
        cin>>m;
        if(m==0) break;
        
        getline(cin,s);
        getline(cin,s);
        L = s.size();
        
        int key_count = 0, ans = 0, start = 0;
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i<L;++i){
            if(cont[s[i]]==0) ++key_count;
            ++cont[s[i]];
            
            while(start<i && key_count>m){
                if(cont[s[start]]==1) --key_count;
                --cont[s[start]];
                ++start;
            }
            
            if(key_count<=m) ans = max(ans,i-start+1);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
