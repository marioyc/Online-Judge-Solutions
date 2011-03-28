#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int pos,len,cost;
    
    node(){}
    
    node(int _pos, int _len, int _cost){
        pos = _pos; len = _len; cost = _cost;
    }
    
    bool operator < (node X)const{
        if(len != X.len) return len > X.len;
        return cost > X.cost;
    }
}aux;

bool visited[100][10001];

int main(){
    int T,K,N,R,price[100][100],len[100][100];
    vector<int> to[100],P[100],L[100];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&K,&N,&R);
        
        for(int i = 0;i < N;++i){
            to[i].clear();
            P[i].clear();
            L[i].clear();
        }
        
        for(int i = 0,u,v,l,p;i < R;++i){
            scanf("%d %d %d %d",&u,&v,&l,&p);
            --u; --v;
            
            to[u].push_back(v);
            L[u].push_back(l);
            P[u].push_back(p);
        }
        
        priority_queue<node> Q;
        Q.push(node(0,0,0));
        memset(visited,false,sizeof(visited));
        
        int ans = -1;
        
        while(!Q.empty()){
            aux = Q.top();
            Q.pop();
            
            if(visited[aux.pos][aux.cost]) continue;
            visited[aux.pos][aux.cost] = true;
            
            if(aux.pos == N-1){
                ans = aux.len;
                break;
            }
            
            for(int i = to[aux.pos].size()-1;i >= 0;--i){
                int pos2 = to[aux.pos][i];
                int l2 = aux.len + L[aux.pos][i];
                int cost2 = aux.cost + P[aux.pos][i];
                
                if(cost2 <= K) Q.push(node(pos2,l2,cost2));
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
