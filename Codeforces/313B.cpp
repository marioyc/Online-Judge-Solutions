#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    string s;
    cin >> s;
    int L = s.size();
    int pos[L];
    
    for(int i = 0,cont = 0;i < L;){
        int e = i;
        
        while(e < L && s[e] == s[i]){
            pos[e] = cont;
            ++e;
        }
        
        i = e;
        ++cont;
    }
    
    int Q,l,r;
    
    cin >> Q;
    
    while(Q--){
        cin >> l >> r;
        --l; --r;
        cout << (r - l + 1) - (pos[r] - pos[l] + 1) << '\n';
    }
    
    return 0;
}
