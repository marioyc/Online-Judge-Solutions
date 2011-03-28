#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node{
    int pos,t,cost;
    
    node(){}
    
    node(int _pos, int _t, int _cost){
        pos = _pos;
        t = _t;
        cost = _cost;
    }
    
    bool operator < (node X)const{
        if(cost == X.cost) return t > X.t;
        return cost > X.cost;
    }
}aux;

int main(){
    int n,t,M1[50][50],M2[50][50];
    bool visited[50][1000];
    
    while(true){
        scanf("%d %d",&n,&t);
        if(n == 0 && t == 0) break;
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&M1[i][j]);
        
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                scanf("%d",&M2[i][j]);
        
        priority_queue<node> Q;
        Q.push(node(0,0,0));
        
        memset(visited,false,sizeof(visited));        
        
        int best_toll = -1,best_time = -1;
        
        while(!Q.empty()){
            aux = Q.top();
            Q.pop();
            
            if(visited[aux.pos][aux.t] || (best_toll != -1 && aux.cost > best_toll)) continue;
            visited[aux.pos][aux.t] = true;
            
            if(aux.pos == n-1){
                if(best_toll == -1 || aux.cost < best_toll || (aux.cost == best_toll && aux.t < best_time)){
                    best_toll = aux.cost;
                    best_time = aux.t;
                }
            }else{
                for(int i = 0;i < n;++i){
                    if(i != aux.pos){
                        int cost2 = aux.cost + M2[aux.pos][i],t2 = aux.t + M1[aux.pos][i];
                        
                        if(t2 <= t && !visited[i][t2]) Q.push(node(i,t2,cost2));
                    }
                }
            }
        }
        
        printf("%d %d\n",best_toll,best_time);
    }
    
    return 0;
}
