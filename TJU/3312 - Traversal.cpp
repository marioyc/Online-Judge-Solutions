#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 9901;
int N,T[100001];

int query(int idx){
    int ret = 0;
    
    while(idx > 0){
        ret += T[idx];
        if(ret >= MOD) ret -= MOD;
        idx -= idx & -idx;
    }
    
    return ret;
}

void update(int idx, int val){
    while(idx <= N){
        T[idx] += val;
        if(T[idx] >= MOD) T[idx] -= MOD;
        idx += idx & -idx;
    }
}

int main(){
    int H,h[100000],h2[100000];
    int lo,hi,mi,a,b;
    
    while(scanf("%d %d",&N,&H) == 2){
        for(int i = 0;i < N;++i){
            scanf("%d",&h[i]);
            h2[i] = h[i];
        }
        
        memset(T,0,sizeof(T));
        sort(h2,h2 + N);
        
        int ans = 0,aux;
        
        for(int i = N-1;i >= 0;--i){
            lo = 0; hi = N-1;
            
            while(lo != hi){
                mi = (lo + hi) / 2;
                
                if(h2[mi] < h[i] - H) lo = mi + 1;
                else hi = mi;
            }
            
            a = lo;
            
            lo = 0; hi = N-1;
            
            while(lo != hi){
                mi = (lo + hi + 1) / 2;
                
                if(h2[mi] > h[i] + H) hi = mi - 1;
                else lo = mi;
            }
            
            b = lo;
            
            aux = query(b + 1) - query(a);
            if(aux < 0) aux += MOD;
            ans += aux;
            if(ans >= MOD) ans -= MOD;
            
            lo = 0; hi = N-1;
            
            while(lo != hi){
                mi = (lo + hi) / 2;
                
                if(h2[mi] < h[i]) lo = mi + 1;
                else hi = mi;
            }
            
            update(lo + 1,aux + 1);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
