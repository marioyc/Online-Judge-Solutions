#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N,id[16];
    string s[16][3];
    
    cin >> N;
    
    for(int i = 0;i < N;++i){
        for(int j = 0;j < 3;++j)
            cin >> s[i][j];
        sort(s[i],s[i] + 3);
    }
    
    for(int i = 0;i < N;++i){
        cin >> id[i];
        --id[i];
    }
    
    int chosen[16];
    bool found = true;
    
    chosen[0] = 0;
    
    for(int i = 1;i < N;++i){
        found = false;
        
        for(int j = 0;j < 3;++j){
            if(s[id[i]][j] > s[id[i-1]][chosen[i-1]]){
                chosen[i] = j;
                found = true;
                break;
            }
        }
        
        if(!found) break;
    }
    
    if(!found) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i = 0;i < N;++i)
            cout << s[id[i]][chosen[i]] << endl;
    }
    
    return 0;
}
