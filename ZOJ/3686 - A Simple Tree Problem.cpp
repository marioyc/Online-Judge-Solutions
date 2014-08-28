#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 100005

vector<int> L[MAXN];
int pos,s[MAXN],e[MAXN];
bool flag[8 * MAXN];

void dfs(int cur){
    flag[pos] = true;
    s[cur] = pos++;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        dfs(to);
    }
    
    e[cur] = pos++;
}

int ones[8 * MAXN],zeros[8 * MAXN];

void init(int node, int l, int r){
    if(l == r){
        if(flag[l]){
            zeros[node] = 1;
            ones[node] = 0;
        }else{
            zeros[node] = 0;
            ones[node] = 0;
        }
    }else{
        int mi = (l + r) >> 1;
        
        init(2 * node + 1,l,mi);
        init(2 * node + 2,mi + 1,r);
        
        ones[node] = ones[2 * node + 1] + ones[2 * node + 2];
        zeros[node] = zeros[2 * node + 1] + zeros[2 * node + 2];
    }
}

void push(int node, int l, int r){
    if(flag[node]){
        swap(ones[node],zeros[node]);
        flag[node] = 0;
        
        if(l != r){
            flag[2 * node + 1] ^= 1;
            flag[2 * node + 2] ^= 1;
        }
    }
}

void pull(int node){
    ones[node] = ones[2 * node + 1] + ones[2 * node + 2];
    zeros[node] = zeros[2 * node + 1] + zeros[2 * node + 2];
}

int query(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(y < l || x > r) return 0;
    if(x <= l && r <= y) return ones[node];
    
    int mi = (l + r) >> 1;
    int ret = query(2 * node + 1,l,mi,x,y) + query(2 * node + 2,mi + 1,r,x,y);
    pull(node);
    return ret;
}

void update(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(y < l || x > r) return;
    if(x <= l && r <= y){
        flag[node] ^= 1;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        update(2 * node + 1,l,mi,x,y);
        update(2 * node + 2,mi + 1,r,x,y);
        pull(node);
    }
}

int main(){
    int N,M,v;
    char op[2];
    
    while(scanf("%d %d",&N,&M) == 2){
        for(int i = 1;i <= N;++i)
            L[i].clear();
        
        for(int i = 2,p;i <= N;++i){
            scanf("%d",&p);
            L[p].push_back(i);
        }
        
        memset(flag,false,sizeof flag);
        pos = 0;
        dfs(1);
        
        init(0,0,2 * N - 1);
        
        memset(flag,false,sizeof flag);
        
        while(M--){
            scanf("%s %d",op,&v);
            
            if(op[0] == 'o') update(0,0,2 * N - 1,s[v],e[v]);
            else printf("%d\n",query(0,0,2 * N - 1,s[v],e[v]));
        }
        
        printf("\n");
    }
    
    return 0;
}
