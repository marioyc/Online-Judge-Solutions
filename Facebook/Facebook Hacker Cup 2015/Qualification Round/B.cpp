#include <iostream>

using namespace std;

int gp,gc,gf,p[20],c[20],f[20];
int sump[1 << 20],sumc[1 << 20],sumf[1 << 20];

int main(){
    ios::sync_with_stdio(0);
    
    int T,N;
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> gp >> gc >> gf >> N;
        
        for(int i = 0;i < N;++i)
            cin >> p[i] >> c[i] >> f[i];
        
        sump[0] = sumc[0] = sumf[0] = 0;
        bool found = false;
        
        for(int mask = 1;mask < (1 << N);++mask){
            int lb = __builtin_ctz(mask);
            
            sump[mask] = sump[mask ^ (1 << lb)] + p[lb];
            sumc[mask] = sumc[mask ^ (1 << lb)] + c[lb];
            sumf[mask] = sumf[mask ^ (1 << lb)] + f[lb];
            
            if(sump[mask] == gp && sumc[mask] == gc && sumf[mask] == gf)
                found = true;
        }
        
        cout << "Case #" << tc << ": " << (found? "yes" : "no") << '\n';
    }
    
    return 0;
}
