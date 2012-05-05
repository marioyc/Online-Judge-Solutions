#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int w,h;
    vector<int> L[900];
    int dist[900];
    
    while(true){
        scanf("%d %d",&w,&h);
        
        if(w == 0) break;
        
        int V = w * h;
        
        for(int i = 0;i < V;++i)
            L[i].clear();
        
        for(int i = 0,x;i < 2*h - 1;++i){
            if(i & 1){
                for(int j = 0;j < w;++j){
                    scanf("%d",&x);
                    
                    if(!x){
                        L[(i / 2) * w + j].push_back((i / 2 + 1) * w + j);
                        L[(i / 2 + 1) * w + j].push_back((i / 2) * w + j);
                    }
                }
            }else{
                for(int j = 0;j < w - 1;++j){
                    scanf("%d",&x);
                    
                    if(!x){
                        L[(i / 2) * w + j].push_back((i / 2) * w + j + 1);
                        L[(i / 2) * w + j + 1].push_back((i / 2) * w + j);
                    }
                }
            }
        }
        
        queue<int> Q;
        
        memset(dist,-1,sizeof dist);
        
        Q.push(0);
        dist[0] = 0;
        
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            
            for(int i = L[cur].size() - 1,to;i >= 0;--i){
                to = L[cur][i];
                
                if(dist[to] == -1){
                    Q.push(to);
                    dist[to] = 1 + dist[cur];
                }
            }
        }
        
        printf("%d\n",dist[h * w - 1] + 1);
    }
    
    return 0;
}
