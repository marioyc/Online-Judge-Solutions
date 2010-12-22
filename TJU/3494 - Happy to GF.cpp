#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    int L,D,T;
    cin>>L>>D>>T;
    
    string dict[D],pattern;
    for(int i = 0;i<D;++i) cin>>dict[i];
    
    for(int tc = 1;tc<=T;++tc){
        cin>>pattern;
        
        int ans = 0,P = pattern.size();
        
        for(int i = 0;i<D;++i){
            bool valid = true;
            
            for(int j = 0,pos = 0;j<L && valid;++j){
                valid = false;
                
                if(pattern[pos]=='('){
                    while(pattern[pos]!=')'){
                        if(dict[i][j]==pattern[pos]) valid = true;
                        ++pos;
                    }
                }else valid = (dict[i][j]==pattern[pos]);
                
                ++pos;
            }
            
            if(valid) ++ans;
        }
        
        cout<<"Case #"<<tc<<": "<<ans<<endl;
    }
    
    return 0;
}
