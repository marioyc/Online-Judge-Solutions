#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int pos,pages;
    long long dist;
    
    node(){}
    
    node(int _pos, int _pages, long long _dist){
        pos = _pos; pages = _pages; dist = _dist;
    }
    
    bool operator < (node X)const{
        return dist>X.dist;
    }
}aux;

int N,P,pages[100];
vector<int> L[100],W[100];
long long visited[100][(1<<10)];

long long solve(){
    memset(visited,-1,sizeof(visited));
    priority_queue<node> Q;
    
    visited[0][pages[0]] = 0;
    Q.push(node(0,pages[0],0));
    
    int nxt,p;
    long long dist;
    
    while(!Q.empty()){
        aux = Q.top();
        Q.pop();
        
        if(aux.dist>visited[aux.pos][aux.pages]) continue;
        if(aux.pos==0 && aux.pages==(1<<P)-1) return aux.dist;
        
        for(int i = L[aux.pos].size()-1;i>=0;--i){
            nxt = L[aux.pos][i];
            p = (aux.pages | pages[nxt]);
            dist = aux.dist+W[aux.pos][i];
            
            if(visited[nxt][p]==-1 || dist<visited[nxt][p]){
                visited[nxt][p] = dist;
                Q.push(node(nxt,p,dist));
            }
        }
    }
    
    return -1;
}

int main(){
    while(true){
        scanf("%d %d",&N,&P);
        if(N==0) break;
        
        for(int i = 0;i<N;++i){
            L[i].clear();
            W[i].clear();
        }
        
        memset(pages,0,sizeof(pages));
        
        for(int i = 0,K,C;i<N;++i){
            scanf("%d",&K);
            
            for(int j = 0,p;j<K;++j){
                scanf("%d",&p);
                --p;
                pages[i] |= (1<<p);
            }
            
            scanf("%d",&C);
            
            for(int j = 0,to,w;j<C;++j){
                scanf("%d %d",&to,&w);
                --to;
                L[i].push_back(to);
                W[i].push_back(w);
            }
        }
        
        printf("%lld\n",solve());
    }
    
    return 0;
}
