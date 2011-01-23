#include <cstdio>

using namespace std;

int main(){
    int R,C;
    int ans,cont,move[15],moveAns[15],prev,cur,need,S;
    char M[15][16];
    bool solved;
    
    while(true){
        scanf("%d %d",&C,&R);
        if(R==0) break;
        
        for(int i = 0;i<R;++i)
            scanf("%s",M[i]);
        
        S = (1<<C)-1;
        ans = -1;
        
        for(int mask = S-1;mask>=0;--mask){
            cont = __builtin_popcount(mask);
            
            need = (mask ^ (mask>>1) ^ (mask<<1)) & S;
            for(int i = 0;i<C;++i) if(M[0][i]=='0') need ^= (1<<i);
            
            move[0] = prev = mask;
            
            for(int r = 1;r<R;++r){
                move[r] = cur = need;
                cont += __builtin_popcount(cur);
                
                need = (cur ^ (cur>>1) ^ (cur<<1) ^ prev) & S;
                for(int i = 0;i<C;++i) if(M[r][i]=='0') need ^= (1<<i);
                
                prev = cur;
            }
            
            if(need==0 && (ans==-1 || cont<ans)){
                ans = cont;
                for(int i = 0;i<R;++i) moveAns[i] = move[i];
            }
        }
        
        if(ans==-1) puts("-1");
        else{
            printf("%d\n",ans);
            
            for(int i = 0;i<R;++i)
                for(int j = 0;j<C;++j)
                    if(moveAns[i] & (1<<j))
                        printf("%d %d\n",j+1,i+1);
        }
    }
    
    return 0;
}
