#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[51][51][2][2],choice[51][51][2][2];

int solve(int P, int Q, int last, int done){
    if(P == 0 && Q == 0) return 0;
    
    int &ret = memo[P][Q][last][done];
    
    if(ret == -1){
        ret = 0;
        
        int aux0 = -1,aux1 = -1;
        
        if(Q > 0) aux0 = (last == 1 && !done? 1 : 0) + solve(P,Q - 1,0,0);
        if(P > 0) aux1 = (last == 0? 1 : 0) + solve(P - 1,Q,1,last == 0);
        
        choice[P][Q][last][done] = (aux0 >= aux1? 0 : 1);
        
        ret = max(aux0,aux1);
    }
    
    return ret;
}

int main(){
    memset(memo,-1,sizeof memo);
    
    int T,P,Q;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&P,&Q);
        
        int aux = solve(P,Q,1,1);
        int last = 1,done = 1;
        long long ans = 0;
        
        while(P > 0 || Q > 0){
            int b = choice[P][Q][last][done];
            
            if(b == 1){
                ans |= (1LL << (P + Q - 1));
                
                if(last == 0) done = 1;
                else done = 0;
                
                last = 1;
                --P;
            }else{
                last = 0;
                done = 0;
                --Q;
            }
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
