#include <cstdio>

using namespace std;

int exp(int n){
    int ret = 0;
    
    while(n){
        ret += (n >> 1);
        n >>= 1;
    }
    
    return ret;
}

int main(){
    int n,k;
    
    while(~scanf("%d %d",&n,&k)){
        if(exp(n) - exp(k) - exp(n - k) > 0) puts("0");
        else puts("1");
    }
    
    return 0;
}
