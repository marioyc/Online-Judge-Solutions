#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N,monsters[20],damage[(1<<20)],memo[(1<<20)];

int solve(int mask){
    int &ret = memo[mask];
    
    if(ret==-1){
        for(int i = 0;i<N;++i){
            bool valid = false;
            
            for(int j = 0;j<3;++j)
                if((mask & (1<<((i+j)%N)))==0)
                    valid = true;
            
            if(!valid) continue;
            
            int mask2 = mask,x = 0;
            
            for(int j = 0;j<3;++j)
                mask2 |= (1<<((i+j)%N));
            
            int aux = solve(mask2)+damage[mask2];
            if(ret==-1 || aux<ret) ret = aux;
        }
        
        if(ret==-1) ret = 0;
    }
    
    return ret;
}

int main(){
    scanf("%d",&N);
    for(int i = 0;i<N;++i)
        scanf("%d",&monsters[i]);
    
    for(int mask = 0;mask<(1<<N);++mask){
        damage[mask] = 0;
        
        for(int i = 0;i<N;++i)
            if((mask & (1<<i))==0)
                damage[mask] += monsters[i];
    }
    
    memset(memo,-1,sizeof(memo));
    printf("%d\n",solve(0));
    
    return 0;
}
