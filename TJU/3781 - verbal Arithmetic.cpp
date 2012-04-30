#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

char s[13][10],c[10];
int N,m,val[256],cont[256],ans;
int mx[(1 << 10)][10],mn[(1 << 10)][10];

int get_min(int mask, int d){
    if(mask == (1 << m) - 1) return 0;
    
    int &ret = mn[mask][d];
    
    if(ret == -1){
        ret = INT_MAX;
        
        if(m - __builtin_popcount(mask) < 10 - d) ret = get_min(mask,d + 1);
        
        for(int x = 0;x < m;++x)
            if((mask & (1 << x)) == 0)
                ret = min(ret,get_min(mask ^ (1 << x),d + 1) + cont[ c[x] ] * d);
    }
    
    return ret;
}

int get_max(int mask, int d){
    if(mask == (1 << m) - 1) return 0;
    
    int &ret = mx[mask][d];
    
    if(ret == -1){
        ret = INT_MIN;
        
        if(m - __builtin_popcount(mask) < 10 - d) ret = get_max(mask,d + 1);
        
        for(int x = 0;x < m;++x)
            if((mask & (1 << x)) == 0)
                ret = max(ret,get_max(mask ^ (1 << x),d + 1) + cont[ c[x] ] * d);
    }
    
    return ret;
}

void solve(int d, int mask, int sum){
    if(sum + get_min(mask,d) > 0 || sum + get_max(mask,d) < 0) return;
    if(m - __builtin_popcount(mask) > 10 - d) return;
    
    if(mask == (1 << m) - 1){
        if(sum == 0) ++ans;
        return;
    }
    
    solve(d + 1,mask,sum);
    
    for(int i = 0;i < m;++i){
        if((mask & (1 << i)) == 0){
            val[ c[i] ] = d;
            solve(d + 1,mask | (1 << i),sum + cont[ c[i] ] * d);
        }
    }
}

int main(){
    bool used[256],first[256];
    
    while(true){
        scanf("%d",&N);
        
        if(N == 0) break;
        
        memset(used,false,sizeof used);
        memset(first,false,sizeof first);
        memset(cont,0,sizeof cont);
        
        for(int i = 0;i < N;++i){
            scanf("%s",s[i]);
            int L = strlen(s[i]);
            
            if(L > 1) first[ s[i][0] ] = true;
            
            for(int j = L - 1,pow10 = 1;j >= 0;--j,pow10 *= 10){
                used[ s[i][j] ] = true;
                cont[ s[i][j] ] += (i == N - 1? -pow10 : pow10);
            }
        }
        
        m = 0;
        
        for(int i = 'A';i <= 'Z';++i)
            if(used[i]) c[m++] = i;
        
        memset(mn,-1,sizeof mn);
        memset(mx,-1,sizeof mx);
        
        ans = 0;
        
        solve(1,0,0);
        
        for(int i = 0;i < m;++i){
            if(!first[ c[i] ]){
                val[ c[i] ] = 0;
                solve(1,(1 << i),0);
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
