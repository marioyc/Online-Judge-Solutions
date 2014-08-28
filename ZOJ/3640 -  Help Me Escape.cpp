#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n,c[100],t[100];
double memo[10002];

double solve(int curf){
    double &ret = memo[curf];
    
    if(!(ret == ret)){
        ret = 0;
        
        for(int i = 0;i < n;++i){
            if(curf > c[i]) ret += t[i];
            else ret += 1 + solve(min(10001,curf + c[i]));
        }
        
        ret /= n;
    }    
    
    return ret;
}

int main(){
    int f;
    
    while(scanf("%d %d",&n,&f) == 2){
        for(int i = 0;i < n;++i){
            scanf("%d",&c[i]);
            t[i] = floor((1 + sqrt(5)) / 2 * c[i] * c[i]);
        }
        
        memset(memo,-1,sizeof memo);
        printf("%.3f\n",solve(f));
    }
    
    return 0;
}
