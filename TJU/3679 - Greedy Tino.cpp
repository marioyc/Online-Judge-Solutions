#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100],memo[100][4001];

int solve(int pos, int diff){
    if(pos == -1) return diff != 2000? -2 : 0;
    
    int &ret = memo[pos][diff];
    
    if(ret == -1){
        ret = -2;
        
        int aux = solve(pos - 1,diff - a[pos]);
        if(aux != -2 && a[pos] + aux > ret) ret = a[pos] + aux;
        
        aux = solve(pos - 1,diff + a[pos]);
        if(aux != -2 && a[pos] + aux > ret) ret = a[pos] + aux;
        
        aux = solve(pos - 1,diff);
        if(aux != -2 && aux > ret) ret = aux;
    }
    
    return ret;
}

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        bool zero = false;
        
        for(int i = 0;i < N;++i){
            scanf("%d",&a[i]);
            if(a[i] == 0) zero = true;
        }
        
        memset(memo,-1,sizeof memo);
        
        int ret = solve(N - 1,2000);
        
        printf("Case %d: %d\n",tc,(ret == 0 && !zero)? -1 : ret / 2);
    }
    
    return 0;
}
