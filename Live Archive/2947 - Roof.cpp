#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN 40000

struct event{
    int x,id,type;
    
    // type = 0 : start
    // type = 1 : event
    
    event(){}
    
    bool operator < (event X)const{
        return x < X.x;
    }
}E[2 * MAXN];

int N,x1[MAXN],x2[MAXN],y1[MAXN],y2[MAXN];
int next[MAXN + 1],id[MAXN + 1],cont,water[MAXN],low[MAXN];
bool pop[MAXN];
vector<int> L[MAXN];

int memo[MAXN];

int solve(int pos){
    int &ret = memo[pos];
    
    if(ret == -1){
        ret = water[pos];
        
        for(int i = L[pos].size() - 1;i >= 0;--i)
            ret += solve(L[pos][i]);
    }
    
    return ret;
}

int main(){
    int T;
    bool first = true;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
        
        for(int i = 0;i < N;++i){
            E[i].x = x1[i]; E[i].id = i; E[i].type = 0;
            E[N + i].x = x2[i]; E[N + i].id = i; E[N + i].type = 1;
        }
        
        memset(water,0,sizeof water);
        sort(E,E + 2*N);
        next[0] = -1;
        cont = 1;
        
        for(int i = 0;i < N;++i){
            L[i].clear();
            
            if(y1[i] < y2[i]) low[i] = x1[i];
            else low[i] = x2[i];
        }
        
        for(int i = 0;i < 2*N;){
            int last = 0;
            
            for(int pos = next[0];pos != -1;pos = next[pos])
                last = pos;
            
            memset(pop,false,sizeof pop);
            int e = i,X = E[i].x;
            
            while(e < 2*N && E[e].x == X){
                if(E[e].type == 0){
                    next[last] = cont++;
                    last = next[last];
                    id[last] = E[e].id;
                    next[last] = -1;
                }else{
                    pop[ E[e].id ] = true;
                }
                
                ++e;
            }
            
            vector< pair<double, int> > v;
            
            for(int pos = next[0];pos != -1;pos = next[pos]){
                double y = (double)(y1[ id[pos] ] * (x2[ id[pos] ] - X) + y2[ id[pos] ] * (X - x1[ id[pos] ])) / (x2[ id[pos] ] - x1[ id[pos] ]);
                
                v.push_back(make_pair(y,id[pos]));
            }
            
            sort(v.rbegin(),v.rend());
            
            int m = v.size();
            
            for(int j = 0;j + 1 < m;++j){
                if(X == low[ v[j].second ])
                    L[ v[j + 1].second ].push_back(v[j].second);
            }
            
            for(int pos = next[0],prev = 0;pos != -1;pos = next[pos]){
                if(pop[ id[pos] ]) next[prev] = next[pos];
                else prev = pos;
            }
            
            if(e != 2*N && next[0] != -1){
                double maxY = -1;
                int ind = -1;
                
                for(int pos = next[0];pos != -1;pos = next[pos]){
                    double y = ((double)y1[ id[pos] ] * (x2[ id[pos] ] - X) + (double)y2[ id[pos] ] * (X - x1[ id[pos] ])) / (x2[ id[pos] ] - x1[ id[pos] ]);
                    
                    if(y > maxY){
                        maxY = y;
                        ind = id[pos];
                    }
                }
                
                water[ind] += E[e].x - E[i].x;
            }
            
            i = e;
        }
        
        if(!first) printf("\n");
        first = false;
        
        memset(memo,-1,sizeof memo);
        
        for(int i = 0;i < N;++i)
            printf("%d\n",solve(i));
    }
    
    return 0;
}
