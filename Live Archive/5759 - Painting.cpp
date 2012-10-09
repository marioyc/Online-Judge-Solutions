#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,K,M[500][500];
vector<int> vr[500][500];
int contc[500][500];
bool other[500];

int best;
vector<int> sol;

void solve(){
    for(int i = 1;i <= K;++i)
        for(int j = 0;j < n;++j)
            vr[i][j].clear();
    
    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j)
            vr[ M[i][j] ][i].push_back(j);
    
    memset(contc,0,sizeof contc);
    
    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j)
            ++contc[ M[i][j] ][j];
    
    for(int k = 1;k <= K;++k){
        bool all = true;
        
        for(int i = 0;i < n && all;++i)
            if(vr[k][i].size() < 2) all = false;
        
        if(all){
            if(n < best){
                best = n;
                sol.clear();
            }
            
            if(best == n)
                sol.push_back(k);
            
            continue;
        }
        
        for(int i = 0;i < n;++i){
            bool &ok = other[i];
            ok = true;
            
            for(int j = 0;j < n && ok;++j){
                ok = false;
                
                for(int x = 0;x < vr[k][j].size() && !ok;++x)
                    if(vr[k][j][x] != i) ok = true;
            }
        }
        
        for(int i = 0;i < n;++i){
            if(contc[k][i] > 1){
                if(other[i]){
                    if(n + 1 < best){
                        best = n + 1;
                        sol.clear();
                    }
                    
                    if(best == n + 1)
                        sol.push_back(k);
            
                    break;
                }
            }
        }
        
        int cont = 0;
        bool found = false;
        
        for(int i = 0;i < n;++i){
            if(vr[k][i].size() > 1) ++cont;
            if(other[i]) found = true;
        }
        
        if(cont >= 2 && found){
            if(n + 1 < best){
                best = n + 1;
                sol.clear();
            }
            
            if(best == n + 1)
                sol.push_back(k);
        }
        
        cont = 0;
        
        for(int i = 0;i < n;++i){
            if(contc[k][i] > 1){
                int cont = 0;
                
                for(int j = 0;j < n && cont < 2;++j){
                    for(int x = 0;x < vr[k][j].size();++x){
                        if(vr[k][j][x] != i){
                            ++cont;
                            break;
                        }
                    }
                }
                
                if(cont == 2){
                    if(n + 2 < best){
                        best = n + 2;
                        sol.clear();
                    }
                    
                    if(best == n + 2)
                        sol.push_back(k);
                    
                    break;
                }
            }
        }
    }
}

int main(){
    int T;    
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&K);
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&M[i][j]);
        
        best = 1000;
        solve();
        
        for(int i = 0;i < n;++i)
            for(int j = i + 1;j < n;++j)
                swap(M[i][j],M[j][i]);
        
        solve();
        
        printf("%d\n",best == 1000? 0 : best);
        
        sort(sol.begin(),sol.end());
        int m = unique(sol.begin(),sol.end()) - sol.begin();
        
        for(int i = 0;i < m;++i){
            if(i) putchar(' ');
            printf("%d",sol[i]);
        }
        
        putchar('\n');
    }
    
    return 0;
}
