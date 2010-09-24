#include<cstdio>

using namespace std;

int main(){    
    int T,V,E;
    int edge[2000][2];
    int edge_cost[2000];
    int dist[1000];
    bool reached[1000];
    bool found;
    
    scanf("%d",&T);
    
    for(int tc=0;tc<T;tc++){
        scanf("%d %d",&V,&E);
        
        for(int i=0;i<E;i++) scanf("%d %d %d",&edge[i][0],&edge[i][1],&edge_cost[i]);
        
        dist[0]=0;
        reached[0]=true;
        for(int i=1;i<V;i++) reached[i]=false;
        
        for(int i=1;i<V;i++)
            for(int j=0;j<E;j++)
                if(reached[edge[j][0]]){
                    if(!reached[edge[j][1]]){
                        dist[edge[j][1]]=dist[edge[j][0]]+edge_cost[j];
                        reached[edge[j][1]]=true;
                    }else dist[edge[j][1]]<?=dist[edge[j][0]]+edge_cost[j];
                }
        
        found=false;
        
        for(int j=0;j<E && !found;j++)
                if(reached[edge[j][0]])
                    if(!reached[edge[j][1]] || dist[edge[j][1]]>dist[edge[j][0]]+edge_cost[j]) found=true;
        
        if(found) printf("possible\n");
        else printf("not possible\n");
    }
    
    return 0;
}
