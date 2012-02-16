#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    int T,C;
    string s1,s2,s3,s4,end,aux;
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> C >> s1 >> s2 >> end;
        s3 = s1; s4 = s2;
        aux = s1 + s2;
        
        int ans = -1;
        
        for(int it = 0;;it++){
            if(aux == end){
                ans = it;
                break;
            }
            
            aux.clear();
            
            for(int i = 0;i < C;++i){
                aux += s4[i];
                aux += s3[i];
            }
            
            s3 = aux.substr(0,C);
            s4 = aux.substr(C,2*C);
            
            if(s1 == s3 && s2 == s4) break;
        }
        
        cout << tc << ' ' << ans << '\n';
    }
    
    return 0;
}
