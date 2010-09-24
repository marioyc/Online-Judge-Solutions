#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

struct edge{
    int u,p;
    
    edge(){
    }
    
    edge(const int _u, const int _p){
        u=_u; p=_p;
    }
};

int V,E,a,b,p,ans;
int ind[200000];
vector<edge> L[200000];
int dp[200000];
queue<int> Q;
bool visited[200000];
int aux,parent[200000],cost[200000];

int main(){
    while(1){
        scanf("%d",&E);
        if(E==0) break;
        
        fill(ind,ind+200000,-1);
        V=0;
        
        for(int i=0;i<200000;i++) L[i].clear();
        
        for(int i=0;i<E;i++){
            scanf("%d %d %d",&a,&b,&p);
            a--; b--;
            
            if(ind[a]==-1) ind[a]=V++;
            if(ind[b]==-1) ind[b]=V++;
            
            L[ind[a]].push_back(edge(ind[b],p));
            L[ind[b]].push_back(edge(ind[a],p));
        }
        
        fill(visited,visited+V,false);
        
        Q.push(0);
        visited[0]=true;
        
        for(int i=0;i<V;i++){
            aux=Q.front();
            ind[i]=aux;
            Q.pop();
            
            for(int j=L[aux].size()-1;j>=0;j--){
                if(visited[L[aux][j].u]) continue;
                visited[L[aux][j].u]=true;
                
                parent[L[aux][j].u]=i;
                cost[L[aux][j].u]=L[aux][j].p;
                
                Q.push(L[aux][j].u);
            }
        }
        
        fill(dp,dp+V,0);
        ans=0;
        
        for(int i=V-1;i>0;i--){
            ans>?=dp[i];
            if(dp[i]+cost[ind[i]]>0)
                dp[parent[ind[i]]]+=dp[i]+cost[ind[i]];
        }
        
        ans>?=dp[0];
        
        printf("%d\n",ans);
    }
    
    return 0;
}
