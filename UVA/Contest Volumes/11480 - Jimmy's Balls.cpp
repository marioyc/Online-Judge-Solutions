#include <cstdio>

using namespace std;

long long f[1000011];

int main(){
    for(int i = 6;i <= 1000010;++i){
        f[i] = (long long)(i / 3 - 1) * (i / 3) / 2;
        if(i / 2 - 1 >= i / 3 + 1)
            f[i] += (long long)(i - 1) * (i / 2 - 1 - i / 3) - (long long)(i / 2 - 1) * (i / 2) + (long long)(i / 3) * (i / 3 + 1);
    }
    
    int tc = 1,N;
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        printf("Case %d: %lld\n",tc++,f[N]);
    }
    
    return 0;
}
