#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,E,last[500],next[250000],to[250000];
int q[500],head,tail;

void add_edge(int u, int v){
    to[E] = v; next[E] = last[u]; last[u] = E++;
}

int l[500],r[500],dl[500],dr[500];
bool visited[500];

bool bfs(){
    memset(dl,-1,sizeof dl);
    memset(dr,-1,sizeof dr);
    head = tail = 0;
    
    bool found = false;
    
    for(int i = 0;i < n;++i){
        if(r[i] == -1){
            q[tail++] = i;
            dl[i] = 0;
        }
    }
    
    while(head < tail){
        int cur = q[head++];
        
        for(int e = last[cur];e != -1;e = next[e]){
            if(to[e] != r[cur] && dr[ to[e] ] == -1){
                dr[ to[e] ] = dl[cur] + 1;
                
                if(l[ to[e] ] == -1) found = true;
                
                if(l[ to[e] ] != -1 && dl[ l[ to[e] ] ] == -1){
                    q[tail++] = l[ to[e] ];
                    dl[ l[ to[e] ] ] = dl[cur] + 2;
                }
            }
        }
    }
    
    return found;
}

bool dfs(int pos){
    if(visited[pos]) return 0;
    visited[pos] = 1;
    
    for(int e = last[pos];e != -1;e = next[e]){
        if(dr[ to[e] ] == dl[pos] + 1 && (l[ to[e] ] == -1 || dfs(l[ to[e] ]))){
            r[pos] = to[e];
            l[ to[e] ] = pos;
            return 1;
        }
    }
    
    return 0;
}

int main(){
    int a[500],b[500];
    
    while(true){
        scanf("%d %d",&n,&m);
        
        if(n == 0) break;
        
        for(int i = 0;i < n;++i) scanf("%d",&a[i]);
        for(int i = 0;i < m;++i) scanf("%d",&b[i]);
        
        memset(last,-1,sizeof last);
        E = 0;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                if(__gcd(a[i],b[j]) > 1)
                    add_edge(i,j);
        
        memset(l,-1,sizeof l);
        memset(r,-1,sizeof r);
        
        int ans = 0;
        bool change = true;
        
        while(bfs()){
            memset(visited,0,sizeof visited);
            
            for(int i = 0;i < n;++i)
                if(r[i] == -1)
                    change |= dfs(i);
        }
        
        for(int i = 0;i < n;++i)
            if(r[i] != -1) ++ans;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
