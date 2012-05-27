#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int T,N,d[10000],l[10000],D;
    int r[10000];
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N;
        
        for(int i = 0;i < N;++i)
            cin >> d[i] >> l[i];
        
        cin >> D;
        
        r[0] = d[0];
        
        for(int i = 0,j = 1;i < N;++i){
            while(j < N){
                if(d[i] + r[i] < d[j]) break;
                r[j] = min(d[j] - d[i],l[j]);
                ++j;
            }
        }
        
        bool found = false;
        
        for(int i = 0;i < N;++i)
            if(d[i] + r[i] >= D)
                found = true;
        
        cout << "Case #" << tc <<": " << (found? "YES" : "NO") << '\n';
    }
    
    return 0;
}
