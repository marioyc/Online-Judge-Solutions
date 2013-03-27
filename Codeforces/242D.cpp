#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 100005

vector<int> L[MAXN];
int a[MAXN],sc[MAXN];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);
    
    vector<int> sol;
    
    queue<int> Q;
    
    for(int i = 1;i <= n;++i)
        if(a[i] == 0)
            Q.push(i);
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        
        if(sc[cur] != a[cur]) continue;
        sol.push_back(cur);
        ++sc[cur];
        
        for(int i = L[cur].size() - 1,to;i >= 0;--i){
            to = L[cur][i];
            ++sc[to];
            
            if(sc[to] == a[to]) Q.push(to);
        }
    }
    
    printf("%d\n",(int)sol.size());
    
    for(int i = 0;i < sol.size();++i)
        printf("%d ",sol[i]);
    
    printf("\n");
    
    return 0;
}
