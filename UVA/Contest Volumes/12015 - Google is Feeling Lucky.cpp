#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    int tc = 1,T,best,r;
    vector<string> ans;
    string s;
    
    cin >> T;
    
    while(T--){
        best = -1;
        ans.clear();
        
        for(int i = 0;i < 10;++i){
            cin >> s >> r;
            
            if(r > best){
                best = r;
                ans.clear();
                ans.push_back(s);
            }else if(r == best) ans.push_back(s);
        }
        
        cout << "Case #" << tc++ << ":\n";
        
        int sz = ans.size();
        
        for(int i = 0;i < sz;++i)
            cout << ans[i] << '\n';
    }
    
    return 0;
}
