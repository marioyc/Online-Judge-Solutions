#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_SIZE 100

vector<int> L[MAX_SIZE];
int parent[MAX_SIZE],rank[MAX_SIZE],components;

void Make_Set(const int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(const int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y){
    int PX=Find(x),PY=Find(y);
    
    if(PX==PY) return;
    --components;
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

bool visited[MAX_SIZE];
int prev[MAX_SIZE];

int most_distant(int s){
    queue<int> Q;
    Q.push(s);
    
    memset(visited,false,sizeof(visited));
    visited[s] = true;
    prev[s] = -1;
    
    int ans = s;
    
    while(!Q.empty()){
        int aux = Q.front();
        Q.pop();
        
        ans = aux;
        
        for(int i=L[aux].size()-1;i>=0;--i){
            int v = L[aux][i];
            if(visited[v]) continue;
            visited[v] = true;
            Q.push(v);
            prev[v] = aux;
        }
    }
    
    return ans;
}

bool in_path[MAX_SIZE];

bool check(int V){
    int s = most_distant(0);
    int e = most_distant(s);
    int v = e;
    
    memset(in_path,false,sizeof(in_path));
    in_path[s] = true;
    
    while(prev[v]!=-1){
        in_path[v] = true;
        v = prev[v];
    }
    
    for(int i=0;i<V;++i){
        if(!in_path[i]){
            bool ok = false;
            
            for(int j=L[i].size()-1;j>=0;--j){
                v = L[i][j];
                if(in_path[v]) ok = true;
            }
            
            if(!ok) return false;
        }
    }
    
    return true;
}

int main(){
    int n,e,u,v;
    
    for(int tc=1;;++tc){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;++i) L[i].clear();
        for(int i=0;i<n;++i) Make_Set(i);
        
        scanf("%d",&e);
        
        for(int i=0;i<e;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            L[u].push_back(v);
            L[v].push_back(u);
            Union(u,v);
        }
        
        if(components>1 || n-e!=1){
            printf("Graph %d is not a caterpillar.\n",tc);
            continue;
        }
        
        printf("Graph %d is %sa caterpillar.\n",tc,((check(n))? "" : "not "));
    }
    
    return 0;
}
