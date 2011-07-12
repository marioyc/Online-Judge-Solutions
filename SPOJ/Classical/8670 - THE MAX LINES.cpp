#include <cstdio>

using namespace std;

int main(){
    int T,r;
    long long r2;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&r);
        
        r2 = (long long)r * r;
        r2 <<= 2;
        printf("Case %d: %lld",tc,r2);
        puts(".25");
    }
    
    return 0;
}
