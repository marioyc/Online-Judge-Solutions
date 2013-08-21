#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct edge{
    int to,sum;
    
    edge(){}
    
    edge(int to, int sum) : to(to), sum(sum) {}
};

vector<edge> L[1000];
bool visited[1000][2];
int value[1000][2];
double calc[1000];

void dfs(int pos, int d, int val){
    if(visited[pos][d]) return;
    visited[pos][d] = true;
    
    value[pos][d] = val;
    calc[pos] += val;
    
    for(int i = L[pos].size() - 1,to;i >= 0;--i)
        dfs(L[pos][i].to,d ^ 1,L[pos][i].sum - val);
}

int main(){
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    for(int i = 0,a,b,c;i < M;++i){
        scanf("%d %d %d",&a,&b,&c);
        --a; --b;
        
        L[a].push_back(edge(b,c));
        L[b].push_back(edge(a,c));
    }
    
    memset(visited,false,sizeof(visited));
    
    for(int i = 0;i < N;++i)
        if(!visited[i][0] && !visited[i][1])
            dfs(i,0,0);
    
    bool ok = true;
    
    for(int i = 0;i < N && ok;++i){
        if(!visited[i][0] || !visited[i][1]) ok = false;
        else calc[i] /= 2;
    }
    
    for(int i = 0;i < N;++i){
        for(int j = L[i].size() - 1,to,sum;j >= 0;--j){
            to = L[i][j].to;
            sum = L[i][j].sum;
            
            if(visited[i][0] && visited[to][1] && sum != value[i][0] + value[to][1]) ok = false;
            if(visited[i][1] && visited[to][0] && sum != value[i][1] + value[to][0]) ok = false;
        }
    }
    
    if(!ok) puts("IMPOSSIBLE");
    else{
        for(int i = 0;i < N;++i)
            printf("%.1f\n",calc[i]);
    }
    
    return 0;
}
