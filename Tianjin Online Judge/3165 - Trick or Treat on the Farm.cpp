#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int next[N];
    for(int i=0;i<N;i++){
        scanf("%d",&next[i]);
        next[i]--;
    }
    
    bool visited[N];
    fill(visited,visited+N,false);
    
    int Q[N],pos[N],sz,x,L,ans[N];
    fill(ans,ans+N,-1);
    
    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        
        sz=0;
        Q[sz++]=i;
        
        while(1){
            if(visited[Q[sz-1]]){
                x=Q[sz-1];
                L=sz-pos[x];
                
                for(int i=pos[x]-1;i<sz;i++) ans[Q[i]]=L;
                for(int i=pos[x]-2;i>=0;i--){
                    L++;
                    ans[Q[i]]=L;
                }
                
                break;
            }
            
            visited[Q[sz-1]]=true;
            pos[Q[sz-1]]=sz;
            
            if(ans[next[Q[sz-1]]]!=-1){
                L=ans[next[Q[sz-1]]];
                
                for(int i=sz-1;i>=0;i--){
                    L++;
                    ans[Q[i]]=L;
                }
                
                break;
            }
            
            Q[sz]=next[Q[sz-1]];
            sz++;
        }
    }
    
    for(int i=0;i<N;i++) printf("%d\n",ans[i]);
    
    return 0;
}
