#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

#define MAX_V 500

int M[MAX_V][MAX_V],w[MAX_V];
bool A[MAX_V],merged[MAX_V];

int minCut(int n){
    int best = INT_MAX;
    for(int i=1;i<n;++i) merged[i] = false;
    merged[0] = true;
    
    for(int phase=1;phase<n;++phase){
        A[0] = true;
        
        for(int i=1;i<n;++i){
            if(merged[i]) continue;
            A[i] = false;
            w[i] = M[0][i];
        }
        
        int prev = 0,next;
        
        for(int i=n-1-phase;i>=0;--i){
            // hallar siguiente vértice que no esté en A
            next = -1;
            
            for(int j=1;j<n;++j)
                if(!A[j] && (next==-1 || w[j]>w[next]))
                    next = j;
            
            A[next] = true;
            
            if(i>0){
                prev = next;
                
                // actualiza los pesos
                for(int j=1;j<n;++j)
                    if(!A[j]) w[j] += M[next][j];
            }
        }
        
        if(best>w[next]) best = w[next];
        
        // mezcla s y t
        for(int i=0;i<n;++i){
            M[i][prev] += M[next][i];
            M[prev][i] += M[next][i];
        }
        
        merged[next] = true;
    }
    
    return best;
}

int main(){
    int n,m,u,v,c;
    
    while(scanf("%d %d",&n,&m)==2){
        memset(M,0,sizeof(M));
        
        for(int i=0;i<m;++i){
            scanf("%d %d %d",&u,&v,&c);
            M[u][v] += c;
            M[v][u] += c;
        }
        
        printf("%d\n",minCut(n));
    }
    
    return 0;
}

