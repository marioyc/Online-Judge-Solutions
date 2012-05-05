#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int pos,n,dist;
    
    node(int _pos, int _n, int _dist) : pos(_pos), n(_n), dist(_dist){}
    
    bool operator < (node X)const{
        return dist > X.dist;
    }
};

vector<int> L[100],W[100];
int dist[100][100];

int main(){
    int n,m,c;
    
    while(true){
        scanf("%d %d %d",&n,&m,&c);
        
        if(n == 0) break;
        
        for(int i = 0;i < n;++i){
            L[i].clear();
            W[i].clear();
        }
        
        for(int i = 0,u,v,w;i < m;++i){
            scanf("%d %d %d",&u,&v,&w);
            --u; --v;
            
            L[u].push_back(v);
            W[u].push_back(w);
        }
        
        int lo = 0,hi = n - 1,mi;
        
        while(lo < hi){
			mi = (lo + hi) >> 1;
			
			priority_queue<node> Q;
			memset(dist,-1,sizeof dist);
			bool ok = false;
			
			Q.push(node(0,mi,0));
			dist[0][mi] = 0;
			
			while(!Q.empty()){
				node cur = Q.top();
				Q.pop();
				
				if(cur.dist > dist[cur.pos][cur.n] || cur.dist > c) continue;
				
				if(cur.pos == n - 1){
                    ok = true;
                    break;
                }
				
				for(int i = L[cur.pos].size() - 1,to;i >= 0;--i){
					to = L[cur.pos][i];
					
					if(dist[to][cur.n] == -1 || W[cur.pos][i] + cur.dist < dist[to][cur.n]){
						Q.push(node(to,cur.n,W[cur.pos][i] + cur.dist));
						dist[to][cur.n] = W[cur.pos][i] + cur.dist;
					}
					
					if(cur.n > 0 && (dist[to][cur.n - 1] == -1 || cur.dist < dist[to][cur.n - 1])){
						Q.push(node(to,cur.n - 1,cur.dist));
						dist[to][cur.n - 1] = cur.dist;
					}
				}
			}
			
			if(ok) hi = mi;
			else lo = mi + 1;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
