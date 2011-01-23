#include <cstdio>

using namespace std;

int main(){
    int R,C;
    int ans,cont,prev,cur,state,S;
    char M[16][17];
    
    while(true){
        scanf("%d %d",&R,&C);
        if(R==0) break;
        
        ans = -1;
        
        for(int i = 0;i<R;++i)
            scanf("%s",M[i]);
        
        S = (1<<C)-1;
        
        for(int mask = S;mask>=0;--mask){
            cont = __builtin_popcount(mask);
            prev = mask,state = (mask ^ (mask>>1) ^ (mask<<1)) & S;
            
            for(int i = 0;i<C;++i) if(M[0][i]=='X') state ^= (1<<i);
            
            for(int r = 1;r<R;++r){
                cur = state;
                cont += __builtin_popcount(state);
                
                state = (state ^ (state>>1) ^ (state<<1) ^ prev) & S;
                prev = cur;
                
                for(int i = 0;i<C;++i) if(M[r][i]=='X') state ^= (1<<i);
            }
            
            if(state==0 && (ans==-1 || cont<ans)) ans = cont;
        }
        
        if(ans==-1) puts("Damaged billboard.");
        else printf("You have to tap %d tiles.\n",ans);
    }
    
    return 0;
}
