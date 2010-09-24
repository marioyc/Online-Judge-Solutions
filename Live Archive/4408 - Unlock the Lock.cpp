#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int a[10], visited[10000];

int solve(const int &L, const int &U, const int &R){
    fill(visited,visited+10000,-1);
    
    int aux,aux2;
    queue<int> Q;
    Q.push(L);
    visited[L]=0;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        for(int i=0;i<R;i++){
            aux2=(aux+a[i])%10000;
            if(visited[aux2]!=-1) continue;
            
            visited[aux2]=visited[aux]+1;
            if(aux2==U) return visited[aux2];
            
            Q.push(aux2);
        }
    }
    
    return -1;
}

int main(){
    int tc=1,L,U,R,ans;
    
    while(1){
        scanf("%d %d %d",&L,&U,&R);
        if(R==0) break;
        
        for(int i=0;i<R;i++) scanf("%d",&a[i]);
        
        ans=solve(L,U,R);
        
        printf("Case %d: ",tc++);
        
        if(ans==-1) printf("Permanently Locked\n");
        else printf("%d\n",ans);
    }
    
    return 0;
}
