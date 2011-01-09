#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node{
    int pos,need;
    
    node(){}
    
    node(int _pos, int _need){
        pos = _pos; need = _need;
    }
    
    bool operator < (node X)const{
        return need>X.need;
    }
}aux;

bool adj[52][52],visited[52];

int solve(int s, int e, int want){
    memset(visited,false,sizeof(visited));
    priority_queue<node> Q;
    
    Q.push(node(s,want));
    
    while(!Q.empty()){
        aux = Q.top();
        Q.pop();
        
        if(visited[aux.pos]) continue;
        visited[aux.pos] = true;
        
        if(aux.pos==e) return aux.need;
        
        int need = aux.need+1;
        
        if(aux.pos>=26){
            int lo = aux.need,hi = 2*aux.need,mi;
            
            while(lo<hi){
                mi = (lo+hi)>>1;
                
                if(mi-(mi+19)/20<aux.need) lo = mi+1;
                else hi = mi;
            }
            
            need = lo;
        }
        
        for(int i = 0;i<52;++i)
            if(i!=aux.pos && adj[aux.pos][i] && !visited[i])
                Q.push(node(i,need));
    }
    
    return -1;
}

int main(){
    int tc = 1,E,u,v,want;
    char c1,c2;
    
    while(true){
        scanf("%d",&E);
        if(E==-1) break;
        
        memset(adj,false,sizeof(adj));
        
        while(E--){
            scanf("%*[\n\t ]%c%*[\n\t ]%c",&c1,&c2);
            
            if(c1>='a' && c1<='z') u = c1-'a';
            else u = 26+c1-'A';
            
            if(c2>='a' && c2<='z') v = c2-'a';
            else v = 26+c2-'A';
            
            adj[u][v] = adj[v][u] = true;
        }
        
        scanf("%d%*[\n\t ]%c%*[\n\t ]%c",&want,&c1,&c2);
        
        if(c1>='a' && c1<='z') u = c1-'a';
        else u = 26+c1-'A';
        
        if(c2>='a' && c2<='z') v = c2-'a';
        else v = 26+c2-'A';
        
        printf("Case %d: %d\n",tc++,solve(v,u,want));
    }
    
    return 0;
}
