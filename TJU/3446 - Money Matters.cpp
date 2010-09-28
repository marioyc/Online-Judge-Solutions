#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    int o[n];
    for(int i=0;i<n;i++) scanf("%d",&o[i]);
    
    vector< vector<int> > L(n);
    int u,v;
    
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    bool possible=true,used[n];
    int sum;
    
    fill(used,used+n,false);
    
    for(int i=0;i<n && possible;i++){
        if(used[i]) continue;
        sum=0;
        
        queue<int> Q;
        Q.push(i);
        used[i]=true;
        
        while(!Q.empty()){
            u=Q.front();
            Q.pop();
            
            sum+=o[u];
            
            for(int i=L[u].size()-1;i>=0;i--){
                v=L[u][i];
                if(used[v]) continue;
                used[v]=true;
                Q.push(v);
            }
        }
        
        if(sum!=0) possible=false;
    }
    
    if(possible) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
    
    return 0;
}
