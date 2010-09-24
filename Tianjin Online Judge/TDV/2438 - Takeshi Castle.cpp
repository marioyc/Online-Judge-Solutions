#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int M,d[30000],x[50],y[50];
long long dist2[50][50];
bool visited[50];

bool possible(int n){
    queue<int> Q;
    Q.push(0);
    
    for(int i=M-1;i>0;i--) visited[i]=false;
    visited[0]=true;
    
    int aux;
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        if(aux==M-1) return true;
        
        for(int i=M-1+1;i>0;i--){
            if(!visited[i] && dist2[aux][i]<=d[n]){
                visited[i]=true;
                Q.push(i);
            }
        }
    }
    
    return false;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,cont,lo,hi,mi;
    
    while(1){
        scanf("%d %d",&N,&M);
        if(N<0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&d[i]);
        sort(d,d+N);
        for(int i=0;i<N;i++) d[i]=d[i]*d[i];
        
        scanf("%d %d %d %d",&x[0],&y[0],&x[M-1],&y[M-1]);
        
        for(int i=1;i<M-1;i++) scanf("%d %d",&x[i],&y[i]);
        
        for(int i=0;i<M;i++)
            for(int j=i+1;j<M;j++)
                dist2[i][j]=dist2[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        
        lo=0; hi=N-1;
        while(lo!=hi){
            mi=(lo+hi)/2;
            
            if(possible(mi)) hi=mi;
            else lo=mi+1;
        }
        
        if(hi>=N) printf("valid\n");
        else{
            cont=N-hi;
            if(cont>N/2) printf("NOT valid\n");
            else printf("valid\n");
        }
    }
    
    return 0;
}
