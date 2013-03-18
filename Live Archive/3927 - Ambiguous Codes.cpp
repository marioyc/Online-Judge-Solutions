#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 100
#define MAXLEN 50

char s[MAXN][MAXLEN + 1];
int len[MAXN];
vector<int> L[MAXN][MAXLEN];
int dist[MAXN][MAXLEN + 1];

struct node{
    int id,pos,dist;
    
    node(){}
    node(int _id, int _pos, int _dist):
        id(_id), pos(_pos), dist(_dist){}
    
    bool operator < (node X)const{
        return dist > X.dist;
    }
};

int main(){
    int N;
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i){
            scanf("%s",s[i]);
            len[i] = strlen(s[i]);
        }
        
        for(int i = 0;i < N;++i){
            for(int j = len[i] - 1;j >= 0;--j){
                L[i][j].clear();
                
                for(int k = 0;k < N;++k){
                    if(j != 0 || k != i){
                        bool match = true;
                        
                        int pi = j,pk = 0;
                        
                        while(pi < len[i] && pk < len[k] && match){
                            if(s[i][pi] != s[k][pk]) match = false;
                            ++pi; ++pk;
                        }
                        
                        if(match) L[i][j].push_back(k);
                    }
                }
            }
        }
        
        priority_queue<node> Q;
        memset(dist,-1,sizeof dist);
        int ans = -1;
        
        for(int i = 0;i < N;++i){
            Q.push(node(i,0,len[i]));
            dist[i][0] = len[i];
        }
        
        while(!Q.empty()){
            node cur = Q.top();
            Q.pop();
            
            if(cur.dist != dist[cur.id][cur.pos]) continue;
            if(cur.pos == len[cur.id]){
                ans = cur.dist;
                break;
            }
            
            for(int i = L[cur.id][cur.pos].size() - 1,to;i >= 0;--i){
                to = L[cur.id][cur.pos][i];
                
                int match = min(len[to],len[cur.id] - cur.pos);
                int d = cur.dist + len[to] - match;
                
                if(dist[to][match] == -1 || d < dist[to][match]){
                    if(match == len[to]){
                        Q.push(node(cur.id,cur.pos + len[to],d));
                        dist[cur.id][cur.pos + len[to]] = d;
                    }else{
                        Q.push(node(to,match,d));
                        dist[to][match] = d;
                    }
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
