#include <cstdio>

using namespace std;

int main(){
    int N;
    
    while(scanf("%d",&N) == 1){
        int lo = 1,hi = 100000,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            if((long long)mi * (mi + 1) / 2 < N) lo = mi + 1;
            else hi = mi;
        }
        
        if((long long)lo * (lo + 1) / 2 == N) printf("%d\n",lo);
        else puts("bad");
    }
    
    return 0;
}
