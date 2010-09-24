#include <cstdio>
#include <vector>

using namespace std;

int main(){    
    int N,u,v;
    
    scanf("%d",&N);
    
    vector< vector<int> > L(N);
    vector< vector<int> > children(N);
    
    for(int i=1;i<N;i++){
        scanf("%d %d",&u,&v);
        
        L[u-1].push_back(v-1);
        L[v-1].push_back(u-1);
    }
    
    int Q[N],size=0;
    Q[size++]=0;
    
    bool visited[N];
    memset(visited,false,sizeof(visited));
    visited[0]=true;
    
    int aux;
    
    for(int i=0;i<N;i++){
        aux=Q[i];
        
        for(int i=0;i<L[aux].size();i++){
            if(visited[L[aux][i]]) continue;
            
            visited[L[aux][i]]=true;
            children[aux].push_back(L[aux][i]);
            Q[size++]=L[aux][i];
        }
    }
    
    int dp_in[N];
    int dp_out[N];
    
    for(int i=N-1;i>=0;i--){
        if(children[Q[i]].size()==0){
            dp_in[Q[i]]=1;
            dp_out[Q[i]]=N;
        }
        
        dp_in[Q[i]]=1;
        dp_out[Q[i]]=0;
        
        for(int j=0;j<children[Q[i]].size();j++){
            dp_in[Q[i]]+=min(dp_in[children[Q[i]][j]],dp_out[children[Q[i]][j]]);
            dp_out[Q[i]]+=dp_in[children[Q[i]][j]];
        }
    }
    
    printf("%d",min(dp_in[0],dp_out[0]));
    
    return 0;
}
