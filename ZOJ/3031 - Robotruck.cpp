#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int id;
    long long cost;
    
    node(){}
    
    node(int _id, long long _cost){
        id = _id; cost = _cost;
    }
    
    bool operator < (node X)const{
        return cost > X.cost;
    }
};

int T,C,N,x[100000],y[100000],cost[100000];
long long F[100001],G[100001];

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&C,&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d %d %d",&x[i],&y[i],&cost[i]);
        
        F[0] = 0;
        
        for(int i = 1;i < N;++i)
            F[i] = F[i-1] + abs(x[i-1]-x[i]) + abs(y[i-1]-y[i]);
        
        G[0] = 0;
        
        for(int i = 1;i <= N;++i)
            G[i] = G[i-1] + cost[i-1];
        
        priority_queue<node> Q;
        Q.push(node(N,abs(x[N-1]) + abs(y[N-1]) + F[N-1]));
        
        long long ans;
        
        for(int i = N-1;i >= 0;--i){
            while(true){
                node aux = Q.top();
                
                if(G[aux.id]-G[i] <= C){
                    ans = aux.cost + abs(x[i]) + abs(y[i]) - F[i];
                    Q.push(node(i,ans + (i > 0? abs(x[i-1]) + abs(y[i-1]) + F[i-1] : 0)));
                    break;
                }else Q.pop();
            }
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
