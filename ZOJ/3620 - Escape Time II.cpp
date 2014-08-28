#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int cur,mask,t;
    
    node(){}
    
    node(int _cur, int _mask, int _t):
        cur(_cur),mask(_mask),t(_t){}
    
    bool operator < (node X)const{
        return t > X.t;
    }
};

int main(){
    int n,m,t,s,e,j[10],dist[10][1 << 10];
    vector<int> L[10],W[10];
    int val[1 << 10];
    
    while(scanf("%d %d %d",&n,&m,&t) == 3){
        scanf("%d %d",&s,&e);
        
        for(int i = 0;i < n;++i)
            scanf("%d",&j[i]);
        
        val[0] = 0;
        
        for(int i = 1;i < (1 << n);++i){
            int x = __builtin_ctz(i);
            val[i] = j[x] + val[i ^ (1 << x)];
        }
        
        for(int i = 0;i < n;++i){
            L[i].clear();
            W[i].clear();
        }
        
        for(int i = 0,a,b,c;i < m;++i){
            scanf("%d %d %d",&a,&b,&c);
            L[a].push_back(b);
            W[a].push_back(c);
            L[b].push_back(a);
            W[b].push_back(c);
        }
        
        int ans = 0;
        priority_queue<node> Q;
        memset(dist,-1,sizeof dist);
        
        Q.push(node(s,(1 << s),0));
        dist[0][1] = 0;
        
        while(!Q.empty()){
            node aux = Q.top();
            Q.pop();
            
            if(aux.cur == e) ans = max(ans,val[aux.mask]);
            
            for(int i = L[aux.cur].size() - 1,to,mask,t2;i >= 0;--i){
                to = L[aux.cur][i];
                mask = (aux.mask | (1 << to));
                t2 = aux.t + W[aux.cur][i];
                
                if(t2 <= t && (dist[to][mask] == -1 || t2 < dist[to][mask])){
                    Q.push(node(to,mask,t2));
                    dist[to][mask] = t2;
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
