#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct node{
    int v,dist;
    
    node(){}
    
    node(int _v, int _dist){
        v = _v; dist = _dist;
    }
}aux;

#define MAX_V 10000

bool visited[MAX_V];
vector<int> L[MAX_V];

node search(int v){
    node ans = node(v,0);
    queue<node> Q;
    Q.push(node(v,0));
    
    memset(visited,false,sizeof(visited)); 
    visited[v] = true;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        ans = aux;
        
        for(int i=L[aux.v].size()-1;i>=0;--i){
            if(visited[L[aux.v][i]]) continue;
            visited[L[aux.v][i]] = true;
            Q.push(node(L[aux.v][i],aux.dist+1));
        }
    }
    
    return ans;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,u,v;
    scanf("%d",&N);
    
    for(int i=1;i<N;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    printf("%d\n",search(search(0).v).dist);
    
    return 0;
}
