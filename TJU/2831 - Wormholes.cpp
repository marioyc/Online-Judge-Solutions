#include<cstdio>

using namespace std;

int main(){    
    int T,V,E,M,W,u,v,cost;
    int edge[5200][2];
    int edge_cost[5200];
    int dist[500];
    bool found;
    
    scanf("%d",&T);
    
    for(int tc=0;tc<T;tc++){
        scanf("%d %d %d",&V,&M,&W);
        E=2*M+W;        
        
        for(int i=0;i<E;){
            scanf("%d %d %d",&u,&v,&cost);
            u--; v--;
            
            if(i<2*M){
                edge[i][0]=u;
                edge[i][1]=v;
                edge_cost[i]=cost;
                
                edge[i+1][0]=v;
                edge[i+1][1]=u,
                edge_cost[i+1]=cost;
                
                i+=2;
            }else{
                edge[i][0]=u;
                edge[i][1]=v;
                edge_cost[i]=-cost;
                
                i++;
            }
        }
                
        for(int i=0;i<V;i++) dist[i]=0;
        
        for(int i=1;i<V;i++)
            for(int j=0;j<E;j++)
                dist[edge[j][1]]<?=dist[edge[j][0]]+edge_cost[j];
        
        found=false;
        
        for(int j=0;j<E && !found;j++)
                if(dist[edge[j][1]]>dist[edge[j][0]]+edge_cost[j]) found=true;
        
        if(found) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
