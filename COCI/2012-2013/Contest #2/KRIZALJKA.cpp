#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s[6];
    
    for(int i = 0;i < 6;++i)
        cin >> s[i];
    
    string ans;
    bool found = false;
    
    for(int mask = 0;mask < (1 << 6);++mask){
        if(__builtin_popcount(mask) == 3){
            vector<string> a,b;
            
            for(int i = 0;i < 6;++i){
                if(mask >> i & 1) a.push_back(s[i]);
                else b.push_back(s[i]);
            }
            
            sort(a.begin(),a.end());
            
            do{
                sort(b.begin(),b.end());
                string s1 = a[0] + a[1] + a[2];
                
                do{
                    string s2;
                    
                    for(int i = 0;i < 3;++i)
                        for(int j = 0;j < 3;++j)
                            s2 += b[j][i];
                    
                    if(s1 == s2 && (!found || s1 < ans)){
                        ans = s1;
                        found = true;
                    }
                }while(next_permutation(b.begin(),b.end()));
            }while(next_permutation(a.begin(),a.end()));
        }
    }
    
    if(!found) cout << 0 << endl;
    else{
        for(int i = 0;i < 3;++i){
            for(int j = 0;j < 3;++j) cout << ans[3 * i + j];
            cout << endl;
        }
    }
    
    return 0;
}
