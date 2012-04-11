#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 600
#define MAXV 360000

int n,bit[MAXN + 1];

void update(int x, int val){
    for(int idx = x;idx <= n;idx += idx & -idx)
        bit[idx] += val;
}

int query(int x){
    int ret = 0;
    
    for(int idx = x;idx > 0;idx -= idx & -idx)
        ret += bit[idx];
    
    return ret;
}

int top[MAXN][MAXN],left[MAXN][MAXN],ans[MAXN][MAXN];
vector<int> L[MAXV];

int main(){
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j)
            scanf("%d",&top[i][j]);
    
    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j)
            scanf("%d",&left[i][j]);
    
    bool ok = true;
    int a[n],pos[n + 1];
    
    for(int c = 0;c < n && ok;++c){
        memset(bit,0,sizeof bit);
        
        for(int r = 1;r <= n;++r)
            update(r,1);
        
        for(int r = n - 1,m = n;r >= 0 && ok;--r,--m){
            int x = m - top[r][c];
            
            if(x < 0) ok = false;
            else{
                int lo = 1,hi = n,mi;
                
                while(lo < hi){
                    mi = (lo + hi) >> 1;
                    
                    if(query(mi) < x) lo = mi + 1;
                    else hi = mi;
                }
                
                update(lo,-1);
                a[r] = lo;
                pos[lo] = r;
            }
        }
        
        if(ok){
            for(int i = 0;i < n;++i){
                if(a[i] != n)
                    L[i * n + c].push_back(pos[ a[i] + 1 ] * n + c);
            }
        }
    }
    
    for(int r = 0;r < n && ok;++r){
        memset(bit,0,sizeof bit);
        
        for(int c = 1;c <= n;++c)
            update(c,1);
        
        for(int c = n - 1,m = n;c >= 0 && ok;--c,--m){
            int x = m - left[r][c];
            
            if(x  < 0) ok = false;
            else{
                int lo = 1,hi = n,mi;
                
                while(lo < hi){
                    mi = (lo + hi) >> 1;
                    
                    if(query(mi) < x) lo = mi + 1;
                    else hi = mi;
                }
                
                update(lo,-1);
                
                a[c] = lo;
                pos[lo] = c;
            }
        }
        
        if(ok){
            for(int i = 0;i < n;++i){
                if(a[i] != n)
                    L[r * n + i].push_back(r * n + pos[ a[i] + 1 ]);
            }
        }
    }
    
    if(!ok) puts("0");
    else{
        int V = n * n;
        int in[V];
        
        memset(in,0,sizeof in);
        
        for(int i = 0;i < V;++i)
            for(int j = L[i].size() - 1;j >= 0;--j)
                ++in[ L[i][j] ];
        
        queue<int> Q;
        int done = 0;
        
        for(int i = 0;i < V;++i)
            if(in[i] == 0)
                Q.push(i);
        
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            
            ans[cur / n][cur % n] = ++done;
            
            for(int i = L[cur].size() - 1,to;i >= 0;--i){
                to = L[cur][i];
                --in[to];
                
                if(in[to] == 0) Q.push(to);
            }
        }
        
        if(done != V) puts("0");
        else{
            for(int i = 0;i < n;++i){
                for(int j = 0;j < n;++j)
                    printf("%d ",ans[i][j]);
                printf("\n");
            }
        }
    }
    
    return 0;
}
