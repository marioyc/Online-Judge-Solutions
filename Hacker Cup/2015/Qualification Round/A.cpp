#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long to_int(string s){
    int L = s.size();
    long long ret = 0;
    
    for(int i = 0;i < L;++i)
        ret = ret * 10 + s[i] - '0';
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    int T;
    string N;
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N;
        
        long long mn = to_int(N),mx = to_int(N),aux;
        int L = N.size();
        
        for(int i = 1;i < L;++i){
            if(N[i] != '0'){
                swap(N[0],N[i]);
                aux = to_int(N);
                mn = min(mn,aux);
                mx = max(mx,aux);
                swap(N[0],N[i]);
            }
        }
        
        for(int i = 1;i < L;++i)
            for(int j = i + 1;j < L;++j){
                swap(N[i],N[j]);
                aux = to_int(N);
                mn = min(mn,aux);
                mx = max(mx,aux);
                swap(N[i],N[j]);
            }
        
        cout << "Case #" << tc << ": " << mn << ' ' << mx << '\n';
    }
    
    return 0;
}
