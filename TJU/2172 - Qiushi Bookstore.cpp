#include <cstdio>
#include <string>
#include <map>

using namespace std;

struct edge{
    int u,v,w;
    
    edge(){}
    
    bool operator < (edge X)const{
        return w<X.w;
    }
}*E;

#define MAX_SIZE 5000
int parent[MAX_SIZE],rank[MAX_SIZE];

void Make_Set(const int x){
    parent[x] = x; rank[x] = 0;
}

int Find(const int x){
    if(parent[x]!=x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y){
    int PX = Find(x),PY = Find(y);
    
    if(rank[PX]>rank[PY]) parent[PY] = PX;
    else{
        parent[PX] = PY;
        if(rank[PX]==rank[PY]) ++rank[PY];
    }
}


int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    
    E = new edge[M];
    
    map<string, int> id;
    char s1[11],s2[11];
    
    for(int i = 0,p,cont = 0;i<M;++i){
        scanf("%s %s %d",s1,s2,&E[i].w);
        
        if(id.find(s1)==id.end()) id[s1] = cont++;
        if(id.find(s2)==id.end()) id[s2] = cont++;
        
        E[i].u = id[s1];
        E[i].v = id[s2];
    }
    
    int ans = 0,comp = N;
    
    for(int i = 0;i<N;++i) Make_Set(i);
    
    for(int i = 0;i<M;++i){
        if(Find(E[i].u)!=Find(E[i].v)){
            Union(E[i].u,E[i].v);
            ans += E[i].w;
            --comp;
        }
    }
    
    ans += 10*comp;
    
    printf("The total cost is %d Yuan %d Jiao.\n",ans/10,ans%10);
    
    return 0;
}
