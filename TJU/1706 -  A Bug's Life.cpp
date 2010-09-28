#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector< vector<int> > L;
bool M[2000][2000];
int color[2000];

bool bipartite(int &V){
    fill(color,color+V,-1);
    
    int aux,v;
    queue<int> Q;
    
    for(int i=0;i<V;i++){
        if(color[i]==-1){
            color[i]=0;
            Q.push(i);
            
            while(!Q.empty()){
                aux=Q.front();
                Q.pop();
                
                for(int j=L[aux].size()-1;j>=0;j--){
                    v=L[aux][j];
                    if(color[v]==color[aux]) return false;
                    if(color[v]==-1){
                        Q.push(v);
                        color[v]=1-color[aux];
                    }
                }
            }
        }
    }
    
    return true;
}

int main(){
    int T,V,E,u,v;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&V,&E);
        
        L.clear();
        L.resize(V);
        
        for(int i=0;i<V;i++) fill(M[i],M[i]+V,false);
        
        for(int i=0;i<E;i++){
            scanf("%d %d",&u,&v);
            u--; v--;
            if(!M[u][v]){
                M[u][v]=M[v][u]=true;
                L[u].push_back(v);
                L[v].push_back(u);
            }
        }
        
        printf("Scenario #%d:\n",tc);
        if(bipartite(V)) printf("No suspicious bugs found!\n\n");
        else printf("Suspicious bugs found!\n\n");
    }
    
    return 0;
}
