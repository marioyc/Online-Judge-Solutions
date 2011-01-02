#include <cstdio>

using namespace std;

int zeroes(int N){
    int ret = 0;
    
    while(N!=0){
        ret += N/5;
        N /= 5;
    }
    
    return ret;
}

int main(){
    int Q;
    scanf("%d",&Q);
    
    int lo = 1,hi = 400000015,mi;
    
    while(lo<hi){
        mi = (lo+hi)/2;
        
        if(zeroes(mi)<Q) lo = mi+1;
        else hi = mi;
    }
    
    if(zeroes(hi)==Q) printf("%d\n",hi);
    else puts("No solution");
    
    return 0;
}
