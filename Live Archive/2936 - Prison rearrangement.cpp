#include <cstdio>
#include <cstring>

using namespace std;

int parent[400];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

int N,a[400],b[400];

bool done[400][200][201],memo[400][200][201];

bool solve(int pos, int total, int diff){
    if(total < 0) return false;
    if(pos == -1) return total == 0 && diff == 0;
    
    bool &ret = memo[pos][total][diff + 100];
    
    if(!done[pos][total][diff + 100]){
        ret = solve(pos - 1,total - a[pos] - b[pos],diff + a[pos] - b[pos]) || solve(pos - 1,total,diff);
        done[pos][total][diff + 100] = true;
    }
    
    return ret;
}

int main(){
    int T,n,m;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&m);
        
        for(int i = 2*n - 1;i >= 0;--i)
            parent[i] = i;
        
        for(int i = 0,u,v;i < m;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            Union(u,n + v);
        }
        
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        N = 0;
        
        for(int i = 2*n - 1;i >= 0;--i){
            if(parent[i] == i){
                for(int j = 2*n - 1;j >= 0;--j){
                    if(Find(j) == i){
                        if(j >= n) ++b[N];
                        else ++a[N];
                    }
                }
                
                ++N;
            }
        }
        
        memset(done,false,sizeof done);
        
        int ans = 0;
        
        for(int i = n / 2;i >= 0;--i){
            if(solve(N - 1,2*i,0)){
                ans = i;
                break;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
