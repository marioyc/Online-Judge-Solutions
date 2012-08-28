#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N,p[5],g[5],set[5];

void updateP(int x){
    if(p[x] == 3){
        bool win = true;
        
        for(int i = 0;i < N;++i)
            if(i != x && p[i] > 2) win = false;
        
        if(win){
            memset(p,0,sizeof p);
            ++g[x];
            return;
        }
    }
    
    if(p[x] == 4){
        memset(p,0,sizeof p);
        ++g[x];
        return;
    }
    
    bool found = false;
    
    for(int i = 0;i < N;++i){
        if(p[i] == 4){
            found = true;
            --p[i];
        }
    }
    
    if(!found) ++p[x];
}

int main(){
    ios::sync_with_stdio(0);
    
    int L;
    string s;
    bool winner;
    
    while(true){
        cin >> N;
        if(N == 0) break;
        
        cin >> s;
        
        L = s.size();
        winner = false;
        
        memset(p,0,sizeof p);
        memset(g,0,sizeof g);
        memset(set,0,sizeof set);
        
        for(int i = 0;!winner;++i){
            int cur = s[i] - 'A';
            
            updateP(cur);
            
            vector< pair<int, int> > aux;
            
            for(int j = 0;j < N;++j)
                aux.push_back(make_pair(g[j],j));
            
            sort(aux.rbegin(),aux.rend());
            
            if(aux[0].first >= 6 && aux[0].first - aux[1].first >= 2){
                if(aux[1].first == 0) set[ aux[0].second ] += 2;
                else ++set[ aux[0].second ];
                memset(g,0,sizeof g);
            }
            
            for(int j = 0;j < N;++j){
                if(set[j] >= 3){
                    cout << (char)('A' + j) << '\n';
                    winner = true;
                }
            }
        }
    }
    
    return 0;
}
