#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int lo,hi,mi;
int a[50],b[50];
int memo[50][201];

int solve(int pos, int x){
    if(pos == -1) return x == 0? 0 : -2;
    
    int &ret = memo[pos][x];
    
    if(ret == -1){
        ret = -2;
        
        for(int i = 0;i <= x && i * a[pos] <= mi;++i){
            int j = (mi - i * a[pos]) / b[pos];
            int aux = solve(pos - 1,x - i);
            if(aux != -2 && (ret == -2 || aux + j >= ret)) ret = aux + j;
        }
    }
    
    return ret;
}

int main(){
    int T,N,X,Y;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d %d",&N,&X,&Y);
        
        for(int i = 0;i < N;++i)
            scanf("%d %d",&a[i],&b[i]);
        
        lo = 0,hi = 400000;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            memset(memo,-1,sizeof memo);
            
            if(solve(N - 1,X) >= Y) hi = mi;
            else lo = mi + 1;
        }
        
        printf("Case %d: %d\n",tc,lo);
    }
    
    return 0;
}
