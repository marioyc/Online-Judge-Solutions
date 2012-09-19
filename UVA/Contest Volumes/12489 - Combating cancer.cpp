#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define MAXN 10000
#define B 10007

unsigned int hash_vector(vector<int> &v){
    unsigned int h = 0;
    
    while(!v.empty()){
        h = v.back() + B * h;
        v.pop_back();
    }
    
    return h;
}

map<unsigned int, int > M;
char S[2 * MAXN];
int cont;
 
int hash(int l, int r){
    if(l > r) return 0;
    vector<int> v;
   
    for(int i = l + 1,s = l + 1,aux = 0;i < r;++i){
        if(S[i] == '0') ++aux;
        else --aux;
       
        if(aux == 0){
            v.push_back(hash(s,i));
            s = i + 1;
        }
    }
   
    if(!v.empty()) sort(v.begin(),v.end());
    
    int h = hash_vector(v);
    
    if(M.find(h) == M.end()) M[h] = cont++;
    return M[h];
}

int nxt[2 * MAXN],last[MAXN],to[2 * MAXN],E = 0;

void add_edge(int u, int v){
    nxt[E] = last[u]; last[u] = E; to[E] = v; ++E;
    nxt[E] = last[v]; last[v] = E; to[E] = u; ++E;
}

int sz;

void dfs(int pos, int p = -1){
    S[sz++] = '0';
    
    for(int e = last[pos],v;e != -1;e = nxt[e]){
        v = to[e];
        if(v != p) dfs(v,pos);
    }
    
    S[sz++] = '1';
}

int parent[MAXN];

int get_farthest(int st){
    int ret = st;
    queue<int> Q;
    memset(parent,-1,sizeof parent);
    
    parent[st] = -2;
    Q.push(st);
    
    while(!Q.empty()){
        ret = Q.front();
        Q.pop();
        
        for(int e = last[ret],v;e != -1;e = nxt[e]){
            v = to[e];
            
            if(parent[v] == -1){
                parent[v] = ret;
                Q.push(v);
            }
        }
    }
    
    return ret;
}

int path[MAXN];

vector<int> hash_tree(bool flag){
    int u = get_farthest(0);
    int v = get_farthest(u);
    int len = 0;
    
    while(v != u){
        path[len++] = v;
        v = parent[v];
    }
    
    path[len++] = u;
    
    vector<int> ret;
    
    sz = 0;
    dfs(path[len / 2]);
    int h = hash(0,sz - 1);
    ret.push_back(h);
    
    if(flag && len % 2 == 0){
        sz = 0;
        dfs(path[len / 2 - 1]);
        h = hash(0,sz - 1);
        ret.push_back(h);
    }
    
    return ret;
}

int main(){
    int N;
    
    while(scanf("%d",&N) == 1){
        memset(last,-1,sizeof last);
        E = 0;
        
        for(int i = 1,u,v;i < N;++i){
            scanf("%d %d",&u,&v);
            add_edge(u - 1,v - 1);
        }
        
        M.clear();
        cont = 1;
        
        int h1 = hash_tree(false).back();
        
        memset(last,-1,sizeof last);
        E = 0;
        
        for(int i = 1,u,v;i < N;++i){
            scanf("%d %d",&u,&v);
            add_edge(u - 1,v - 1);
        }
        
        vector<int> h2 = hash_tree(true);
        int n2 = h2.size();
        bool found = false;
        
        for(int i = 0;i < n2;++i)
            found |= h2[i] == h1;
        
        puts(found? "S" : "N");
    }
    
    return 0;
}
