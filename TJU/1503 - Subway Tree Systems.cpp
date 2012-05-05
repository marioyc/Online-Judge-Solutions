#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map< vector<int> , int > M;
string s;
int cont;

int hash(int l, int r){
    vector<int> v;
    v.push_back(0);
    
    int aux = 0;
    
    for(int i = l,x = l;i <= r;++i){
        if(s[i] == '0') ++aux;
        else --aux;
        
        if(aux == 0){
            v.push_back(hash(x + 1,i - 1));
            x = i + 1;
        }
    }
    
    if(v.size() > 1) sort(v.begin() + 1,v.end());
    v.push_back(1);
    
    if(M.find(v) == M.end()) M[v] = cont++;
    
    return M[v];
}

int main(){
    ios::sync_with_stdio(0);
    
    int T;
    string s1,s2;
    
    cin >> T;
    
    while(T--){
        cin >> s1 >> s2;
        int L = s1.size(),L2 = s2.size();
        
        if(L != L2) cout << "different\n";
        else{
            cont = 2;
            M.clear();
            
            s = s1;
            int x = hash(0,L - 1);
            
            s = s2;
            int y = hash(0,L - 1);
            
            if(x == y) cout << "same\n";
            else cout << "different\n";
        }
    }
    
    return 0;
}
