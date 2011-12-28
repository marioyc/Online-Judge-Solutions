#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int n,m;
int type[12];
int memo[(1 << 12)][2];
int pre[12];
bool valid[(1 << 12)][2];

int solve(int mask, int f, int off){
    if(mask == 0) return 0;
    
    int &ret = memo[mask][f];
    
    if(ret == -1){
        ret = 1000;
        
        if(off == 0) ret = 1 + solve(mask,f ^ 1,1);
        
        for(int mask2 = mask;mask2 > 0;mask2 = (mask2 - 1) & mask){
            if(valid[mask2][f] && __builtin_popcount(mask2) <= m){
                int p = 0;
                
                for(int i = 0;i < n;++i)
                    if(mask2 & (1 << i))
                        p |= pre[i];
                
                if((~mask & p) == p)
                    ret = min(ret,1 + solve(mask ^ mask2,f ^ 1,0));
            }
        }
    }
    
    return ret;
}

int main(){
    map<string, int> id;
    char name[6],c;
    
    while(true){
        cin >> n >> m;
        if(n == -1) break;
        
        id.clear();
        
        for(int i = 0;i < n;++i){
            cin >> name;
            id[name] = i;
        }
        
        for(int i = 0,p,aux;i < n;++i){
            cin >> name >> c >> p;
            
            aux = id[name];
            
            if(c == 'F') type[aux] = 0;
            if(c == 'S') type[aux] = 1;
            if(c == 'B') type[aux] = 2;
            
            pre[aux] = 0;
            
            for(int j = 0,x;j < p;++j){
                cin >> name;
                x = id[name];
                
                pre[aux] |= (1 << x);
            }
        }
        
        memset(valid,true,sizeof valid);
        
        for(int mask = 0;mask < (1 << n);++mask){
            for(int i = 0;i < n;++i)
                if((mask & (1 << i)) && type[i] == 1)
                    valid[mask][1] = false;
            
            for(int i = 0;i < n;++i)
                if((mask & (1 << i)) && type[i] == 0)
                    valid[mask][0] = false;
        }
        
        memset(memo,-1,sizeof memo);
        
        cout << "The minimum number of semesters required to graduate is " << solve((1 << n) - 1,1,0) << ".\n";
    }
    
    return 0;
}
