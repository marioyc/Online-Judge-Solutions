#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int stack[30];
    int pos[31];
    int moves[57];
    int N,K,ind;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&stack[i]);
        
        for(int i=0;i<N;i++) pos[stack[i]]=i+1;
        
        K=0;
        
        for(int i=N;i>=2;i--){
            if(pos[i]!=i){
                if(pos[i]!=1){
                    moves[K++]=pos[i];
                    
                    ind=pos[i];
                    
                    for(int j=0;j<ind/2;j++){
                        swap(stack[j],stack[ind-j-1]);
                        swap(pos[stack[j]],pos[stack[ind-j-1]]);
                    }
                }
                moves[K++]=i;
                
                for(int j=0;j<i/2;j++){
                    swap(stack[j],stack[i-j-1]);
                    swap(pos[stack[j]],pos[stack[i-j-1]]);
                }
            }            
        }
        
        printf("%d",K);
        for(int i=0;i<K;i++) printf(" %d",moves[i]);
        printf("\n");
    }
    
    return 0;
}
