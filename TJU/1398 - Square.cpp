#include <cstdio>
#include <cstring>

using namespace std;

int N,l[20],L;
bool done[(1 << 20)],memo[(1 << 20)];

bool solve(int mask, int have){
    if(mask == 0) return true;
    
    bool &ret = memo[mask];
    
    if(!done[mask]){
        if(have == 0) have = L;
        
        ret = false;
        done[mask] = true;
        
        for(int i = 0;i < N;++i)
            if((mask & (1 << i)) && l[i] <= have && solve(mask ^ (1 << i),have - l[i]))
                ret = true;
    }
    
    return ret;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        L = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%d",&l[i]);
            L += l[i];
        } 
        
        if(L % 4 != 0) puts("no");
        else{
            L /= 4;
            memset(done,false,sizeof done);
            puts(solve((1 << N) - 2,L - l[0])? "yes" : "no");
        }
    }
    
    return 0;
}
