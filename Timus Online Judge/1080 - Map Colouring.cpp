#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    bool M[100][100];
    memset(M,false,sizeof(M));
    
    for(int i = 0,x;i<N;++i){
        while(true){
            scanf("%d",&x);
            if(x==0) break;
            
            --x;
            M[i][x] = M[x][i] = true;
        }
    }
    
    int colour[100],Q[100],head,tail;
    memset(colour,-1,sizeof(colour));
    bool bipartite = true;
    
    for(int i = 0;i<N;++i){
        if(colour[i]!=-1) continue;
        
        head = tail = 0;
        Q[0] = i; ++tail;
        colour[0] = 0;
        
        while(head<tail){
            int cur = Q[head]; ++head;
            
            for(int i = 0;i<N;++i){
                if(!M[cur][i]) continue;
                
                if(colour[i]==-1){
                    Q[tail] = i; ++tail;
                    colour[i] = 1-colour[cur];
                }else{
                    if(colour[i]==colour[cur])
                        bipartite = false;
                }
            }
        }
    }
    
    if(!bipartite) printf("-1\n");
    else{
        for(int i = 0;i<N;++i) printf("%d",colour[i]);
        putchar('\n');
    }
    
    return 0;
}
