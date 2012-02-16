#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    int T,N,ac[9],totalS[9],totalT[9],tm,cont[62][9];
    string team;
    char prob,res;
    bool first = true,done[62][9];
    map<string, int> id;
    
    cin >> T;
    
    while(T--){
        cin >> N;
        
        memset(ac,0,sizeof ac);
        memset(done,false,sizeof done);
        memset(cont,0,sizeof cont);
        memset(totalS,0,sizeof totalS);
        memset(totalT,0,sizeof totalT);
        id.clear();
        
        for(int i = 0,aux = 0;i < N;++i){
            cin >> tm >> team >> prob >> res;
            
            if(id.find(team) == id.end()) id[team] = aux++;
            
            int k = id[team];
            
            if(!done[k][prob - 'A']){
                ++cont[k][prob - 'A'];
                
                if(res == 'A'){
                    done[k][prob - 'A'] = true;
                    totalT[prob - 'A'] += tm;
                    totalS[prob - 'A'] += cont[k][prob - 'A'];
                    ++ac[prob - 'A'];
                }
            }
        }
        
        if(!first) cout << '\n';
        first = false;
        
        for(int i = 0;i < 9;++i){
            cout << (char)('A' + i) << ' ' << ac[i];
            
            if(ac[i])
                cout << fixed << setprecision(2) << ' ' << (double)totalS[i] / ac[i] << ' ' << (double)totalT[i] / ac[i];
            
            cout << '\n';
        }
    }
    
    return 0;
}
