#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int H;
vector<int> key[100000],lson[100000],rson[100000];

void solve(int lvl, int id, int lo, int hi){
    if(lvl == H) return;
    
    if(key[lvl].back() >= lo){
        int pos = lower_bound(key[lvl].begin(),key[lvl].end(),lo) - key[lvl].begin();
        
        if(key[lvl][pos] <= hi){
            if(lo == key[lvl - 1][id]) rson[lvl - 1][id] = key[lvl][pos];
            else lson[lvl - 1][id] = key[lvl][pos];
            
            solve(lvl + 1,pos,key[lvl][pos],hi);
            solve(lvl + 1,pos,lo,key[lvl][pos]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    
    int T;
    string line;
    
    cin >> T;
    
    while(T--){
        cin >> H;
        
        getline(cin,line);
        
        for(int i = 0,x;i < H;++i){
            getline(cin,line);
            istringstream is(line);
            
            key[i].clear();
            
            while(is >> x) key[i].push_back(x);
            
            int sz = key[i].size();
            
            lson[i] = vector<int>(sz,-1);
            rson[i] = vector<int>(sz,-1);
        }
        
        solve(1,0,INT_MIN,key[0][0]);
        solve(1,0,key[0][0],INT_MAX);
        
        for(int i = 0;i < H;++i){
            int sz = key[i].size();
            
            for(int j = 0;j < sz;++j){
                cout << key[i][j] << ':';
                if(lson[i][j] != -1) cout << lson[i][j];
                cout << '-';
                if(rson[i][j] != -1) cout << rson[i][j];
                cout << '\n';
            }
        }
    }
    
    return 0;
}
