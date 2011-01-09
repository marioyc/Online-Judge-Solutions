#include <cstdio>

using namespace std;

int main(){
    int R[16],G[16],B[16];
    
    for(int i = 0;i<16;++i)
        scanf("%d %d %d",&R[i],&G[i],&B[i]);
    
    int r,g,b;
    
    while(true){
        scanf("%d %d %d",&r,&g,&b);
        if(r==-1 && g==-1 && b==-1) break;
        
        int ans = -1,D = 0;
        
        for(int i = 0;i<16;++i){
            int aux = (R[i]-r)*(R[i]-r)+(G[i]-g)*(G[i]-g)+(B[i]-b)*(B[i]-b);
            
            if(ans==-1 || aux<D){
                ans = i;
                D = aux;
            }
        }
        
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,R[ans],G[ans],B[ans]);
    }
    
    return 0;
}
