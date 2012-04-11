#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXV 100000
#define MAXE 2 * MAXV

int to[MAXE],W[MAXE],nxt[MAXE],last[MAXV],E;
int sum[MAXV],trie[MAXV * 31][2],cont;

void add_edge(int u, int v, int w){
    to[E] = v; W[E] = w; nxt[E] = last[u]; last[u] = E++;
    to[E] = u; W[E] = w; nxt[E] = last[v]; last[v] = E++;
}

void insert(int s){
    int pos = 0;
    
    for(int i = 30,k;i >= 0;--i){
        if(s & (1 << i)) k = 1;
        else k = 0;
        
        if(trie[pos][k] == -1) trie[pos][k] = cont++;
        pos = trie[pos][k];
    }
}

void dfs(int cur, int par, int s){
    sum[cur] = s;
    insert(s);
    
    for(int e = last[cur];e != -1;e = nxt[e])
        if(to[e] != par)
            dfs(to[e],cur,s ^ W[e]);
}

int solve(int s){
    int ret = 0,pos = 0;
    
    for(int i = 30,k;i >= 0;--i){
        if(s & (1 << i)) k = 0;
        else k = 1;
        
        if(trie[pos][k] == -1) k ^= 1;
        else ret ^= (1 << i);
        
        pos = trie[pos][k];
    }
    
    return ret;
}

int main(){
    int N;
    
    while(scanf("%d",&N) == 1){
        memset(last,-1,sizeof last);
        E = 0;
        
        for(int i = 1,u,v,w;i < N;++i){
            scanf("%d %d %d",&u,&v,&w);
            add_edge(u,v,w);
        }
        
        memset(trie,-1,sizeof trie);
        cont = 1;
        
        dfs(0,-1,0);
        
        int ans = 0;
        
        for(int i = 0;i < N;++i)
            ans = max(ans,solve(sum[i]));
        
        printf("%d\n",ans);
    }
    
    return 0;
}
