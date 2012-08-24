#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int bit[26],cont[26],less[25000],eq[25000];
int T[100000],P[25000],f[25000];

void update(int idx, int val){
    for(int x = idx;x <= 25;x += x & -x)
        bit[x] += val;
}

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

int main(){
    int N,K,S;
    
    scanf("%d %d %d",&N,&K,&S);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&T[i]);
    
    for(int i = 0;i < K;++i){
        scanf("%d",&P[i]);
        
        eq[i] = cont[ P[i] ];
        less[i] = query(P[i] - 1);
        
        update(P[i],1);
        ++cont[ P[i] ];
    }
    
    memset(bit,0,sizeof bit);
    memset(cont,0,sizeof cont);
    
    f[0] = 0;
    
    for(int i = 1,k = 0;i < K;++i){
        while(k > 0 && (query(P[i] - 1) != less[k] || cont[ P[i] ] != eq[k])){
            for(int x = i - 1 - f[k - 1];x >= i - k;--x){
                update(P[x],-1);
                --cont[ P[x] ];
            }
            
            k = f[k - 1];
        }
        
        update(P[i],1);
        ++cont[ P[i] ];
        f[i] = ++k;
    }
    
    memset(bit,0,sizeof bit);
    memset(cont,0,sizeof cont);
    int sol[N],sz = 0;
    
    for(int i = 0,k = 0;i < N;++i){
        while(k > 0 && (query(T[i] - 1) != less[k] || cont[ T[i] ] != eq[k])){
            for(int x = i - 1 - f[k - 1];x >= i - k;--x){
                update(T[x],-1);
                --cont[ T[x] ];
            }
            
            k = f[k - 1];
        }
        
        update(T[i],1);
        ++cont[ T[i] ];
        ++k;
        
        if(k == K){
            sol[sz++] = i - K + 1;
            
            for(int x = i - f[k - 1];x >= i + 1 - k;--x){
                update(T[x],-1);
                --cont[ T[x] ];
            }
            
            k = f[k - 1];
        }
    }
    
    printf("%d\n",sz);
    
    for(int i = 0;i < sz;++i)
        printf("%d\n",sol[i] + 1);
    
    return 0;
}
