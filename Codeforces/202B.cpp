#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> v,v2,p;
int n,m,k;

int solve(){
    vector<int> ind;
    for(int i = 0;i < n;++i)
        ind.push_back(i);
    
    int ret = -1;
    
    do{
        int pos = 0;
        v2.clear();
        for(int i = 0;i < n;++i)
            v2.push_back(v[ ind[i] ]);
        
        for(int i = 0;i < k && pos < n;++i)
            if(p[i] == v2[pos]) ++pos;
        
        if(pos == n){
            int aux = 0;
            
            for(int i = 0;i < n;++i)
                for(int j = i + 1;j < n;++j)
                    if(ind[i] > ind[j]) ++aux;
            
            ret = max(ret,n * (n - 1) / 2 - aux + 1);
        }
    }while(next_permutation(ind.begin(),ind.end()));
    
    return ret;
}

int main(){
    string s;
    
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> s;
        v.push_back(s);
    }
    
    int pos = -1,sim = 0;
    
    cin >> m;
    
    for(int i = 0;i < m;++i){
        cin >> k;
        p.clear();
        
        for(int j = 0;j < k;++j){
            cin >> s;
            p.push_back(s);
        }
        
        int ret = solve();
        
        if(ret != -1 && (pos == -1 || ret > sim)){
            pos = i + 1;
            sim = ret;
        }
    }
    
    if(pos == -1) cout << "Brand new problem!\n";
    else{
        cout << pos << "\n[:";
        for(int i = 0;i < sim;++i) cout << "|";
        cout << ":]\n";
    }
    
    return 0;
}
