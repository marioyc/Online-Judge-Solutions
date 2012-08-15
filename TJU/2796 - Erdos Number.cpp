#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>

using namespace std;

map<string, int> id;
vector<int> L[100000];
int dist[100000];

int main(){
    int N = 0,M;
    char s1[21],s2[21];
    
    scanf("%d",&M);
    
    id["Erdos"] = N++;
    
    for(int i = 0;i < M;++i){
        scanf("%s %s",s1,s2);
        
        if(id.find(s1) == id.end()) id[s1] = N++;
        if(id.find(s2) == id.end()) id[s2] = N++;
        
        int u = id[s1],v = id[s2];
        
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    queue<int> Q;
    memset(dist,-1,sizeof dist);
    
    dist[0] = 0;
    Q.push(0);
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            
            if(dist[to] == -1){
                dist[to] = 1 + dist[cur];
                Q.push(to);
            }
        }
    }
    
    scanf("%d",&N);
    
    while(N--){
        scanf("%s",s1);
        
        if(id.find(s1) == id.end()) puts("infinity");
        else{
            int v = id[s1];
            
            if(dist[v] == -1) puts("infinity");
            else printf("%d\n",dist[v]);
        }
    }
    
    return 0;
}
