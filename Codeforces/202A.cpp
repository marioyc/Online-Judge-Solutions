#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    int L = s.size();
    
    string ans;
    
    for(int mask = 1;mask < (1 << L);++mask){
        string aux;
        
        for(int i = 0;i < L;++i)
            if(mask >> i & 1)
                aux += s[i];
        
        string aux2 = aux;
        reverse(aux2.begin(),aux2.end());
        
        if(aux == aux2)
            ans = max(ans,aux);
    }
    
    cout << ans << '\n';
    
    return 0;
}
