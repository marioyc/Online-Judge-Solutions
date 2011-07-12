#include <cstdio>

using namespace std;

int main(){
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    int x = 1,ans = 0;
    
    while(x < K && x < N){
        x <<= 1;
        ++ans;
    }
    
    if(x < N) ans += (N - x + K - 1) / K;
    
    printf("%d\n",ans);
    
    return 0;
}
