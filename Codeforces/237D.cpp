#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 100001

vector<int> L[MAXN];
int m;
int ans1[MAXN],ans2[MAXN],cont = 0;

void dfs(int cur, int prev, int id){
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != prev){
            printf("2 %d %d\n",cur,to);
            ans1[cont] = id; ans2[cont] = ++m;
            ++cont;
            dfs(to,cur,m);
        }
    }
}

int main(){
    int n,u,v;
    
    scanf("%d",&n);
    printf("%d\n",n - 1);
    
    for(int i = 1;i < n;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    m = 1;
    printf("2 %d %d\n",u,v);
    
    dfs(u,v,1);
    dfs(v,u,1);
    
    for(int i = 0;i < cont;++i)
        printf("%d %d\n",ans1[i],ans2[i]);
    
    return 0;
}
