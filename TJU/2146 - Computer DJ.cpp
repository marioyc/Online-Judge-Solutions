#include <cstdio>

using namespace std;

int main(){
    int N,Q,x;
    char L[26][101];
    
    int pot,pos;
    
    while(1){
        scanf("%d %d",&N,&Q);
        if(N==0 && Q==0) break;
        
        for(int i=0;i<N;i++) scanf("%s",L[i]);
        
        for(int k=0;k<Q;k++){
            scanf("%d",&x);
            
            if(N==1){
                printf("%s\n",L[0]);
                continue;
            }
            
            pot=1;
            
            for(int i=1;;i++){
                if(x>i*pot*N) x-=i*pot*N;
                else{
                    pos=(x-1)/i;
                    x=(x-1)%i;
                    
                    for(int j=i-1;;j--)
                        if(j==x){
                            printf("%s\n",L[pos%N]);
                            break;
                        }else pos/=N;
                    
                    break;
                }
                
                pot*=N;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
