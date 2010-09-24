#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int v,d;
    
    node(){
    }
    
    node(int _v, int _d){
        v=_v;
        d=_d;
    }
    
    bool operator < (node X)const{
        return d>X.d;
    }
};

int main(){
    int V,E,s,t,M[500][500],u,v,d;
    
    priority_queue<node> Q1;
    queue<int> Q2;
    node aux;
    bool visited[500];
    int D[500];
    
    while(1){
        scanf("%d %d",&V,&E);
        if(V==0) break;
        
        scanf("%d %d",&s,&t);
        
        for(int i=0;i<V;i++) fill(M[i],M[i]+V,-1);
        
        for(int i=0;i<E;i++){
            scanf("%d %d %d",&u,&v,&d);
            M[u][v]=d;
        }
        
        fill(visited,visited+V,false);
        fill(D,D+V,-1);
        Q1.push(node(t,0));
        
        while(!Q1.empty()){
            aux=Q1.top();
            v=aux.v;
            d=aux.d;
            Q1.pop();
            
            if(visited[v]) continue;
            visited[v]=true;
            D[v]=d;
            
            for(int i=0;i<V;i++) if(M[i][v]!=-1 && !visited[i]) Q1.push(node(i,d+M[i][v]));
        }
        
        if(!visited[s]){
            printf("-1\n");
            continue;
        }
        
        fill(visited,visited+V,false);
        Q2.push(s);
        visited[s]=true;
        
        while(!Q2.empty()){
            v=Q2.front();
            Q2.pop();
            
            for(int i=0;i<V;i++){
                if(M[v][i]!=-1 && D[i]==D[v]-M[v][i]){
                    M[v][i]=-1;
                    if(!visited[i]) Q2.push(i);
                    visited[i]=true;
                }
            }
        }
        
        fill(visited,visited+V,false);
        priority_queue<node> Q3;
        Q3.push(node(s,0));
        
        while(!Q3.empty()){
            aux=Q3.top();
            v=aux.v;
            d=aux.d;
            Q3.pop();
            
            if(visited[v]) continue;
            visited[v]=true;
            
            if(v==t){
                printf("%d\n",d);
                break;
            }
            
            for(int i=0;i<V;i++) if(M[v][i]!=-1 && !visited[i]) Q3.push(node(i,d+M[v][i]));
        }
        
        if(!visited[t]) printf("-1\n");
    }
    
    return 0;
}
