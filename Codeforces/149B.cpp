#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int f(char c){
    if(c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

int main(){
    string s,s1,s2;
    cin >> s;
    
    for(int i = 0;i < s.size();++i)
        if(s[i] == ':') s[i] = ' ';
    
    istringstream is(s);
    is >> s1 >> s2;
    
    int p1 = 0,p2 = 0;
    
    while(p1 + 1 < s1.size() && s1[p1] == '0') ++p1;
    while(p2 + 1 < s2.size() && s2[p2] == '0') ++p2;
    
    if(p1 == s1.size() - 1 && f(s1[s1.size() - 1]) < 24 && p2 == s2.size() - 1) cout << -1 << '\n';
    else{
        vector<int> ans;
        
        for(int b = 2;b < 100;++b){
            bool ok = true;
            int h = 0,mm = 0;
            
            for(int i = p1;i < s1.size();++i){
                if(f(s1[i]) < b) h = min(24,h * b + f(s1[i]));
                else ok = false;
            }
            
            for(int i = p2;i < s2.size();++i){
                if(f(s2[i]) < b) mm = min(60,mm * b + f(s2[i]));
                else ok = false;
            }
            
            if(ok && h < 24 && mm < 60) ans.push_back(b);
        }
        
        if(ans.empty()) cout << 0 << '\n';
        else{
            for(int i = 0;i < ans.size();++i)
                cout << ans[i] << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}
