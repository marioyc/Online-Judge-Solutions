#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct edge{
    int u,v,cost;
    
    edge(){
    }
    
    edge(int _u, int _v, int _cost){
        u=_u;
        v=_v;
        cost=_cost;
    }
    
    bool operator < (edge X) const{
        if(v!=X.v) return v>X.v;
        return u<X.u;
    }
};

int main(){    
    int T,V,E,Q,cost,ind1,ind2,stopovers;
    char L[100][21];
    char s1[21],s2[21];
    int dist[100];
    int min_cost[100];
    edge edges[1000];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&V);
        
        for(int i=0;i<V;i++) scanf("%s",L[i]);
        
        scanf("%d",&E);
        
        for(int i=0;i<E;i++){
            scanf("%s %s %d",s1,s2,&cost);
            
            for(int j=0;j<V;j++)
                if(strcmp(s1,L[j])==0){
                    ind1=j;
                    break;
                }
            
            for(int j=0;j<V;j++)
                if(strcmp(s2,L[j])==0){
                    ind2=j;
                    break;
                }
            
            edges[i]=edge(ind1,ind2,cost);
        }
        
        dist[0]=0;
        for(int i=1;i<V;i++) dist[i]=-1;
        
        sort(edges,edges+E);
        
        for(int i=1;i<V;i++){
            for(int j=0;j<E;j++)
                if(dist[edges[j].u]!=-1){
                    if(dist[edges[j].v]==-1) dist[edges[j].v]=dist[edges[j].u]+edges[j].cost;
                    else dist[edges[j].v]<?=dist[edges[j].u]+edges[j].cost;
                }
                
            min_cost[i-1]=dist[V-1];
        }
        
        printf("Scenario #%d\n",tc);
        
        scanf("%d",&Q);
        
        for(int i=0;i<Q;i++){
            scanf("%d",&stopovers);
            
            if(stopovers>=V-1) stopovers=V-2;
            
            if(min_cost[stopovers]==-1) printf("No satisfactory flights\n"); 
            else printf("Total cost of flight(s) is $%d\n",min_cost[stopovers]);
        }
        
        if(tc!=T) printf("\n");
    }
    
    return 0;
}
