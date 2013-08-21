#include <cstdio>
#include <algorithm>

using namespace std;

long long f(long long r, long long c, long long T){
    long long ret = 0;
    long long mn = min(r,c),mx = max(r,c);
    
    if(T >= mn) ret += (mn - 1) * mn / 2;
    else{
        ret += T * (T + 1) / 2;
        return ret;
    }
    
    if(T > mx) ret += mn * (mx - mn + 1);
    else{
        ret += mn * (T - mn + 1);
        return ret;
    }
    
    if(T >= r + c) ret += (mn - 1) * mn / 2;
    else ret += (r + c) * (T - mx) - (T * (T + 1) / 2 - mx * (mx + 1) / 2);
    
    return ret;
}

int main(){
    int n;
    long long x,y,c;
    
    scanf("%d %I64d %I64d %I64d",&n,&x,&y,&c);
    
    long long lo = 1,hi = 2000000000LL,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        long long aux = f(x,y,mi) + f(n + 1 - x,y,mi) + f(x,n + 1 - y,mi) + f(n + 1 - x,n + 1 - y,mi);
        aux -= min(x,mi) + min(n + 1 - x,mi) + min(y,mi) + min(n + 1 - y,mi);
        ++aux;
        
        if(aux < c) lo = mi + 1;
        else hi = mi;
    }
    
    printf("%I64d\n",lo - 1);
    
    return 0;
}
