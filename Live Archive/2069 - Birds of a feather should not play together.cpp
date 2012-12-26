#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int tc = 1,N,m[9];
    string line,aux;
    string s[9][9];
    string name[9];
    map<string,int> cont;
    int sc[9];
    
    while(true){
        cin >> N;
        if(N == 0) break;
        
        getline(cin,line);
        cont.clear();
        
        for(int i = 0;i < N;++i){
            getline(cin,line);
            istringstream is(line);
            
            is >> name[i];
            m[i] = 0;
            
            while(is >> s[i][ m[i] ]){
                ++cont[ s[i][ m[i] ] ];
                m[i]++;
            }
        }
        
        int best = -1;
        
        for(int i = 0;i < N;++i){
            int cur = 0;
            
            for(int j = 0;j < m[i];++j)
                cur += s[i][j].size() * 2520 / cont[ s[i][j] ];
            
            best = max(best,cur);
            sc[i] = cur;
        }
        
        cout << "Round " << tc++ << '\n';
        
        bool first = true;
        
        for(int i = 0;i < N;++i)
            if(sc[i] == best){
                if(!first) cout << ' ';
                first = false;
                
                cout << name[i];
            }
        
        cout << '\n';
    }
    
    return 0;
}
