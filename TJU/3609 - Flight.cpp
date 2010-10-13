#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct node{
    int pos;
    long long dist;
    
    node(){}
    node(int pos, long long dist) : pos(pos), dist(dist){}
    
    bool operator < (node X)const{
        return dist>X.dist;
    }
};

vector< vector<node> > L1,L2;

void dijkstra(int V, int s, long long dist[], vector< vector<node> > &L){
    fill(dist,dist+V,-1);
    
    priority_queue<node> Q;
    Q.push(node(s,0));
    
    int u,v;
    long long d,d2;
    
    while(!Q.empty()){
        u = Q.top().pos;
        d = Q.top().dist;
        Q.pop();
        
        if(dist[u]!=-1) continue;
        dist[u] = d;
        
        for(int i = L[u].size()-1;i>=0;--i){
            v = L[u][i].pos;
            d2 = L[u][i].dist;
            
            if(dist[v]==-1) Q.push(node(v,d+d2));
        }
    }
}

int U[500000],V[500000],D[500000];

int main(){
    int N,M;
    long long distS[100000],distE[100000];
    char name1[11],name2[11];
    map<string, int> id;
    
    while(scanf("%d %d",&N,&M)==2){
        id.clear();
        L1.clear(); L1.resize(N);
        L2.clear(); L2.resize(N);
        
        for(int i = 0,cont = 0,u,v;i<M;++i){
            scanf("%s %s %d",name1,name2,&D[i]);
            
            if(id.find(name1)==id.end()) id[name1] = cont++;
            if(id.find(name2)==id.end()) id[name2] = cont++;
            
            U[i] = id[name1]; V[i] = id[name2];
            
            L1[U[i]].push_back(node(V[i],D[i]));
            L2[V[i]].push_back(node(U[i],D[i]));
        }
        
        scanf("%s %s",name1,name2);
        
        int S = id[name1], E = id[name2];
        
        dijkstra(N,S,distS,L1);
        dijkstra(N,E,distE,L2);
        
        long long ans = -1;
        
        for(int i = 0;i<M;++i){
            if(distS[U[i]]!=-1 && distE[V[i]]!=-1){
                long long aux = distS[U[i]]+D[i]/2+distE[V[i]];
                if(ans==-1 || aux<ans) ans = aux;
            }
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
