#include <cstdio>
#include <algorithm>

using namespace std;

struct num{
    int id,val,val2;
    
    num(){}
}seq[1000];

bool comp1(num a, num b){
    return a.val<b.val;
}

bool comp2(num a, num b){
    return a.id<b.id;
}

int main(){
    int T,N,s[1000],e[1000],M;
    
    scanf("%d",&T);
    
    for(int i = 1;i<=1000;++i) seq[i].id = i;
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i<N;++i)
            scanf("%d",&seq[i].val);
        
        sort(seq,seq+N,comp1);
        
        for(int i = 0;i<N;++i)
            seq[i].val2 = i;
        
        sort(seq,seq+N,comp2);
        
        M = 0;
        
        for(int i = 0;i<N;++i){
            bool found = false;
            
            for(int j = 0;j<M;++j){
                if(seq[i].val2== s[j]-1){
                    found = true;
                    --s[j];
                    break;
                }
                
                if(seq[i].val2== e[j]+1){
                    found = true;
                    ++e[j];
                    break;
                }
            }
            
            if(!found){
                s[M] = e[M] = seq[i].val2;
                ++M;
            }
        }
        
        printf("%d\n",M);
    }
    
    return 0;
}
