#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 100000
#define MAXV 3200000
#define NUMB 32

int id(int r, int c){
    return r * NUMB + c;
}

int parent[MAXV];
bool dist[MAXV];
int start[MAXN];

pair<int, int> Find(int x){
    if(parent[x] == x) return make_pair(x,0);
    pair<int,int> r = Find(parent[x]);
    r.second ^= dist[x];
    parent[x] = r.first;
    dist[x] = r.second;
    return r;
}

bool Union(int x, int y, bool w){
    pair<int,bool> px = Find(x);
    pair<int,bool> py = Find(y);
    
    bool d = (px.second ^ py.second ^ w);
    
    if(px.first == py.first){
        if(d != 0) return false;
    }else{
        x = px.first; y = py.first;
        parent[x] = y;
        dist[x] = d;
    }
    
    return true;
}

long long ans[MAXN];
bool used[MAXV];

int main(){
    int N,Q;
    
    scanf("%d %d",&N,&Q);
    
    bool ok = true;
    
    for(int i = N * NUMB - 1;i >= 0;--i)
        parent[i] = i;
    
    for(int i = 0,op,x,y;i < Q && ok;++i){
        scanf("%d %d %d",&op,&x,&y);
        --x;
        
        if(op == 1) start[x] = (start[x] + y) % NUMB;
        else{
            --y;
            
            long long res;
            scanf("%lld",&res);
            
            for(int i = 0;i < NUMB && ok;++i){
                if(!Union(id(x,(start[x] + i) % NUMB),id(y,(start[y] + i) % NUMB),((res >> i) & 1)))
                    ok = false;
            }
        }
    }
    
    if(!ok) puts("-1");
    else{
        for(int i = 0;i < N;++i)
            for(int j = NUMB - 1;j >= 0;--j){
                int cur = id(i,j);
                pair<int,bool> r = Find(cur);
                
                if(!used[r.first]){
                    used[r.first] = true;
                    int valr = r.second;
                    if(valr) ans[r.first / NUMB] |= (1LL << (r.first % NUMB));
                }else{
                    int valr = ((ans[r.first / NUMB] >> (r.first % NUMB)) & 1);
                    valr ^= r.second;
                    if(valr) ans[i] |= (1LL << j);
                }
            }
        
        for(int i = 0;i < N;++i){
            printf("%lld",ans[i]);
            if(i == N-1) printf("\n");
            else printf(" ");
        }
    }
    
    return 0;
}
