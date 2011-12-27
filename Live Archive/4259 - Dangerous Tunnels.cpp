#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N,N2,K,E;
int last[404],next[41208],to[41208],dang[41208],cap[41208];
int Q[404],head,tail,parent[404];

void add_edge(int u, int v, int d){
    to[E] = v; next[E] = last[u]; last[u] = E; dang[E] = d; ++E;
    to[E] = u; next[E] = last[v]; last[v] = E; dang[E] = d; ++E;
}

bool max_flow(int max_d){
    for(int i = 0;i < E;i += 2){
        cap[i] = 1;
        cap[i + 1] = 0;
    }
    
    for(int it = 0;it < K;++it){
        memset(parent,-1,sizeof parent);
        
        head = tail = 0;
        
        parent[1] = -2;
        Q[tail++] = 1;
        
        while(head < tail){
            int cur = Q[head++];
            
            for(int e = last[cur],v;e != -1;e = next[e]){
                v = to[e];
                
                if(parent[v] == -1 && dang[e] <= max_d && cap[e] > 0){
                    parent[v] = e;
                    Q[tail++] = v;
                }
            }
        }
        
        if(parent[N2 - 2] == -1) return false;
        
        int cur = N2 - 2,prev;
        
        while(cur != 1){
            prev = to[ parent[cur] ^ 1];
            --cap[parent[cur]];
            ++cap[parent[cur] ^ 1];
            cur = prev;
        }
    }
    
    return true;
}

int main(){
    int t;
    
    for(int tc = 1;;++tc){
        scanf("%d",&N);
        if(N == 0) break;
        
        N += 2;
        
        E = 0;
        memset(last,-1,sizeof last);
        memset(next,-1,sizeof next);
        
        for(int i = 0;i < N;++i)
            add_edge(2*i,2*i + 1,0);
        
        scanf("%d",&t);
        
        for(int i = 0,a,b,d;i < t;++i){
            scanf("%d %d %d",&a,&b,&d);
            if(b < a) swap(a,b);
            add_edge(2*a + 1,2*b,d);
        }
        
        scanf("%d",&K);
        
        N2 = 2 * N;
        
        int lo = 0,hi = 100000,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            if(!max_flow(mi)) lo = mi + 1;
            else hi = mi;
        }
        
        printf("Case %d: ",tc);
        
        if(!max_flow(lo)) puts("no solution");
        else printf("%d\n",lo);
    }
    
    return 0;
}
