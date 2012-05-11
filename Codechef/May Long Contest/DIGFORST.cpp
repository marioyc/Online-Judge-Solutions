#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int pos,rem,mask,dist;
    
    node(){}
    
    node(int _pos, int _rem, int _mask, int _dist) :
        pos(_pos), rem(_rem), mask(_mask), dist(_dist){}
    
    bool operator < (node X)const{
        return dist > X.dist;
    }
};

int lcm(int a, int b){
    return a / __gcd(a,b) * b;
}

int LCM[(1 << 6)];
int N,M[100][100],d[100],dist[100][420][(1 << 6)];

int main(){
    LCM[0] = 1;
    
    for(int mask = 1;mask < (1 << 6);++mask){
        int x = __builtin_ctz(mask);
        LCM[mask] = lcm(LCM[mask ^ (1 << x)],x + 2);
    }
    
    while(true){
        scanf("%d",&N);
        
        if(N == 0) break;
        
        for(int i = 0;i < N;++i)
            scanf("%d",&d[i]);
        
        for(int i = 0;i < N;++i)
            for(int j = 0;j < N;++j)
                scanf("%d",&M[i][j]);
        
        priority_queue<node> Q;
        memset(dist,-1,sizeof dist);
        int ans = -1;
        
        Q.push(node(0,d[0],d[0] == 1? 0 : (1 << (d[0] - 2)),d[0]));
        dist[0][d[0]][d[0] == 1? 0 : (1 << (d[0] - 2))] = d[0];
        
        while(!Q.empty()){
            node cur = Q.top();
            Q.pop();
            
            if(cur.dist > dist[cur.pos][cur.rem][cur.mask]) continue;
            
            if(cur.pos == N - 1 && cur.rem % LCM[cur.mask] == 0){
                ans = cur.dist;
                break;
            }
            
            for(int i = 0;i < N;++i){
                if(M[cur.pos][i]){
                    int rem = (cur.rem * 10 + d[i]) % 420;
                    int mask = (cur.mask | (d[i] == 1? 0 : (1 << (d[i] - 2))));
                    
                    if(dist[i][rem][mask] == -1 || cur.dist + d[i] < dist[i][rem][mask]){
                        Q.push(node(i,rem,mask,cur.dist + d[i]));
                        dist[i][rem][mask] = cur.dist + d[i];
                    }
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
