#include<cstdio>

using namespace std;

int main(){    
    int V,E;
    int si,ni,ki;
    char oi[3];
    int dist[101];
    int edge[100][2];
    int edge_cost[100];
    bool cycle;
    
    while(1){
        scanf("%d",&V);
        if(V==0) break;
        V++;
        
        scanf("%d",&E);
        
        for(int i=0;i<E;i++){
            scanf("%d %d %s %d",&si,&ni,oi,&ki);
            
            if(oi[0]=='g'){
                edge[i][0]=si+ni;
                edge[i][1]=si-1;
                edge_cost[i]=-ki-1;
            }else{                
                edge[i][0]=si-1;
                edge[i][1]=si+ni;
                edge_cost[i]=ki-1;
            }
        }
        
        for(int i=0;i<V;i++) dist[i]=0;
        
        for(int i=1;i<V;i++)
            for(int j=0;j<E;j++)
                dist[edge[j][1]]<?=dist[edge[j][0]]+edge_cost[j];
        
        cycle=false;
        
        for(int j=0;j<E && !cycle;j++)
            if(dist[edge[j][1]]>dist[edge[j][0]]+edge_cost[j]) cycle=true;
        
        if(cycle) printf("successful conspiracy\n");
        else printf("lamentable kingdom\n");
    }
    
    return 0;
}
