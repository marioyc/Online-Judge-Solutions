#include <iostream>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define MAXK 10000

long long K[21];
int nk = 0;
long long dist[MAXK];

void dijkstra(){
    memset(dist,-1,sizeof dist);
    priority_queue<long long> Q;
    Q.push(0);
    
    while(!Q.empty()){
        long long curd = -Q.top();
        int cur = curd % K[0];
        Q.pop();
        
        if(dist[cur] != -1) continue;
        dist[cur] = curd;
        
        for(int i = 0;i < nk;++i){
            long long to = -(curd + K[i]);
            Q.push(to);
        }
    }
}

map<long long, int> C;
priority_queue< pair<int, int> > Q;

int main(){
    ios::sync_with_stdio(0);
    
    long long h;
    int n,m,k;
    
    cin >> h >> n >> m >> k;
    
    long long a[n];
    
    for(int i = 0,c;i < n;++i){
        cin >> a[i] >> c;
        --a[i];
        C[ a[i] ] = c;
        if(a[i] % k == 0)
            Q.push(make_pair(c,-i));
    }
    
    int op;
    long long x;
    int y;
    
    memset(dist,-1,sizeof dist);
    dist[0] = 0;
    K[nk++] = k;
    
    while(m--){
        cin >> op;
        
        if(op == 1){
            cin >> x;
            K[nk++] = x;
            dijkstra();
            
            while(!Q.empty()) Q.pop();
            
            for(int i = 0;i < n;++i){
                int aux = a[i] % K[0];
                if(dist[aux] != -1 && a[i] >= dist[aux])
                    Q.push(make_pair(C[ a[i] ],-i));
            }
        }else if(op == 2){
            cin >> x >> y;
            --x;
            
            C[ a[x] ] -= y;
            
            int aux = a[x] % K[0];
            if(dist[aux] != -1 && a[x] >= dist[aux])
                Q.push(make_pair(C[ a[x] ],-x));
        }else{
            if(Q.empty()) cout << 0 << '\n';
            else{
                while(!Q.empty()){
                    pair<int, int> cur = Q.top();
                    Q.pop();
                    
                    if(C[ a[-cur.second] ] == cur.first){
                        cout << cur.first << '\n';
                        C[ a[-cur.second] ] = 0;
                        break;
                    }else if(Q.empty()) cout << 0 << '\n';
                }
            }
        }
    }
    
    return 0;
}
